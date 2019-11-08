#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"exptree.h"

#define INTTYPE  0
#define STRTYPE  1
#define BOOLTYPE 2

#define reg_index int
int regFlag[20];
int labelCount = 0;
int label1,label2,label3,loopFlg=0;
struct Gsymbol* symHead=NULL;
extern int phase;
int freeAdd = 4096;					//To store the available free address
int rel_binding = 0;					//To store the binding of parameteres and local variables
int flabel = 0;						//To store function lables
int savedReg = -1;					//To store the registers to be saved during function call
int ssa_reg = 2;
extern struct Lsymbol* Ltable;
extern int line;
FILE* target_file;
struct Typetable* Typetable = NULL;
struct ClassTable* Classtable = NULL;
extern struct ClassTable* CurrentClass;
struct StringNames* Stringtable = NULL;			//To store the strings which need to be allocated space

struct node* makeNode(int nodetype,int val,char* name,struct node* l,struct node* r,struct node* t,struct Paramstruct* paramList)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->class = NULL;
    if(nodetype == NUM_NODE)   			//An number node
    {
	newNode->nodetype = 0;
	newNode->val = val;
	newNode->type = TLookup("int");
    }
    else if(nodetype == VAR_NODE)			//A variable node
    {
	newNode->nodetype = 1;
	newNode->varname = name;
	if(phase == 1 || phase > 2)
	{
	    struct Lsymbol* Ltemp = Ltable;
	    struct Gsymbol* Gtemp = NULL;
	    while(Ltemp != NULL && strcmp(name,Ltemp->name) != 0)
	    {
		Ltemp = Ltemp->next;
	    }
	    if(Ltemp == NULL)
	    {
	        Gtemp = symHead;
	        while(Gtemp != NULL && strcmp(name,Gtemp->name) != 0)
	        {
	            Gtemp = Gtemp->next;
	        }
	    }
 	    if(Gtemp == NULL && Ltemp == NULL)
	    {
	        printf("LINE %d : Undeclared variable %s\n",line,name);
	        exit(0);
	    }
	    else
	    {
		if(Gtemp != NULL)
		{
		    if(Gtemp->size != 1 && l == NULL && (Gtemp->type == TLookup("int") || Gtemp->type == TLookup("str")))
		    {
		        printf("LINE %d : %s is an array\n",line,name);
		        exit(0);
		    }
		    else if(l != NULL && Gtemp->size == 1 && (Gtemp->type == TLookup("int") || Gtemp->type == TLookup("str")))
		    {
		        printf("LINE %d : %s is not an array\n",line,name);
		        exit(0);
		    }
	            newNode->Gentry = Gtemp;
		    newNode->Lentry = NULL;
		    newNode->type = Gtemp->type;
		    newNode->class = Gtemp->class;
		}
	  	else
		{
		    newNode->Gentry = NULL;
		    newNode->Lentry = Ltemp;
		    newNode->type = Ltemp->type;
		}
	    }
	}
    }
    else if(nodetype == OP_NODE)			//An operator node
    {
	newNode->nodetype = 2;
        newNode->varname = name;
	if(r->nodetype == ALLOC_NODE || (r->nodetype == NULL_NODE && (strcmp(name,"!=") == 0 || *name == '=')))
	{
	    if(l->type == TLookup("int") || l->type == TLookup("str") || l->type == TLookup("bool"))
	    {
		printf("LINE %d : %s is not a user-defined type\n",line,l->varname);
		exit(0);
	    }
	    if(strcmp(name,"!=") == 0 || strcmp(name,"==") == 0)
		newNode->type = TLookup("bool");
	    else if(*name == '=')
		newNode->type = TLookup("int");
	}
	else if(l->type != NULL && l->type == r->type && (l->type != TLookup("bool")))
	{
	    if(*name == '+' |*name == '-' |*name == '*' |*name == '/' |*name == '%' |*name == '=')
		newNode->type = TLookup("int");
	    else
	    	newNode->type = TLookup("bool");
	}
	else if(l->class != NULL && r->class != NULL && strcmp(name,"=") == 0)
	{
	    int flg = 0;
	    struct ClassTable* LClass = l->class;
	    if(l->left != NULL)
	    {
		LClass = Class_FLookup(l->class,l->left->varname)->Ctype;
	    }
	    struct ClassTable* RClass = r->class;
	    while(RClass != NULL)
	    {
		if(LClass == RClass)
		{
		    flg = 1;
		    break;
		}
		RClass = RClass->parentClass;
	    }
	    if(flg == 1)
	    {
		newNode->type = TLookup("int");
	    }
	    else
	    {
		printf("LINE %d : Type mismatch error\n",line);
                exit(0);
	    }
	}
	else
	{
	    if(!l->type)
		printf("L FAULT\n");
	    else if(!r->type)
		printf("R FAULT\n");
	    printf("LINE %d : Type mismatch error\n",line);
	    printf("L->type:%s R->type:%s\n",l->type->name,r->type->name);
            exit(0);    
	}	
    }
    else if(nodetype == WRITE_NODE)			//A "write" node
    {
	newNode->nodetype = 3;
    }
    else if(nodetype == READ_NODE)			//A "read" node
    {
	newNode->nodetype = 4;
    }
    else if(nodetype == EMPTY_NODE)			//An empty connector node
    {
	newNode->varname = name;
	newNode->nodetype = 5;
	newNode->paramList = paramList;
    }
    else if(nodetype == IF_NODE)			//An if-then node
    {
	newNode->nodetype = 6;
    }
    else if(nodetype == IFELSE_NODE)			//An if-then-else node
    {
	newNode->nodetype = 7;
	newNode->third = t;
    }
    else if(nodetype == WHILE_NODE)			//A while-do loop node
    {
	newNode->nodetype = 8;
    }
    else if(nodetype == BRK_NODE)			//A break statement node
    {
	newNode->nodetype = 9;
    }
    else if(nodetype == CON_NODE)			//A continue statement node
    {
	newNode->nodetype = 10;
    }
    else if(nodetype == DOWHL_NODE)			//A do-while node
    {
	newNode->nodetype = 11;
    }
    else if(nodetype == STR_NODE)			//A string node
    {
	newNode->nodetype = 12;
	newNode->type = TLookup("str");
	name++;
	char* temp = name;
	while(*temp != '"')
	    temp++;
	*temp = '\0';
	newNode->varname= name;
	Stringtable = InstallString(Stringtable,name);
    }
    else if(nodetype == FUNC_NODE)			//A node which calls a function
    {
	newNode->nodetype = FUNC_NODE;
	newNode->varname = name;
	struct Gsymbol* Gtemp = symHead;
	while(Gtemp != NULL && strcmp(name,Gtemp->name) != 0)
	    Gtemp = Gtemp->next;

        if(Gtemp == NULL)
        {
            printf("Undeclared function %s()\n",name);
            exit(1);
        }
	newNode->Gentry = Gtemp;
	newNode->type = Gtemp->type;
    }
    else if(nodetype == RET_NODE)			//A return type node
    {
	newNode->nodetype = RET_NODE;
    }
    else if(nodetype == FIELD_NODE)
    {
	newNode->nodetype = FIELD_NODE;
    }
    else if(nodetype == INIT_NODE)
    {
        newNode->nodetype = INIT_NODE;
	newNode->type = TLookup("int");
    }
    else if(nodetype == ALLOC_NODE)
    {
        newNode->nodetype = ALLOC_NODE;
    }
    else if(nodetype == FREE_NODE)
    {
        newNode->nodetype = FREE_NODE;
	if(l->type == TLookup("int") || l->type == TLookup("str") || l->type == TLookup("bool"))
	{
	    printf("LINE %d : %s is not a user-defined type\n",line,l->varname);
            exit(0);
	}
    }
    else if(nodetype == NULL_NODE)
    {
	newNode->nodetype = NULL_NODE;
    }
    else if(nodetype == NEW_NODE)
    {
        newNode->nodetype = NEW_NODE;
	newNode->class = CLookup(l->varname);
	if(newNode->class == NULL)
	{
	    printf("LINE %d : %s is not a class type\n",line,l->varname);
	    exit(0);
	}
    }
    else if(nodetype == DELETE_NODE)
    {
        newNode->nodetype = DELETE_NODE;
	if(l->class == NULL)
	{
	    printf("LINE %d : %s is not a class type\n",line,l->varname);
            exit(0);
	}
    }
    else if(nodetype == SELF_NODE)
    {
	newNode->nodetype = SELF_NODE;
	newNode->varname = name;
	if(CurrentClass != NULL)
        {   
            newNode->class = CurrentClass;
	    newNode->type = NULL;
        }
        else
        {   
            printf("LINE %d:Invalid use of self\n",line);
            exit(0);
        }
	struct Lsymbol* Ltemp = Ltable;
	while((Ltemp != NULL) && strcmp(Ltemp->name,"self") != 0)
	   Ltemp = Ltemp->next;
	if(Ltemp == NULL)
	{
	    printf("LINE %d : Undeclared type self\n",line);
	    exit(0);
	}
        newNode->Lentry = Ltemp;
    }
    newNode->left = l;
    newNode->right = r;
    newNode->third = t;
    return newNode;
}

