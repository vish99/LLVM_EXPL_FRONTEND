
%{
    #include<stdio.h>
    #include<stdlib.h>
    #define YYSTYPE struct node*
    #include"exptree.c"
    char* ch;
    extern FILE *yyin;
    extern int line;
    extern int freeAdd;
    int classes = 0;
    int varType = -1;
    int phase = 0;
    int fieldSize = 0;
    struct Lsymbol* Ltable = NULL;
    struct Fieldlist* Fields = NULL;
    struct ClassTable* CurrentClass = NULL;
%}

%token CLASS ENDCLASS DECL ENDDECL TYPE ENDTYPE INT STR null STRNODE MAIN RETURN INIT ALLOC FREE NEW DELETE SELF EXTENDS
%token BEGIN NUM EOS END_OF_FILE ID READ WRITE END IF ENDIF WHILE ENDWHILE THEN DO ELSE GT LT GE LE EQ NE AND OR BREAK CONTINUE  
%token REPEAT UNTIL
%right '='
%left GT LT GE LE EQ NE AND OR
%left '%' '.'
%left '+' '-'
%left '*'
%left '/'

%%
start : {TypeTableInitialize();generateInitCode();} Program END_OF_FILE   {printf("\n");return 1;}
	;

Program : TypeBlock ClassDefBlock GDeclBlock FDeclBlock MainBlock
	| TypeBlock ClassDefBlock GDeclBlock MainBlock		    
        ;

TypeBlock : TYPE TypeDefList ENDTYPE			{phase = 1;}
	  | %empty					{phase = 1;}
	  ;	

TypeDefList : TypeDefList TypeDef
	    | TypeDef
	    ;

TypeDef : ID {TInstall($1->varname);} '{' FieldDecList '}'   {TInstallFields($1->varname,fieldSize,Fields);
							      free($1);fieldSize = 0;;
							      generateTypeDef($1->varname,Fields);Fields = NULL;}
	;

FieldDecList : FieldDecList FieldDec		
	     | FieldDec 			
	     ;

FieldDec : TypeName ID EOS			{Fields=FInstall(Fields,$2->varname,$1->varname,&fieldSize);free($1);free($2);}
	 ;

TypeName : INT					{$$=makeNode(EMPTY_NODE,0,"int",NULL,NULL,NULL,NULL);}
	 | STR					{$$=makeNode(EMPTY_NODE,0,"str",NULL,NULL,NULL,NULL);}
	 | ID					{$$=$1;}
	 ;

ClassDefBlock : CLASS ClassDefList ENDCLASS		{phase = 2;freeAdd = 4096 + 8*classes;}
	      | %empty					{phase = 2;}
	        ;

ClassDefList : ClassDefList ClassDef
	     | ClassDef
	     ;

ClassDef : Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefs '}'  {CurrentClass = NULL;}
	   ;

Cname : ID					{CurrentClass = CInstall($1->varname,NULL);free($1);classes++;}
      | ID EXTENDS ID                           {CurrentClass = CInstall($1->varname,$3->varname);free($1);free($3);classes++;}
	;

Fieldlists : Fieldlists Fld			
	   | %empty

Fld : TypeName ID EOS				{ClassFInstall(CurrentClass,$1->varname,$2->varname);free($1);free($2);}
      	;

MethodDecl : MethodDecl MDecl
	   | MDecl
	   ;

MDecl : TypeName ID '(' ParamList ')' EOS	{ClassMInstall(CurrentClass,$2->varname,$1->varname,$4->paramList);
						 free($1);free($2);free($4);}
	;

MethodDefs : MethodDefs FDef			
	   | FDef							
	   ;



GDeclBlock : DECL GDeclList ENDDECL     {phase = 3;}
	   | DECL ENDDECL 	  	{phase = 3;Ltable = NULL;}
	   | %empty			{phase = 3;Ltable = NULL;}
	     ;
GDeclList : GDeclList GDecl | GDecl
	     ;
GDecl : TypeName VarList EOS		 
	 ;
	;
VarList : VarList ',' ID    			  {Install($3,$0->varname,1,0,NULL);free($3);}
	| ID		    			  {Install($1,$0->varname,1,0,NULL);free($1);}
	| VarList ',' ID '[' NUM ']' 		  {Install($3,$0->varname,$5->val,0,NULL);free($5);free($3);}
	| ID '[' NUM ']'    			  {Install($1,$0->varname,$3->val,0,NULL);free($1);free($3);}
	| VarList ',' ID '[' NUM ']' '[' NUM ']'  {Install($3,$0->varname,($5->val)*($8->val),$5->val,NULL);free($5);free($8);free($1);}
	| ID '[' NUM ']' '[' NUM ']'   		  {Install($1,$0->varname,($3->val)*($6->val),$3->val,NULL);free($3);free($6);free($1);}
	| VarList ',' '*' ID 			  {Install($4,$0->varname,1,0,NULL);free($4);}
	| '*' ID				  {Install($2,$0->varname,1,0,NULL);free($2);}
	| VarList ',' ID '(' ParamList ')'	  {Install($3,$0->varname,0,0,$5->paramList);free($3);free($5);}
	| ID '(' ParamList ')'			  {Install($1,$0->varname,0,0,$3->paramList);free($1);free($3);}
	   ;