void generateInitCode()
{
    target_file = fopen("out.ll","w");
    fprintf(target_file,"target datalayout = \"e-m:o-i64:64-f80:128-n8:16:32:64-S128\"\ntarget triple = \"x86_64-apple-macosx10.14.0\"\n\n");
    return;
}

void generateTypeDef(char* name,struct Fieldlist* Fields)
{
    fprintf(target_file,"%%struct.%s = type {",name);
    while(Fields)
    {
	if(Fields->type == TLookup("int"))
	{
	    fprintf(target_file," i32");
	}
	else
	{
	    fprintf(target_file," %%struct.%s*",Fields->type->name);
	}

	if(Fields->next)
	    fprintf(target_file,",");
	Fields = Fields->next;
    }
    fprintf(target_file,"}\n\n");
}

void generateGlobalVariableCode()
{
    struct Gsymbol* temp = symHead;
    fprintf(target_file,"@.str = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n");   		//read interger
    fprintf(target_file,"@.str.1 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n");	//write integer

    fprintf(target_file,"@.str.2 = private unnamed_addr constant [3 x i8] c\"%%s\\00\", align 1\n");		//read string
    fprintf(target_file,"@.str.3 = private unnamed_addr constant [4 x i8] c\"%%s\\0A\\00\", align 1\n");	//write string

    struct StringNames* STemp = Stringtable;
    while(STemp)
    {
	char *name = STemp->name;
fprintf(target_file,"@.str.%d = private unnamed_addr constant [%d x i8] c\"%s\\00\", align 1\n",STemp->index,str_len(name)+1,name);
	STemp = STemp->next;
    }

    while(temp)
    {
	if(temp->type == TLookup("int"))
	{
            if(temp->size == 1)
	    {
                fprintf(target_file,"@%s = common global i32 0,align 4\n",temp->name);
	    }
            else if(temp->size != 0)
            { 
                if(temp->rowSize != 0)
                {
                    int rows = temp->rowSize;
                    int cols = temp->size/temp->rowSize;
                    fprintf(target_file,"@%s = common global [%d x [%d x i32]] zeroinitializer, ",temp->name,rows,cols);
                    if(temp->size < 4)
                        fprintf(target_file,"align 4\n");
                    else
                        fprintf(target_file,"align 16\n");
                }
                else
                {
                    int size = temp->size;
                    fprintf(target_file,"@%s = common global [%d x i32] zeroinitializer, ",temp->name,size);
                    if(temp->size < 4)
                        fprintf(target_file,"align 4\n");
                    else
                        fprintf(target_file,"align 16\n");
                }
            }
	}
	else if(temp->type == TLookup("str"))
	{
	    if(temp->size == 1)
		fprintf(target_file,"@%s = common global [32 x i8] zeroinitializer, align 16\n",temp->name);
	}
	else if(temp->size != 0)
	    fprintf(target_file,"@%s = common global %%struct.%s* null,align 8\n",temp->name,temp->type->name);
        temp = temp->next;
    }
    fprintf(target_file,"\n");
    fprintf(target_file,"declare i32 @scanf(i8*, ...)\n\ndeclare i32 @printf(i8*, ...)\n\ndeclare i8* @malloc(i64)\n\n");
    fprintf(target_file,"declare i32 @free(...)\n\n");
    fprintf(target_file,"declare void @llvm.memcpy.p0i8.p0i8.i32(i8*, i8*, i32, i1)\n");
    return;
}

void generateFuncCode(struct node* tree,char* name)
{
    struct Gsymbol* Gtemp = symHead;
    while(Gtemp != NULL && strcmp(Gtemp->name,name) != 0)
         Gtemp = Gtemp->next;

    ssa_reg = 0;
    fprintf(target_file,"define ");
    if(Gtemp->type == TLookup("int"))
    {
	fprintf(target_file,"i32 ");
    }
    else if(Gtemp->type == TLookup("str"))
    {
	fprintf(target_file,"[32 x i8]* ");
    }
    else
    {
	fprintf(target_file,"%%struct.%s* ",Gtemp->type->name);
    }

    fprintf(target_file,"@%s(",Gtemp->name);
    struct Paramstruct* temp = Gtemp->paramList;
    while(temp->next)
    {
	ssa_reg++;
 	if(temp->type == TLookup("int"))
		fprintf(target_file,"i32, ");
	else if(temp->type == TLookup("str"))
		fprintf(target_file,"[32 x i8]*, ");
	else
		fprintf(target_file,"%%struct.%s*, ",temp->type->name);
	temp = temp->next;
    }
    if(temp)
    {
        if(temp->type == TLookup("int"))
                fprintf(target_file,"i32");
        else if(temp->type == TLookup("str"))
                fprintf(target_file,"[32 x i8]*, ");
        else
                fprintf(target_file,"%%struct.%s*",temp->type->name);
    	ssa_reg++;
    }
    fprintf(target_file,") {\n entry:\n");
    int params = ssa_reg;

    struct Lsymbol* L_temp = Ltable;
    while(L_temp)
    {
	if(L_temp->type == TLookup("int"))
	{
		fprintf(target_file,"  %%%d = alloca i32, align 4\n",ssa_reg);
	}
	else if(L_temp->type == TLookup("str"))
	{
		fprintf(target_file,"  %%%d = alloca [32 x i8], align 16\n",ssa_reg);
	}
	else
	{
		fprintf(target_file,"  %%%d = alloca %%struct.%s*, align 8\n",ssa_reg,L_temp->type->name);
	}
	L_temp->binding = ssa_reg++;
	L_temp = L_temp->next;
    }
    int param_reg = 0,param_count = params;
    L_temp = Ltable;
    while(params > 0 && L_temp)				//to store the function parameters in local registers
    {
	if(L_temp->type == TLookup("int"))
	    fprintf(target_file,"  store i32 %%%d, i32* %%%d, align 4\n",param_reg,param_count+param_reg);
	else if(L_temp->type == TLookup("str"))
	{
 	   int p = param_reg + param_count,q = param_reg; 
	   int src = getReg();
           fprintf(target_file,"  %%%d = getelementptr inbounds [32 x i8], [32 x i8]* ",src);
	   fprintf(target_file,"  %%%d, i32 0, i32 0\n",q);
	   int dest = getReg();
	   fprintf(target_file,"  %%%d = getelementptr inbounds [32 x i8], [32 x i8]* ",dest);
           fprintf(target_file,"  %%%d, i32 0, i32 0\n",p);
	   fprintf(target_file,"  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %%%d,i8* %%%d,i32 32,i1 false)\n",dest,src);
	}
	else
	{
	    fprintf(target_file,"  store %%struct.%s* %%%d, %%struct.%s** %%%d, align 8\n",L_temp->type->name,param_reg,L_temp->type->name,param_count+param_reg);
	}
	param_reg++;
	params--;
	L_temp = L_temp->next;
    }
    int p = codegen(tree,target_file);
    fprintf(target_file,"}\n\n");
    return; 
}

void generateMainCode(struct node* tree)
{
    fprintf(target_file,"define i32 @main() {\n entry:\n  %%0 = alloca i32, align 4\n");

    ssa_reg = 1;
    struct Lsymbol* L_temp = Ltable;
    while(L_temp)
    {
        if(L_temp->type == TLookup("int"))
        {       
                fprintf(target_file,"  %%%d = alloca i32, align 4\n",ssa_reg);
        }
	else if(L_temp->type == TLookup("str"))
	{
                fprintf(target_file,"  %%%d = alloca [32 x i8], align 16\n",ssa_reg);
	}
        else    
        {       
                fprintf(target_file,"  %%%d = alloca %%struct.%s*, align 8\n",ssa_reg,L_temp->type->name);
        }
	L_temp->binding = ssa_reg++;
	L_temp = L_temp->next;
    }    

    fprintf(target_file,"  store i32 0, i32* %%0, align 4\n");

    int p = codegen(tree,target_file);
    fprintf(target_file,"}\n\n");
    return;
}

//stores name as NUM if NUM_NODE else name is NULL
struct Lsymbol* generateArgsCode(struct node* tree)
{
    if(!tree)
    {
	return NULL;
    }
    int p;
    if(tree->type != TLookup("str"))
 	p = codegen(tree,target_file);
    else
	p = tree->Lentry->binding;
    struct Lsymbol* newNode = malloc(sizeof(struct Lsymbol));
    newNode->binding = p;
    if(tree->nodetype == NUM_NODE)
    {
	newNode->name = malloc(3);
	strcpy(newNode->name,"NUM");
    }
    newNode->type = tree->type;
    newNode->next = generateArgsCode(tree->third);
    free(tree->third);
    return newNode;
}

reg_index getReg()
{
    return ssa_reg++;
}

void freeReg()
{
    int i = 19;
    for(i=19;i >= 0;i--)
    {
	if(regFlag[i] == 1)
	{
	    regFlag[i] = 0;
	    return;
	}
    }
    return;
}

int getLabel()
{
    return labelCount++;
}

reg_index codegen(struct node* tree,FILE* target_file)
{
    if(tree->nodetype == DOWHL_NODE)
    {
	loopFlg++;
	label1 = getLabel();
        label2 = getLabel();
	fprintf(target_file,"L%d:\n",label1);
        int p = codegen(tree->left,target_file);
        p = codegen(tree->right,target_file);
	int q = getReg();
	fprintf(target_file,"MOV R%d,1\nEQ R%d,R%d\nJNZ R%d,L%d\n",q,q,p,q,label1);
	freeReg();
	freeReg();
	fprintf(target_file,"L%d:\n",label2);
	loopFlg--;
	return -1;
    }
    if(tree->nodetype == WHILE_NODE)
    {
	loopFlg++;
	label1 = getLabel();
	label2 = getLabel();
	label3 = getLabel();
	fprintf(target_file,"  br label %%L%d\n\n",label1);

	//condition code
	fprintf(target_file," L%d:\n",label1);
	int l1 = label1;
	int l2 = label2;
	int l3 = label3;
	if(tree->left->type != TLookup("bool"))
	{
	    printf("Condition of while loop is not boolean\n");
	    exit(1);
	}
	int p = codegen(tree->left,target_file);
	label1 = l1;
	label2 = l2;
	label3 = l3;
	fprintf(target_file,"  br i1 %%%d, label %%L%d, label %%L%d\n\n",p,label2,label3);

	//body of the loop
 	fprintf(target_file," L%d:\n",label2);	
	p = codegen(tree->right,target_file);
	label1 = l1;
 	label2 = l2;
	label3 = l3;
	fprintf(target_file,"  br label %%L%d\n\n",label1);
	fprintf(target_file," L%d:\n",label3);
	loopFlg--;
	return -1;
    }
    else if(tree->nodetype == IFELSE_NODE)
    {
	int p = codegen(tree->left,target_file);
	int label1 = getLabel();
	int label2 = getLabel();
  	int label3 = getLabel();

	fprintf(target_file,"  br i1 %%%d, label %%L%d, label %%L%d\n",p,label1,label2);
	fprintf(target_file,"\n");

	//if-then part
	fprintf(target_file," L%d:\n",label1);
        p = codegen(tree->right,target_file);
	if(tree->right->nodetype != BRK_NODE)
		fprintf(target_file,"  br label %%L%d\n\n",label3);

	//else part
	fprintf(target_file," L%d:\n",label2);
	p = codegen(tree->third,target_file);
	if(tree->third->nodetype != BRK_NODE)
		fprintf(target_file,"  br label %%L%d\n\n",label3);

	fprintf(target_file," L%d:\n",label3);
        return -1;
    }
    else if(tree->nodetype == IF_NODE)
    {
	int p = codegen(tree->left,target_file);
        int label1 = getLabel();
        int label2 = getLabel();

	fprintf(target_file,"  br i1 %%%d, label %%L%d, label %%L%d\n\n",p,label1,label2);

	//if-then part
	fprintf(target_file," L%d:\n",label1);
        p = codegen(tree->right,target_file);

	if(tree->right->nodetype != BRK_NODE)
		fprintf(target_file,"  br label %%L%d\n",label2);
	fprintf(target_file," L%d:\n",label2);
	return -1;
    }
    else if(tree->nodetype == EMPTY_NODE)
    {
	int p;
	p = codegen(tree->left,target_file);
	p = codegen(tree->right,target_file);
	return -1;
    }
    else if(tree->nodetype == READ_NODE)
    {
	int p,q;
	if(tree->left->nodetype == FIELD_NODE)
	{

                struct Typetable* type = NULL;
		struct ClassTable* class = NULL;
                p = getReg();
                if(tree->left->Lentry == NULL)
                {   
                    type = tree->left->Gentry->type;
		    fprintf(target_file,"  %%%d = load %%struct.%s*, %%struct.%s** @%s, align 8\n",p,type->name,type->name,tree->left->Gentry->name);
                }
                else
                {   
                    q = tree->left->Lentry->binding;
                    type = tree->left->Lentry->type;
		    if(type == NULL)
		    {
			class = tree->left->class;
                        fprintf(target_file,"MOV R%d,[R%d]\n",p,p);
		    }
		    fprintf(target_file,"  %%%d = load %%struct.%s*, %%struct.%s** %%%d, align 8\n",p,type->name,type->name,q);
                }
                struct node* temp = tree->left->left;
                struct Fieldlist* field = NULL;
                int offset = 0;
		
                while(temp != NULL)
                {   
		    q = getReg();
                    offset = 0;
		    if(type != NULL)
                    	field = type->fields;
		    else
			field = class->fields;
                    while(field != NULL && strcmp(temp->varname,field->name) != 0)
                    {      
                        offset++;
                        field = field->next;
                    }
    fprintf(target_file,"  %%%d = getelementptr inbounds %%struct.%s, %%struct.%s* %%%d, i32 0, i32 %d\n",q,type->name,type->name,p,offset);
		    p = q;
                    temp = temp->left;
                    type = field->type;
		    class = field->Ctype;
                }
	}
	//A 2D array
	else if(tree->left->right != NULL)
	{
	    q = codegen(tree->left->left,target_file);
	    if(tree->left->left->nodetype != NUM_NODE)
	    {
		p = getReg();
		fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,q);
		q = p;
	    }
	    p = getReg();
	    fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
            if(tree->left->Gentry->type == TLookup("int"))
            {
                int rows = tree->left->Gentry->rowSize;
                int cols = tree->left->Gentry->size/rows;
                fprintf(target_file,"[%d x [%d x i32]], [%d x [%d x i32]]* @%s, ",rows,cols,rows,cols,tree->left->Gentry->name);
                if(tree->left->left->nodetype != NUM_NODE)
                   fprintf(target_file,"i64 0, i64 %%%d\n",q);
                else
                   fprintf(target_file,"i64 0, i64 %d\n",q);
            }
            int r = p;

            //code for the columns in that row
            q = codegen(tree->left->right,target_file);
            if(tree->left->right->nodetype != NUM_NODE)
            {
                p = getReg();
                fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,q);
		q = p;
            }
	    p = getReg();
            fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
            if(tree->left->Gentry->type == TLookup("int"))
            {
                int rows = tree->left->Gentry->rowSize;
                int cols = tree->left->Gentry->size/rows;
                fprintf(target_file,"[%d x i32], [%d x i32]* %%%d, ",cols,cols,r);
                if(tree->left->left->nodetype != NUM_NODE)
                   fprintf(target_file,"i64 0, i64 %%%d\n",q);
                else
                   fprintf(target_file,"i64 0, i64 %d\n",q);
            }
	
	}
	//A 1D array
	else if(tree->left->left != NULL)
	{
	    q = codegen(tree->left->left,target_file);
	    if(tree->left->left->nodetype != NUM_NODE)
            {
                p = getReg();
                fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,q);
                q = p;
            }
            p = getReg();
            fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
            if(tree->left->Gentry->type == TLookup("int"))
            {
                int size = tree->left->Gentry->size;
                fprintf(target_file,"[%d x i32], [%d x i32]* @%s, ",size,size,tree->left->Gentry->name);
                if(tree->left->left->nodetype != NUM_NODE)
                   fprintf(target_file,"i64 0, i64 %%%d\n",q);
                else
                   fprintf(target_file,"i64 0, i64 %d\n",q);
             }
	}
	//An identifier
	else
	{
	    if(tree->left->Lentry == NULL)
	    {
		p = getReg();
		fprintf(target_file,"  %%%d = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ",p);
		if(tree->left->type == TLookup("int"))
		{
		    fprintf(target_file,"([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* @%s)\n",tree->left->Gentry->name);
		}
		else if(tree->left->type == TLookup("str"))
		{
		    fprintf(target_file,"([3 x i8], [3 x i8]* @.str.2, i32 0,i32 0), [32 x i8]* @%s)\n",tree->left->Gentry->name);
		}
	    }
	    else
	    {
                p = tree->left->Lentry->binding;
		int q = getReg();
		fprintf(target_file,"  %%%d = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ",q);
		if(tree->left->type == TLookup("int"))
                {
		   fprintf(target_file,"([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* %%%d)\n",p);
		}
		else
		{
                   fprintf(target_file,"([3 x i8], [3 x i8]* @.str.2, i32 0, i32 0), [32 x i8]* %%%d)\n",p);
		}
   	    }
	    return -1;
	}
	q = getReg();
	fprintf(target_file,"  %%%d = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ",q);                          
        fprintf(target_file,"([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* %%%d)\n",p);
	return -1;
    }
    else if(tree->nodetype == WRITE_NODE)
    {
	int q = codegen(tree->left,target_file);
	int p = getReg();
	fprintf(target_file,"  %%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* ",p);
	if(tree->left->type == TLookup("int"))
	{
	    fprintf(target_file,"@.str.1, i32 0, i32 0), i32 ");
	    if(tree->left->nodetype != NUM_NODE)
		fprintf(target_file,"%%%d)\n",q);
	    else
		fprintf(target_file,"%d)\n",q);
	}
	else if(tree->left->type == TLookup("str"))
	{
	    fprintf(target_file,"@.str.3, i32 0, i32 0), i8* %%%d)\n",q);
	}
	return -1;
    }
    else if(tree->nodetype == OP_NODE)
    {

        char *op = tree->varname;
	int p;
	if(op[0] != '=' || op[1] != '\0')
            p = codegen(tree->left,target_file);

        int q = codegen(tree->right,target_file);

	if(*op == '=' && op[1] == '\0')
	{
	    if(tree->right->nodetype == ALLOC_NODE)
	    {
		int p = getReg();
		fprintf(target_file,"  %%%d = bitcast i8* %%%d to %%struct.%s*\n",p,q,tree->left->type->name);
		//q = p;
		
		fprintf(target_file,"  store %%struct.%s* %%%d, %%struct.%s** ",tree->left->type->name,p,tree->left->type->name);
		
		if(tree->left->Gentry)
		{
		    fprintf(target_file,"@%s, align 8\n",tree->left->Gentry->name);
		}
		else
		{
		    fprintf(target_file,"%%%d, align 8\n",tree->left->Lentry->binding);
		}
	    }
	    else if(tree->left->nodetype == FIELD_NODE)
	    {
		int p,s;
        	struct Typetable* type = NULL;
		struct ClassTable* class = NULL;
       		p = getReg();
        	if(tree->left->Lentry == NULL)
        	{   
            	    type = tree->left->Gentry->type;
		    fprintf(target_file,"  %%%d = load %%struct.%s*, %%struct.%s** @%s, align 8\n",p,type->name,type->name,tree->left->Gentry->name);
        	}
        	else
        	{   
            	    s = tree->left->Lentry->binding;
            	    type = tree->left->Lentry->type;
		    class = NULL;
		    if(type == NULL)
		    {
                	class = tree->left->class;
			fprintf(target_file,"MOV R%d,[R%d]\n",p,p);
		    }
		    fprintf(target_file,"  %%%d = load %%struct.%s*, %%struct.%s** %%%d, align 8\n",p,type->name,type->name,s);
        	}
        	struct node* temp = tree->left->left;
        	struct Fieldlist* field = NULL;
        	int offset = 0;
        	while(temp != NULL)
        	{   
		    s = getReg();
            	    offset = 0;
		    if(type != NULL)
            	       	field = type->fields;
		    else
			field = class->fields;
           	    while(field != NULL && strcmp(temp->varname,field->name) != 0)
            	    {	   
                	offset++;
                	field = field->next;
            	    }
            	    fprintf(target_file,"  %%%d = getelementptr inbounds %%struct.%s, %%struct.%s* %%%d, i32 0, i32 %d\n",s,type->name,type->name,p,offset);
		    p = s;
            	    temp = temp->left;
            	    type = field->type;
        	}
		fprintf(target_file,"  store ");
		if(tree->left->type == TLookup("int"))
		{
                    if(tree->right->nodetype == NUM_NODE)
                    {
                        fprintf(target_file,"i32 %d, ",q);
                    }
                    else
                    {
                        fprintf(target_file,"i32 %%%d, ",q);
                    }
                    fprintf(target_file,"i32* %%%d, align 4\n",p);
		}
		else if(tree->right->nodetype == NULL_NODE)
		{
	fprintf(target_file,"%%struct.%s* null, %%struct.%s** %%%d, align 8\n",tree->left->type->name,tree->left->type->name,p);
		}
		else
		{
		    fprintf(target_file,"%%struct.%s* %%%d, %%struct.%s** %%%d, align 8\n",tree->left->type->name,q,tree->left->type->name,p);
		}
	    }
	    //ELSE A VAR-NODE
	    else if(tree->left->left == NULL)
	    {
		if(tree->left->nodetype != PTR_NODE)
		{
		    if(tree->left->type == TLookup("str")) 	//llvm.memcpy for string assignment
		    {
			int p = codegen(tree->left,target_file);
                        fprintf(target_file,"  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %%%d, i8* %%%d, ",p,q);
                        if(!tree->right->Gentry && !tree->right->Lentry)
                        {
                            fprintf(target_file," i32 %d, i1 false)\n",str_len(tree->right->varname) + 1);
                        }   
                        else
                            fprintf(target_file," i32 32, i1 false)\n");
			return -1;
		    }
		    //Global
		    if(tree->left->Lentry == NULL)
		    {
			fprintf(target_file,"  store ");
			if(tree->left->type == TLookup("int"))
			{
			    if(tree->right->nodetype == NUM_NODE)
			    {
			        fprintf(target_file,"i32 %d, ",q);
			    }
			    else
			    {
			        fprintf(target_file,"i32 %%%d, ",q);
			    }
			    fprintf(target_file,"i32* @%s, align 4\n",tree->left->Gentry->name);
			}
			else if(tree->right->nodetype == NULL_NODE)
                	{
        fprintf(target_file,"%%struct.%s* null, %%struct.%s** @%s, align 8\n",tree->left->type->name,tree->left->type->name,tree->left->Gentry->name);
                	}
			else
			{
    fprintf(target_file,"%%struct.%s* %%%d, %%struct.%s** @%s, align 8\n",tree->left->type->name,q,tree->left->type->name,tree->left->Gentry->name);  
			}
		    }
		    //Local
		    else
		    {
			fprintf(target_file,"  store ");
			p = (tree->left->Lentry)->binding;
			if(tree->left->type == TLookup("int"))
			{
			    if(tree->right->nodetype == NUM_NODE)
                            {
                                fprintf(target_file,"i32 %d, ",q);
                            }
                            else
                            {
                                fprintf(target_file,"i32 %%%d, ",q);
                            }
                            fprintf(target_file,"i32* %%%d, align 4\n",p);
			}
			else if(tree->right->nodetype == NULL_NODE)
                        {
        fprintf(target_file,"%%struct.%s* null, %%struct.%s** %%%d, align 8\n",tree->left->type->name,tree->left->type->name,p);
                        }
			else
			{
      fprintf(target_file,"%%struct.%s* %%%d, %%struct.%s** %%%d, align 8\n",tree->left->type->name,q,tree->left->type->name,p);  
			}
		    }
		}
		else
		{
		    p = (tree->left->Gentry)->binding;
		    int r = getReg();
		    fprintf(target_file,"MOV R%d,[%d]\nMOV [R%d],R%d\n",r,p,r,q);
		}
	    }
	    //ELSE ITS AN ARRAY-NODE
	    else if(tree->left->right != NULL)
	    {
		int s,r;
            	//code for finding row
            	s = codegen(tree->left->left,target_file);
		if(tree->left->left->nodetype != NUM_NODE)
            	{
		    p = getReg();
            	    fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,s);
            	    s = p;
		}
            	p = getReg();
            	fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
            	if(tree->left->Gentry->type == TLookup("int"))
            	{
                    int rows = tree->left->Gentry->rowSize;
                    int cols = tree->left->Gentry->size/rows;
                   fprintf(target_file,"[%d x [%d x i32]], [%d x [%d x i32]]* @%s, ",rows,cols,rows,cols,tree->left->Gentry->name);
		    if(tree->left->left->nodetype != NUM_NODE)
                   	fprintf(target_file,"i64 0, i64 %%%d\n",s);
                    else
                   	fprintf(target_file,"i64 0, i64 %d\n",s);
	
            	}
            	r = p;

            	//code for the columns in that row
            	s = codegen(tree->left->right,target_file);
		if(tree->left->right->nodetype != NUM_NODE)
		{
            	    p = getReg();
           	    fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,s);
            	    s = p;
		}
            	p = getReg();
            	fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
            	if(tree->left->Gentry->type == TLookup("int"))
            	{
                    int rows = tree->left->Gentry->rowSize;
                    int cols = tree->left->Gentry->size/rows;
                    fprintf(target_file,"[%d x i32], [%d x i32]* %%%d, ",cols,cols,r);
		    if(tree->left->right->nodetype != NUM_NODE)
                   	fprintf(target_file,"i64 0, i64 %%%d\n",s);
                    else
                   	fprintf(target_file,"i64 0, i64 %d\n",s);
             	}
		fprintf(target_file,"  store ");
		if(tree->right->nodetype == NUM_NODE)
                {   
                    fprintf(target_file,"i32 %d, ",q);
                }
                else
                {   
                    fprintf(target_file,"i32 %%%d, ",q);
                }
                fprintf(target_file,"i32* %%%d, align 4\n",p);
	    }
	    //1D-Array
	    else
	    {
		int s;
		s = codegen(tree->left->left,target_file);
		if(tree->left->left->nodetype != NUM_NODE)
		{
            	    p = getReg();
            	    fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,s);
            	    s = p;
		}
            	p = getReg();
            	fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
		if(tree->left->Gentry->type == TLookup("int"))
		{
                    int size = tree->left->Gentry->size;
                    fprintf(target_file,"[%d x i32], [%d x i32]* @%s, ",size,size,tree->left->Gentry->name);
		    if(tree->left->left->nodetype != NUM_NODE)
                       fprintf(target_file,"i64 0, i64 %%%d\n",s);
                    else
                       fprintf(target_file,"i64 0, i64 %d\n",s);
		}
            	
		fprintf(target_file,"  store ");
                if(tree->right->nodetype == NUM_NODE)
                {
                    fprintf(target_file,"i32 %d, ",q);
                }
                else
                {
                    fprintf(target_file,"i32 %%%d, ",q);
                }
                fprintf(target_file,"i32* %%%d, align 4\n",p);
  	    }		    
	    return -1;
	}

	int r = getReg();
	fprintf(target_file,"  %%%d = ",r);

	if(*op == '+')
        {
            fprintf(target_file,"add nsw");
        }   
        else if(*op == '-')
        {
            fprintf(target_file,"sub nsw");
        }   
        else if(*op == '*')
        {
            fprintf(target_file,"mul nsw");
        }   
        else if(*op == '/')
        {
            fprintf(target_file,"sdiv");
        }   
        else if(*op == '%')
        {
            fprintf(target_file,"urem");
        }
	else if(op[0] == '<' && op[1] == '=')
        {
	    fprintf(target_file,"icmp sle");
	}
	else if(op[0] == '>' && op[1] == '=')
        {   
            fprintf(target_file,"icmp sge");
        }
	else if(op[0] == '=' && op[1] == '=')
        {   
            fprintf(target_file,"icmp eq");
        }
	else if(op[0] == '!' && op[1] == '=')
        {   
            fprintf(target_file,"icmp ne");
        }
	else if(op[0] == '&' && op[1] == '&')
	{
	    fprintf(target_file,"and");
	}
        else if(op[0] == '|' && op[1] == '|')
        {
            fprintf(target_file,"or");
        }
        else if(*op == '<')
        {   
            fprintf(target_file,"icmp slt");
        }
        else if(*op == '>')
        {   
            fprintf(target_file,"icmp sgt");
        }

	if(tree->left->type == TLookup("int"))
	    fprintf(target_file," i32");
	else
	    fprintf(target_file," %%struct.%s*",tree->left->type->name);

        if(tree->left->nodetype == NUM_NODE)
		fprintf(target_file," %d,",p);
	else if(tree->left->nodetype == NULL_NODE)
		fprintf(target_file," null,");
	else
		fprintf(target_file,"  %%%d,",p);

	if(tree->right->nodetype == NUM_NODE)
		fprintf(target_file," %d \n",q);
	else if(tree->right->nodetype == NULL_NODE)
		fprintf(target_file," null\n");
	else
		fprintf(target_file,"  %%%d \n",q);
        return r;
    } 
    else if(tree->nodetype == VAR_NODE)
    {
	int p,q;

	if(tree->left == NULL)
	{
	    p = getReg();
	    if(tree->Lentry == NULL)
            {
		fprintf(target_file,"  %%%d = ",p);
		if(tree->Gentry->type == TLookup("int"))
		    fprintf(target_file,"load i32, i32* @%s, align 4\n",tree->Gentry->name);
		else if(tree->Gentry->type == TLookup("str"))
		    fprintf(target_file,"getelementptr inbounds [32 x i8], [32 x i8]* @%s, i32 0, i32 0\n",tree->Gentry->name);
		else
		    fprintf(target_file,"load %%struct.%s*, %%struct.%s** @%s, align 8\n",tree->Gentry->type->name,tree->Gentry->type->name,tree->Gentry->name);
	    }
	    else
	    {
	 	q = tree->Lentry->binding;
		fprintf(target_file,"  %%%d = ",p);
                if(tree->Lentry->type == TLookup("int"))
		   fprintf(target_file,"load i32, i32* %%%d, align 4\n",q);
		else if(tree->Lentry->type == TLookup("str"))
		   fprintf(target_file,"getelementptr inbounds [32 x i8], [32 x i8]* %%%d, i32 0, i32 0\n",q);
	 	else
		   fprintf(target_file,"load %%struct.%s*, %%struct.%s** %%%d, align 8\n",tree->Lentry->type->name,tree->Lentry->type->name,q);
	    }
	}
	else if(tree->right != NULL)
	{
	    int r;
	    //code for finding row
	    q = codegen(tree->left,target_file);
	    if(tree->left->nodetype != NUM_NODE)
	    {
	        p = getReg();
	        fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,q);
	        q = p;
	    }
	    p = getReg();
	    fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
	    if(tree->Gentry->type == TLookup("int"))
	    {
		int rows = tree->Gentry->rowSize;
		int cols = tree->Gentry->size/rows;
	    	fprintf(target_file,"[%d x [%d x i32]], [%d x [%d x i32]]* @%s, ",rows,cols,rows,cols,tree->Gentry->name);
		if(tree->left->nodetype != NUM_NODE)
	    	   fprintf(target_file,"i64 0, i64 %%%d\n",q);
		else
		   fprintf(target_file,"i64 0, i64 %d\n",q);
	    }
	    r = p;

	    //code for the columns in that row
	    q = codegen(tree->right,target_file);
	    if(tree->right->nodetype != NUM_NODE)
	    {
	        p = getReg();
                fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,q);
	        q = p;
	    }
	    p = getReg();
	    fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
	    if(tree->Gentry->type == TLookup("int"))
            {   
                int rows = tree->Gentry->rowSize;
                int cols = tree->Gentry->size/rows; 
                fprintf(target_file,"[%d x i32], [%d x i32]* %%%d, ",cols,cols,r);
		if(tree->right->nodetype != NUM_NODE)
                   fprintf(target_file,"i64 0, i64 %%%d\n",q);
                else
                   fprintf(target_file,"i64 0, i64 %d\n",q);
             }
	     q = p;
	     p = getReg();
	     fprintf(target_file,"  %%%d = load i32, i32* %%%d\n",p,q);
	}
	else
	{
	    q = codegen(tree->left,target_file);
	    if(tree->left->nodetype != NUM_NODE)
	    {
	       p = getReg();
	       fprintf(target_file,"  %%%d = sext i32 %%%d to i64\n",p,q);
	       q = p;
	    }
	    p = getReg();
	    fprintf(target_file,"  %%%d = getelementptr inbounds ",p);
	    if(tree->Gentry->type == TLookup("int"))
            {
                int size = tree->Gentry->size;
                fprintf(target_file,"[%d x i32], [%d x i32]* @%s, ",size,size,tree->Gentry->name);
		if(tree->left->nodetype != NUM_NODE)
                   fprintf(target_file,"i64 0, i64 %%%d\n",q);
                else
                   fprintf(target_file,"i64 0, i64 %d\n",q);
            }
	    q = p;
            p = getReg();
            fprintf(target_file,"  %%%d = load i32, i32* %%%d\n",p,q);
	}
	return p;
    }
    else if(tree->nodetype == FIELD_NODE)
    {
	int p,q;
   	struct Typetable* type = NULL;
	struct ClassTable* class = NULL;
	p = getReg();
	if(tree->Lentry == NULL)
	{
	    type = tree->Gentry->type;
	    fprintf(target_file,"  %%%d = load %%struct.%s*, %%struct.%s** @%s, align 8\n",p,type->name,type->name,tree->Gentry->name);
	}
	else
	{
	    q = tree->Lentry->binding;
	    type = tree->Lentry->type;
	    if(type == NULL)
	    {
		class = tree->class;
		fprintf(target_file,"MOV R%d,[R%d]\n",p,p);
	    }
   fprintf(target_file,"  %%%d = load %%struct.%s*, %%struct.%s** %%%d, align 8\n",p,type->name,type->name,tree->Lentry->binding);
	}
	struct node* temp = tree->left;
  	struct Fieldlist* field = NULL;
	int offset;
	while(temp != NULL)
	{
  	    q = getReg(); 
	    offset = 0;
	    if(type != NULL)
	        field = type->fields;
	    else
		field = class->fields;
	    while(field != NULL && strcmp(temp->varname,field->name) != 0)
	    {
		offset++;
		field = field->next;
	    }
       fprintf(target_file,"  %%%d = getelementptr inbounds %%struct.%s, %%struct.%s* %%%d, i32 0, i32 %d\n",q,type->name,type->name,p,offset);
	    p = q;
	    temp = temp->left;
	    type = field->type;
	}
	q = p;
	p = getReg();
	if(type == TLookup("int"))
	{
	    fprintf(target_file,"  %%%d = load i32, i32* %%%d\n",p,q);
	}
	else
	{
	    fprintf(target_file,"  %%%d = load %%struct.%s*, %%struct.%s** %%%d\n",p,type->name,type->name,q);
	}
	return p;
    }
    else if(tree->nodetype == NUM_NODE)
    {
	return tree->val;
    }
    else if(tree->nodetype == PTR_NODE)
    {
	int p = getReg();
	fprintf(target_file,"MOV R%d,[%d]\nMOV R%d,[R%d]\n",p,tree->Gentry->binding,p,p);
	return p;
    }
    else if(tree->nodetype == ADD_NODE)
    {
	int p = getReg();
	fprintf(target_file,"MOV R%d,%d\n",p,tree->Gentry->binding);
	return p;
    }
    else if(tree->nodetype == BRK_NODE)
    {
	if(loopFlg > 0)
	 	fprintf(target_file,"br label %%L%d\n",label3);
	return -1;
    }
    else if(tree->nodetype == CON_NODE)
    {
	if(loopFlg < 0)
		fprintf(target_file,"br label %%L%d\n",label1);
	return -1;
    }
    else if(tree->nodetype == STR_NODE)
    {
	int p = getReg();
	if(tree->Gentry || tree->Lentry)
	{
	    fprintf(target_file,"  %%%d = getelementptr inbounds [32 x i8], [32 x i8]* @%s, i32 0, i32 0\n",p,tree->Gentry->name);
	    return p;
	}
	struct StringNames* S = StrLookup(Stringtable,tree->varname);
        if(!S)
        {   
            printf("COMPILER ERROR\n");
            exit(0);
        }
        int len = str_len(S->name) + 1;
        fprintf(target_file,"  %%%d = getelementptr inbounds [%d x i8], [%d x i8]* @.str.%d, i32 0, i32 0\n",p,len,len,S->index);
	return p;
    }
    else if(tree->nodetype == SELF_NODE)
    {
	struct Fieldlist* field = Class_FLookup(tree->class,tree->left->varname);
	struct ClassTable* class = tree->class;
    }
    else if(tree->nodetype == FUNC_NODE)
    {
	struct Gsymbol* Gtemp = symHead;
        while(Gtemp != NULL && strcmp(tree->varname,Gtemp->name) != 0)
            Gtemp = Gtemp->next;	

	struct Lsymbol* Ltemp = generateArgsCode(tree->left);
	int p = getReg();
	fprintf(target_file,"  %%%d = call ",p);

	if(Gtemp->type == TLookup("int"))
	    fprintf(target_file,"i32 ");
	else if(Gtemp->type == TLookup("str"))
	    fprintf(target_file,"[32 x i8]* ");
	else
	    fprintf(target_file,"%%struct.%s* ",Gtemp->type->name);

	fprintf(target_file,"@%s(",Gtemp->name);
	while(Ltemp->next)
	{
	    if(Ltemp->type == TLookup("int"))
	    {
		if(!Ltemp->name)
		  	fprintf(target_file,"i32 %%%d, ",Ltemp->binding);
		else
			fprintf(target_file,"i32 %d, ",Ltemp->binding);
	    }
	    else if(Ltemp->type == TLookup("str"))
	    {
		fprintf(target_file,"[32 x i8]* %%%d, ",Ltemp->binding);
	    }
	    else
		fprintf(target_file,"%%struct.%s* %%%d, ",Ltemp->type->name,Ltemp->binding);
	    Ltemp = Ltemp->next;
	}
	if(Ltemp)
	{
	    if(Ltemp->type == TLookup("int"))
	    {
		if(!Ltemp->name)
	                fprintf(target_file,"i32 %%%d",Ltemp->binding);
		else
			fprintf(target_file,"i32 %d",Ltemp->binding);
	    }
	    else if(Ltemp->type == TLookup("str"))
            {    
                fprintf(target_file,"[32 x i8]* %%%d, ",Ltemp->binding);
            }
	    else
		fprintf(target_file,"%%struct.%s* %%%d",Ltemp->type->name,Ltemp->binding);
	}
	fprintf(target_file,")\n");
	if(Gtemp->type == TLookup("str"))
	{
	    int q = getReg();
	    fprintf(target_file,"  %%%d = getelementptr inbounds [32 x i8], [32 x i8]* %%%d, i32 0, i32 0\n",q,p);
	    p = q;
	}
	return p;
    }
    else if(tree->nodetype == FIELDFUNC_NODE)
    {
	int localVar = rel_binding;
        int savedReg = -1;
        if(regFlag[0] == 1)
        {   
            savedReg = 0;
            while(savedReg < 20)
            {   
                if(regFlag[savedReg] == 1)
                {   
                    fprintf(target_file,"PUSH R%d\n",savedReg);
                    regFlag[savedReg ] = 0;
                    savedReg++;
                }
                else
                    break;
            }
            savedReg--;
        }

	struct Gsymbol* Gtemp = symHead;
        while(Gtemp != NULL && strcmp(tree->varname,Gtemp->name) != 0)
            Gtemp = Gtemp->next;

	struct Lsymbol* Ltemp = NULL;
	struct ClassTable* class;
	if(Gtemp != NULL)
 	    class= Gtemp->class;
	else
	{
	    Ltemp = Ltable;
	    while(Ltemp != NULL && strcmp(Ltemp->name,tree->varname) != 0)
		Ltemp = Ltemp->next;
	    class = tree->class;
	}

        int p = getReg();
        if(Gtemp != NULL)
               fprintf(target_file,"MOV R%d,%d\nPUSH R%d\nADD R%d,1\nPUSH R%d\n",p,Gtemp->binding,p,p,p);  //Add virtual table ptr
        else
        {
                int q = getReg();
                fprintf(target_file,"MOV R%d,BP\nMOV R%d,%d\nADD R%d,R%d\nMOV R%d,[R%d]\n",p,q,Ltemp->binding,p,q,p,p);
                freeReg();
        }


	struct node* temp = tree->left;
	struct Fieldlist* field = Class_FLookup(class,temp->varname);
	while(temp->left != NULL)
	{
	    field = Class_FLookup(class,temp->varname);
	    if(Gtemp == NULL)
	    {
		int q = getReg();
		fprintf(target_file,"MOV R%d,[R%d]\nMOV R%d,%d\nADD R%d,R%d\n",p,p,q,field->fieldIndex,p,q);
		if(temp->left->left != NULL)
			fprintf(target_file,"MOV R%d,[R%d]\n",p,p);
		freeReg();
	    }
	    class = field->Ctype;
	    temp = temp->left;
	}
	if(Gtemp == NULL)
	{
	    fprintf(target_file,"PUSH R%d\nADD R%d,1\nPUSH R%d\n",p,p,p); 	//Assuming each class takes 2 words even in heap
	}
	
	struct Memberfunclist* Mtemp = Class_MLookup(class,temp->varname);
 	int q = getReg();
	//Value of func label in R[p]
	fprintf(target_file,"MOV R%d,[R%d]\nMOV R%d,%d\nADD R%d,R%d\nMOV R%d,[R%d]\n",p,p,q,Mtemp->funcPosition,p,q,p,p);
	freeReg();

	struct Paramstruct* paramList = Mtemp->paramList;
	int params = checkArgs(tree->right,paramList,temp->varname);

//	generateArgsCode(tree->right);
	fprintf(target_file,"PUSH R0\nCALL R%d\nPOP R16\nSUB SP,%d\n",p,params);
	freeReg();
	fprintf(target_file,"SUB SP,2\n");
		
	while(savedReg > -1)
        {   
            fprintf(target_file,"POP R%d\n",savedReg);
            regFlag[savedReg] = 1;
            savedReg--;
        }
        p = getReg();
        fprintf(target_file,"MOV R%d,R16\n",p);
        rel_binding = localVar;
        return p;

    }
    else if(tree->nodetype == RET_NODE)
    {
	if(phase == 5)
	{
	    fprintf(target_file,"  ret i32 0\n");
	    return -1;
	}
	int p;
	if(tree->left->type != TLookup("str"))
		p = codegen(tree->left,target_file);
	else
	{
	  if(tree->left->Gentry)
		fprintf(target_file,"  ret [32 x i8]* @%s\n",tree->left->Gentry->name);
	  else
		p = tree->left->Lentry->binding;
	}

	if(tree->left->nodetype == NUM_NODE)
	    fprintf(target_file,"  ret i32 %d\n",p);
	else
	{
	    fprintf(target_file,"  ret");
	    if(tree->left->type == TLookup("int"))
		fprintf(target_file," i32 %%%d\n",p);
	    else if(tree->left->type == TLookup("str"))
		fprintf(target_file," [32 x i8]* %%%d\n",p);
	    else
		fprintf(target_file," %%struct.%s* %%%d\n",tree->left->type->name,p);
	}
	return -1;
    }
    else if(tree->nodetype == INIT_NODE)
    {
	fprintf(target_file,"MOV R16,\"Heapset\"\nPUSH R16\nPUSH R17\nPUSH R17\nPUSH R17\nPUSH R17\n");
	fprintf(target_file,"CALL 0\n");
	fprintf(target_file,"POP R17\nPOP R16\nPOP R16\nPOP R16\nPOP R16\n");
	return 17;
    }
    else if(tree->nodetype == ALLOC_NODE)
    {
	int p = getReg();
	fprintf(target_file,"  %%%d = call i8* @malloc(i64 32)\n",p);
	return p;
    }
    else if(tree->nodetype == FREE_NODE)
    {
	int p = codegen(tree->left,target_file);
        fprintf(target_file,"MOV R16,\"Free\"\nPUSH R16\nPUSH R%d\nPUSH R17\nPUSH R17\nPUSH R17\n",p);
        fprintf(target_file,"CALL 0\n");
        fprintf(target_file,"POP R17\nPOP R16\nPOP R16\nPOP R16\nPOP R16\n");
        return 17;
    }
    else if(tree->nodetype == NEW_NODE)
    {
	fprintf(target_file,"MOV R16,\"Alloc\"\nPUSH R16\nPUSH R17\nPUSH R17\nPUSH R17\nPUSH R17\n");
        fprintf(target_file,"CALL 0\n");
        fprintf(target_file,"POP R17\nPOP R16\nPOP R16\nPOP R16\nPOP R16\n");
	fprintf(target_file,"MOV R18,%d\n",4096+8*(tree->class->class_index));
        return 17;
	//Code for setting up virtual function table
    }
    else if(tree->nodetype == DELETE_NODE)
    {
	int p = codegen(tree->left,target_file);
        fprintf(target_file,"MOV R16,\"Free\"\nPUSH R16\nPUSH R%d\nPUSH R17\nPUSH R17\nPUSH R17\n",p);
        fprintf(target_file,"CALL 0\n");
        fprintf(target_file,"POP R17\nPOP R16\nPOP R16\nPOP R16\nPOP R16\n");
        return 17;
    }
    else if(tree->nodetype == NULL_NODE)
    {
    }
    return -1;
}