FDeclBlock : FDeclBlock FDef
	   | FDef
	   ;

FDef : Fhead '{' LDeclBlock Body '}'			{printf("Ltable:\n");
                                    			struct Lsymbol* temp = Ltable;
                                    			while(temp != NULL)
                                    			{
							      
                                        			printf("%s \n",temp->name);
                                        			temp=temp->next;
                                   			 }
                                    			 printf("DONE Ltable\n");
							generateFuncCode($4,$1->varname);
							Ltable=NULL;free($1);}


Fhead : TypeName ID '(' ParamList ')'			{
							     if(CurrentClass != NULL && phase < 2 )
								Ltable = LInstall(Ltable,"self",NULL);
							     checkParam($2->varname,$4->paramList);
							     struct Paramstruct* temp = $4->paramList;
							     while(temp != NULL)
							     {
								 Ltable = LInstall(Ltable,temp->name,temp->type->name);
								 temp = temp->next;
							     }
							     $$=$2;free($1);
							}
	;

ParamList : ParamList ',' Param			   {struct Paramstruct* temp = $1->paramList;
						    while(temp != NULL && temp->next != NULL) temp = temp->next;
						    temp->next = $3->paramList;
						    $$=$1;}

	  | Param				   {$$=$1;}

	  | %empty				   {$$=makeNode(EMPTY_NODE,0,NULL,NULL,NULL,NULL,NULL);}
	  ;

Param : TypeName ID				   {struct Paramstruct* newNode = malloc(sizeof(struct Paramstruct));
						    newNode->name = $2->varname;
						    newNode->type = TLookup($1->varname);
						    newNode->next = NULL;
						    $$=makeNode(EMPTY_NODE,0,NULL,NULL,NULL,NULL,newNode);}

	;

MainBlock : INT MAIN '(' ')' '{' LDeclBlock Body '}'  {phase = 5;generateMainCode($7);generateGlobalVariableCode();} 
	    ;

LDeclBlock : DECL LDeclList ENDDECL
	   | DECL ENDDECL
	   | %empty
	   ;

LDeclList : LDeclList LDecl
	  | LDecl
	  ;

LDecl : TypeName LidList EOS          		   
	;

LidList : LidList ',' ID			   {Ltable=LInstall(Ltable,$3->varname,$0->varname);}
	| ID					   {Ltable=LInstall(Ltable,$1->varname,$0->varname);}
	;

Body : Slist					   {$$=$1;}
	;

Slist : Slist Stmt 	      {$$=makeNode(5,0,NULL,$1,$2,NULL,NULL);}
	   | Stmt	      {$$=$1;}
	   ;
Stmt : InputStmt 		{$$=$1;}
          | OutputStmt 		{$$=$1;}
          | AsgStmt		{$$=$1;}
	  | IfStmt	  	{$$=$1;}
	  | WhileStmt		{$$=$1;}
	  | BrkStmt		{$$=$1;}
	  | ContinueStmt	{$$=$1;}
	  | DowhileStmt		{$$=$1;}
	  | RetStmt		{$$=$1;}
	  | FreeStmt		{$$=$1;}
	  | DelStmt		{$$=$1;}
	  ;
InputStmt : READ '(' ID ')' EOS    {$3=makeNode(1,0,$3->varname,NULL,NULL,NULL,NULL);$$=makeNode(4,0,NULL,$3,NULL,NULL,NULL);}
	  | READ '(' Array1 ')' EOS {$$=makeNode(4,0,NULL,$3,NULL,NULL,NULL);}
	  | READ '(' Field ')' EOS  {//$3=makeNode(1,0,$3->varname,$3->left,NULL,NULL,NULL);
                                     $3->nodetype = FIELD_NODE;
                                     $3->type=getType($3->varname,$3->type,$3->class,$3->left);
				     if($3->type != TLookup("int") || $3->type != TLookup("str"))
				     {
					 printf("Error!\n");
				     }
				     $$=makeNode(4,0,NULL,$3,NULL,NULL,NULL);}
	       ;