void Install(struct node* varNode,char* type,int size,int rowSize,struct Paramstruct* paramList)
{
    int flg = 1;
    struct Gsymbol* temp = symHead;
    while(temp != NULL)
    {
	if(strcmp(temp->name,varNode->varname) == 0)
	{
	    flg = 0;
	    break;
	}
	temp = temp->next;
    }
	
    if(flg != 0)
    {
	struct Gsymbol* newNode = malloc(1*sizeof(struct Gsymbol));
	newNode->name = varNode->varname;
	newNode->type = TLookup(type);
	newNode->class = NULL;
	if(newNode->type == NULL)
	{
	    newNode->class = CLookup(type);
	    if(newNode->class == NULL)
	    {
		printf("LINE %d : Undeclared type %s\n",line,type);
		exit(0);
	    }
	    size = 2;
	}
	newNode->size = size;
	newNode->paramList = paramList;
	if(size != 0)
	{
	    newNode->binding = freeAdd;
	    newNode->rowSize = rowSize;
	    freeAdd += size;
	}
	if(size == 0)
	{
	    newNode->flabel = flabel++;
	}
	else
	{
	    newNode->flabel = -1;
	}
	newNode->next = symHead;
	symHead = newNode;
    }
    else if(flg == 0)
    {
	if(size != 0)
		printf("%s already declared!\n",varNode->varname);
	else
		printf("%s() already declared!\n",varNode->varname);
	exit(0);
    }
    if(symHead->type != NULL)
        printf("%s %s %d %d %d\n",symHead->name,symHead->type->name,symHead->size,symHead->binding,symHead->rowSize);
    else
	printf("%s %s %d %d %d\n",symHead->name,symHead->class->name,symHead->size,symHead->binding,symHead->rowSize);
    if(symHead->paramList != NULL)
    {
        printf("FUNC args:\n");
        struct Paramstruct* temp = symHead->paramList;
        while(temp != NULL)
        {
            printf("%s %s\n",temp->name,temp->type->name);
            temp = temp->next;
        }
    }
    return;
}

struct Lsymbol* LInstall(struct Lsymbol* head,char* name,char* type)
{
    struct Lsymbol* newNode = malloc(sizeof(struct node));
    newNode->name = name;
    newNode->type = TLookup(type);
    if(newNode->type == NULL && CurrentClass == NULL)
    {
	printf("LINE %d : Undeclared type %s\n",line,type);
	exit(0);
    }
    newNode->next = NULL;
    if(head == NULL)
	return newNode;
    else
    {
	struct Lsymbol* temp = head;
	while(temp->next != NULL)
	    temp = temp->next;
	temp->next = newNode;
    }
    return head;
}

void checkParam(char* name,struct Paramstruct* paramList)
{
    struct Gsymbol* Gsymtemp = symHead;
    while(Gsymtemp != NULL && strcmp(Gsymtemp->name,name) != 0)
        Gsymtemp = Gsymtemp->next;

    struct Memberfunclist* Mtemp = Class_MLookup(CurrentClass,name);
    if(Gsymtemp != NULL  || Mtemp != NULL)
    {
        int flg = 1;
        struct Paramstruct* funcParam;
	if(Gsymtemp != NULL)
	    funcParam = Gsymtemp->paramList;
	else
	    funcParam = Mtemp->paramList;

        while(funcParam != NULL || paramList != NULL)
        {
	    if((funcParam == NULL && paramList != NULL) || (funcParam != NULL && paramList == NULL))
	    {
		flg = 0;
                break;
	    }
            if(funcParam->type != paramList->type)
            {
                flg = 0;
                break;
            }
            funcParam = funcParam->next;
            paramList = paramList->next;
        }
        if(flg == 0)
        {
            printf("Parameter mismatch for function %s()\n",name);
            exit(1);
        }
    }
    else
    {
        printf("%s() function not declared\n",name);
        exit(0);
    }
}