OutputStmt : WRITE '(' expr ')' EOS {$$=makeNode(3,0,NULL,$3,NULL,NULL,NULL);}
	 	;
AsgStmt : ID '=' expr EOS {$1=makeNode(1,0,$1->varname,NULL,NULL,NULL,NULL);ch = malloc(1);*ch='=';
			   $$=makeNode(2,0,ch,$1,$3,NULL,NULL);}

	| Array1 '=' expr EOS {ch = malloc(1);*ch = '='; $$=makeNode(2,0,ch,$1,$3,NULL,NULL);}

	| '*' ID '=' expr EOS {$2=makeNode(1,0,$2->varname,NULL,NULL,NULL,NULL);
			       ch = malloc(1);*ch = '=';
			       $2->nodetype=PTR_NODE;
			       $$=makeNode(2,0,ch,$2,$4,NULL,NULL);}

	| ID '=' '&' ID EOS   {$1=makeNode(1,0,$1->varname,NULL,NULL,NULL,NULL);
			       $4=makeNode(1,0,$4->varname,NULL,NULL,NULL,NULL);
			       ch = malloc(1);*ch = '=';
			       $4->nodetype=ADD_NODE;$$=makeNode(2,0,ch,$1,$4,NULL,NULL);}

	| Field '=' expr EOS   {
				  $1->nodetype = FIELD_NODE;
	                          $1->type=getType($1->varname,$1->type,$1->class,$1->left);
				  ch = malloc(1);*ch = '=';
                                  $$=makeNode(2,0,ch,$1,$3,NULL,NULL);
			       }

	| ID '=' INIT '(' ')' EOS  {ch = malloc(1);*ch = '=';
				    $3 = makeNode(INIT_NODE,0,NULL,NULL,NULL,NULL,NULL);
				    $1 = makeNode(1,0,$1->varname,NULL,NULL,NULL,NULL);
				   $$=makeNode(2,0,ch,$1,$3,NULL,NULL);}

	| ID '=' ALLOC '(' ')' EOS {ch = malloc(1);*ch = '=';
				   $1 = makeNode(1,0,$1->varname,NULL,NULL,NULL,NULL);
				   $3 = makeNode(ALLOC_NODE,0,NULL,NULL,NULL,NULL,NULL);
                                   $$=makeNode(2,0,ch,$1,$3,NULL,NULL);}

	| ID '=' NEW '(' ID ')' EOS   {ch = malloc(1);*ch = '=';
                                       $1 = makeNode(1,0,$1->varname,NULL,NULL,NULL,NULL);
				       $3 = makeNode(NEW_NODE,0,NULL,$5,NULL,NULL,NULL);
				       $$ = makeNode(2,0,ch,$1,$3,NULL,NULL);}

	| Field '=' NEW '(' ID ')' EOS {$1->nodetype = FIELD_NODE;
                                        $1->type=getType($1->varname,$1->type,$1->class,$1->left);
					$3 = makeNode(NEW_NODE,0,NULL,$5,NULL,NULL,NULL);
                                        ch = malloc(1);*ch = '=';
                                        $$=makeNode(2,0,ch,$1,$3,NULL,NULL);
				       }
	     ;

IfStmt : IF '(' expr ')' THEN Slist ELSE Slist ENDIF EOS   {$$=makeNode(7,0,NULL,$3,$6,$8,NULL);}
	|IF '(' expr ')' THEN Slist ENDIF EOS		{$$=makeNode(6,0,NULL,$3,$6,NULL,NULL);}
	;
WhileStmt : WHILE '(' expr ')' DO Slist ENDWHILE EOS	{$$=makeNode(8,0,NULL,$3,$6,NULL,NULL);}
	;

BrkStmt : BREAK EOS {$$=makeNode(9,0,NULL,NULL,NULL,NULL,NULL);}
	 ;

ContinueStmt : CONTINUE EOS {$$=makeNode(10,0,NULL,NULL,NULL,NULL,NULL);}
	 ;

DowhileStmt : DO Slist WHILE '(' expr ')' EOS		{$$=makeNode(11,0,NULL,$2,$5,NULL,NULL);}
	     |REPEAT Slist UNTIL '(' expr ')' EOS	{$$=makeNode(11,0,NULL,$2,$5,NULL,NULL);}
	     ;
RetStmt : RETURN expr EOS {$$=makeNode(RET_NODE,0,NULL,$2,NULL,NULL,NULL);}
	  ;

FreeStmt : FREE '(' ID ')' EOS      {$3=makeNode(1,0,$3->varname,NULL,NULL,NULL,NULL);
				     $$=makeNode(FREE_NODE,0,NULL,$3,NULL,NULL,NULL);}
	;