void TypeTableInitialize()
{
    struct Typetable* newNode = malloc(sizeof(struct Typetable));
    char *ch = malloc(3);
    ch[0] = 'i';ch[1] = 'n';ch[2] = 't';
    newNode->name = ch;
    newNode->size = 1;
    newNode->fields = NULL;
    Typetable = newNode;

    newNode = malloc(sizeof(struct Typetable));
    ch = malloc(3);
    ch[0] = 's';ch[1] = 't';ch[2] = 'r';
    newNode->name = ch;
    newNode->size = 1;
    newNode->fields = NULL;   
    Typetable->next = newNode;

    newNode = malloc(sizeof(struct Typetable));
    ch = malloc(4);
    ch[0] = 'b';ch[1] = 'o';ch[2] = 'o';ch[3] = 'l';
    newNode->name = ch;
    newNode->size = 1;
    newNode->fields = NULL;   
    newNode->next = NULL; 
    Typetable->next->next = newNode;
    return;
}

void TInstall(char* name)
{
    struct Typetable* Ttemp = Typetable;
    while(Ttemp->next != NULL)
         Ttemp = Ttemp->next; 
    struct Typetable* newNode = malloc(sizeof(struct Typetable));
    newNode->name = name;
    newNode->next = NULL;
    Ttemp->next = newNode;
    return;
}