DelStmt : DELETE '(' ID ')' EOS     {$3=makeNode(1,0,$3->varname,NULL,NULL,NULL,NULL);
				     $$=makeNode(DELETE_NODE,0,NULL,$3,NULL,NULL,NULL);}
	  ;

Array1 : ID '[' expr ']' 		{$$=makeNode(1,0,$1->varname,$3,NULL,NULL,NULL);$1=NULL;}
	| ID '[' expr ']' '[' expr ']'  {$$=makeNode(1,0,$1->varname,$3,$6,NULL,NULL);$1=NULL;}
	;

expr : expr '+' expr    {ch = malloc(1);*ch='+';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr '-' expr    {ch = malloc(1);*ch='-';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr '*' expr    {ch = malloc(1);*ch='*';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr '/' expr    {ch = malloc(1);*ch='/';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr '%' expr    {ch = malloc(1);*ch='%';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |'('expr')'	{$$=$2;}
      |NUM		{$$=$1;}
      |ID	 	{$1=makeNode(1,0,$1->varname,NULL,NULL,NULL,NULL);$$=$1;}
      |'*' ID 		{$2=makeNode(1,0,$2->varname,NULL,NULL,NULL,NULL);$2->nodetype=PTR_NODE;$$=$2;}
      |STRNODE		{$$=$1;}
      |Array1	        {$$=$1;}
      |Field		{$1->nodetype=FIELD_NODE;
			 $$=$1;
			 $$->type=getType($1->varname,$1->type,$1->class,$1->left);}
      |null		{$$=makeNode(NULL_NODE,0,NULL,NULL,NULL,NULL,NULL);}
      |FieldFunction    {$$=$1;}
      |ID '(' ArgList ')' {$$ = makeNode(FUNC_NODE,0,$1->varname,$3,NULL,NULL,NULL);$1=NULL;}
      |expr LT expr     {ch = malloc(1);*ch='<';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr GT expr     {ch = malloc(1);*ch='>';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr LE expr     {ch = malloc(2);ch[0]='<';ch[1]= '=';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr GE expr     {ch = malloc(2);ch[0]='>';ch[1]= '=';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr EQ expr     {ch = malloc(2);ch[0]='=';ch[1]= '=';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr NE expr     {ch = malloc(2);ch[0]='!';ch[1]= '=';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr AND expr    {ch = malloc(2);ch[0]='&';ch[1]= '&';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
      |expr OR expr    {ch = malloc(2);ch[0]='|';ch[1]= '|';$$=makeNode(2,0,ch,$1,$3,NULL,NULL);}
     ;

ArgList : expr ',' ArgList	{$1->third=$3;$$=$1;}
	| expr		 	{$$=$1;}
	| %empty		{$$=NULL;}
	;

Field : IDfield		        {$$=makeNode(1,0,$1->varname,$1->left,NULL,NULL,NULL);}
      | SELF '.' ID		{$1=makeNode(SELF_NODE,0,"self",$3,NULL,NULL,NULL);
				 $$=$1;}
      | SELF '.' IDfield 	{$$ = makeNode(SELF_NODE,0,"self",$3,NULL,NULL,NULL);}
      ;

FieldFunction : SELF '.' ID '(' ArgList ')' 		{$$ = makeNode(SELF_NODE,0,"self",$3,$5,NULL,NULL);
							 $$->nodetype = FIELDFUNC_NODE;
							 $$->type = getFuncType("self",$$->class,$3);} 
	      | SELF '.' IDfield '('ArgList ')'		{$$ = makeNode(SELF_NODE,0,"self",$3,$5,NULL,NULL);
                                                         $$->nodetype = FIELDFUNC_NODE;
                                                         $$->type = getFuncType("self",$$->class,$3);}

	      | ID '.' ID '(' ArgList ')'		{$$ = makeNode(1,0,$1->varname,$3,$5,NULL,NULL);
                                                         $$->nodetype = FIELDFUNC_NODE;
							 $$->type = getFuncType($1->varname,$$->class,$3);}

	      | ID '.' IDfield '(' ArgList ')'		{$$ = makeNode(1,0,$1->varname,$3,$5,NULL,NULL);
                                                         $$->nodetype = FIELDFUNC_NODE;
                                                         $$->type = getFuncType($1->varname,$$->class,$3);}
	      ;

IDfield : ID '.' IDfield	{$1->left = $3;$$=$1;}
	| ID '.' ID             {$1->left = $3;$3->left=NULL;$$=$1;}
%%

int yyerror()
{
    printf("LINE %d : Syntax error\n",line);
    return 0;
}

int main(int argc,char* argv[])
{
    FILE* fp = fopen(argv[1],"r");
    yyin = fp;
    yyparse();
    return 1;
}