void TInstallFields(char* name,int size,struct Fieldlist* Fields)
{
    struct Typetable* Ttemp = Typetable;
    while(Ttemp != NULL && strcmp(Ttemp->name,name) != 0)
         Ttemp = Ttemp->next;
    Ttemp->size = size;
    if(size > 8)
    {
	printf("LINE%d:Size greater than 8 for type %s\n",line,name);
	exit(0);
    }
    Ttemp->fields = Fields;
    return;
}

struct Typetable* TLookup(char* name)
{
    if(name != NULL)
    {
	struct Typetable* Ttemp = Typetable;
    	while(Ttemp != NULL && strcmp(Ttemp->name,name) != 0)
	    Ttemp = Ttemp->next;
    	return Ttemp;
    }
    return NULL;
}

struct Fieldlist* FInstall(struct Fieldlist* Fields,char* name,char* typename,int* fieldSize)
{
    struct Fieldlist* newNode = malloc(sizeof(struct Fieldlist));
    newNode->name = name;
    struct Typetable* Ttemp = Typetable;
    while(Ttemp != NULL && strcmp(Ttemp->name,typename) != 0)
	Ttemp = Ttemp->next;
    if(Ttemp == NULL)
    {
 	printf("Undeclared type %s\n",typename);
	exit(0);
    }
    newNode->type = Ttemp;
    newNode->next = NULL;
    *fieldSize = *fieldSize + 1;
 
    if(Fields == NULL)
    	return newNode;
    else
    {
   	struct Fieldlist* Ftemp = Fields;
	while(Ftemp->next != NULL)
	    Ftemp = Ftemp->next;
	Ftemp->next = newNode;
	return Fields;
    }
}

struct Typetable* getType(char* name,struct Typetable* type,struct ClassTable* class,struct node* Field)
{
    if(class != NULL && strcmp(name,"self") != 0)
    {
	printf("LINE %d : Access to fields of class %s is restricted\n",line,class->name);
	exit(0);
    }
    struct Fieldlist* Ftemp;
    if(class == NULL)
        Ftemp = type->fields;
    else
   	Ftemp = class->fields;
    while(Ftemp != NULL && strcmp(Ftemp->name,Field->varname) != 0)
    	Ftemp = Ftemp->next;
    if(Ftemp == NULL)
    {
	if(type != NULL)
	    printf("LINE%d : Undeclared type %s in type %s\n",line,Field->varname,type->name);
	else
	    printf("LINE%d : Undeclared type %s in class %s\n",line,Field->varname,class->name);
	exit(0);
    }
    if(Ftemp->Ctype != NULL && Field->left != NULL)
    {
         printf("LINE %d : Access to fields of class %s is restricted\n",line,Ftemp->Ctype->name);
         exit(0);
    }
    if(Field->left != NULL)
        return getType(NULL,Ftemp->type,Ftemp->Ctype,Field->left);
    else
    {
 	return Ftemp->type;
    }
}

struct Typetable* getFuncType(char* name,struct ClassTable* class,struct node* Field)
{
    if(strcmp(name,"self") != 0 && Field->left != NULL)
    {
	printf("LINE %d : Access to fields of class %s is restricted\n",line,class->name);
	exit(0);
    }

    if(Field->left != NULL)
    {
	struct Fieldlist* Ftemp = Class_FLookup(class,Field->varname);
	if(Ftemp == NULL)
        {
            printf("LINE %d : Undeclared field %s in class %s\n",line,Field->varname,class->name);
            exit(0);
        }
	if(Ftemp->Ctype != NULL)
            return getFuncType(Ftemp->name,Ftemp->Ctype,Field->left);
	else
	{
	  printf("LINE %d : Calling method %s() inside field %s which is not a class\n",line,Field->left->varname,Field->varname);
	    exit(0);
	}
    }
    else
    {
	struct Memberfunclist* Mtemp = Class_MLookup(class,Field->varname);
	if(Mtemp == NULL)
        {
            printf("LINE %d : Undeclared method %s() in class %s\n",line,Field->varname,class->name);
            exit(0);
        }
	return Mtemp->type;
    }
}


int checkArgs(struct node* args,struct Paramstruct* paramList,char* funcName)
{
    int params = 0;
    while(args != NULL || paramList != NULL)
    {
        if((args == NULL && paramList != NULL) || (args != NULL && paramList == NULL))
        {
             printf("LINE %d : Invalid number of arguments for %s()\n",line,funcName);
             exit(0);
        }
        if(args->type != paramList->type)
        {
            printf("LINE %d : Invalid type of arguments for %s()\n",line,funcName);
            exit(0);
        }
        params++;
        paramList = paramList->next;
        args = args->third;
   }
   return params;
}

struct ClassTable* CInstall(char* name,char* parentName)
{
    struct ClassTable* newNode = malloc(sizeof(struct ClassTable)),*parent = NULL;
    if(TLookup(name) || CLookup(name))
    {
 	printf("LINE %d : %s already declared\n",line,name);
	exit(0);
    }
    newNode->name = name;
    if(parentName != NULL)
    {
	parent = CLookup(parentName);
	if(parent == NULL)
	{
	    printf("LINE %d : %s class not found\n",line,parentName);
	    exit(0);
	}
    }
    newNode->parentClass = parent;
    newNode->fields = NULL;
    newNode->Vfuncptr = NULL;

    if(parent != NULL)
    {
        struct Fieldlist* fields = parent->fields;
        while(fields != NULL)
        {
	    if(fields->type != NULL)
 	        ClassFInstall(newNode,fields->type->name,fields->name);
	    else
		ClassFInstall(newNode,fields->Ctype->name,fields->name);	   
            fields = fields->next;
        }
        struct Memberfunclist* Methods = parent->Vfuncptr,*head = NULL,*curr = NULL;
        while(Methods != NULL)
        {
            struct Memberfunclist* newNode = malloc(sizeof(struct Memberfunclist));
            newNode->name = Methods->name;
            newNode->type = Methods->type;
            newNode->paramList = Methods->paramList;
            newNode->funcPosition = Methods->funcPosition;
            newNode->flabel = Methods->flabel;
            newNode->next = NULL;
            if(curr != NULL)
                curr->next = newNode;
            else
                head = newNode;
            curr = newNode;

            Methods = Methods->next;
        }
        newNode->Vfuncptr = head;
    }
    newNode->next = NULL;
    if(Classtable == NULL)
    {
	newNode->class_index = 0;
    	Classtable = newNode;
    }
    else
    {
	struct ClassTable* Ctemp = Classtable;
        while(Ctemp->next != NULL)
            Ctemp = Ctemp->next;
	Ctemp->next = newNode;
	newNode->class_index = Ctemp->class_index + 1;
    }
    return newNode;
}

struct ClassTable* CLookup(char *name)
{
    struct ClassTable* Ctemp = Classtable;
    while(Ctemp != NULL && strcmp(Ctemp->name,name) != 0)
	Ctemp = Ctemp->next;
    return Ctemp;
}

void ClassFInstall(struct ClassTable* class,char* type,char* name)
{
    struct Fieldlist* newNode = malloc(sizeof(struct Fieldlist));
    newNode->name = name;
    newNode->next = NULL;
    int size = 1;
    if(TLookup(type) != NULL)
    {
	newNode->type = TLookup(type);
    }
    else
    {
	newNode->Ctype = CLookup(type);
	if(newNode->Ctype == NULL)
	{
	    printf("LINE %d : Undeclared type %s in class %s\n",line,type,class->name);
	    exit(0);
	}
	size = 2;
    }
    newNode->size = size;
    struct Fieldlist* Ftemp = class->fields;
    if(Ftemp == NULL)
    {
	class->fields = newNode;
	newNode->fieldIndex = 0;
    }
    else
    {
	while(Ftemp->next != NULL)
	{
	    if(strcmp(Ftemp->name,name) == 0)
	    {
		printf("LINE %d : %s already declared in class %s\n",line,name,class->name);
		exit(0);
 	    }
	    Ftemp = Ftemp->next;
	}
	newNode->fieldIndex = Ftemp->fieldIndex + Ftemp->size;
	if(newNode->fieldIndex + size > 8)
	{
	    printf("LINE %d : Field size exceeds 8 in class %s\n",line,class->name);
	    exit(0);
	}
        if(strcmp(Ftemp->name,name) == 0)
        {
            printf("LINE %d : %s already declared in class %s\n",line,name,class->name);
            exit(0);
        }
	Ftemp->next = newNode;
    }
    return;
}

void ClassMInstall(struct ClassTable* class,char* name,char* type,struct Paramstruct* paramList)
{
    struct Memberfunclist* newNode = malloc(sizeof(struct Memberfunclist));
    newNode->name = name;
    newNode->type = TLookup(type);
    newNode->paramList = paramList;
    newNode->next = NULL;
    struct Memberfunclist* Mtemp = class->Vfuncptr;
    if(Mtemp == NULL)
    {
	class->Vfuncptr = newNode;
	newNode->flabel = flabel++;
	newNode->funcPosition = 0;	
    }
    else
    {
	int i = 1;
        while(Mtemp->next != NULL)
        {
            if(strcmp(Mtemp->name,name) == 0)
            {
                if(Class_MLookup(class->parentClass,name) != NULL)
                {
                    Mtemp->flabel = flabel++;
                    return;
                }
                else
                {
                    printf("LINE %d : %s() already declared in class %s\n",line,name,class->name);
                    exit(0);
                }
            }
            Mtemp = Mtemp->next;
            i++;
        }
	if(i > 7)
        {
            printf("LINE %d : More than 8 methods in class %s\n",line,class->name);
            exit(0);
        }
        if(strcmp(Mtemp->name,name) == 0)
        {
            if(Class_MLookup(class->parentClass,name) != NULL)
            {
                Mtemp->flabel = flabel++;
                return;
            }
            else
            {
                printf("LINE %d : %s() already declared in class %s\n",line,name,class->name);
                exit(0);
            }
        }
        Mtemp->next = newNode;
        newNode->flabel = flabel++;
	newNode->funcPosition = i;
    }
}

struct StringNames* InstallString(struct StringNames* S,char* name)
{
    struct StringNames* new_node = malloc(sizeof(struct StringNames));
    new_node->name = name;
    if(!S)
    {
    	new_node->index = 4;
        return new_node;
    }
    struct StringNames* STemp = S;
    while(STemp->next)
    	STemp = STemp->next;
    new_node->index = STemp->index + 1;
    new_node->next = STemp->next;
    STemp->next = new_node;
    return S;
}
 
struct StringNames* StrLookup(struct StringNames* S,char* name)
{
    while(S && strcmp(S->name,name) != 0)
	S = S->next;
    return S;
}

struct Memberfunclist* Class_MLookup(struct ClassTable* class,char* name)
{
    if(class != NULL)
    {
	struct Memberfunclist* Mtemp = class->Vfuncptr;
    	while(Mtemp != NULL && strcmp(Mtemp->name,name) != 0)
	{
    	    Mtemp = Mtemp->next;
	}
    	return Mtemp;
    }
    return NULL;
}

struct Fieldlist* Class_FLookup(struct ClassTable* class,char* name)
{
    if(class != NULL)
    {
    	struct Fieldlist* Ftemp = class->fields;
    	while(Ftemp != NULL && strcmp(Ftemp->name,name) != 0)
	{
	    Ftemp = Ftemp->next;
	}
    	return Ftemp;
    }
    return NULL;
}

int str_len(char* str)
{
    int len = 0;
    while(*str != '\0')
    {
	len++;
	str++;
    }
    return len;
}
