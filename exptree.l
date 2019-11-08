
%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"y.tab.h"
    int numb;
    struct node{
        int nodetype;               //type of internal node Read/Write/Op
        int val;                    //Value incase of a NUM node/offset in case of an array
        char* varname;              //Var name
        int type;                   //type of variable
        struct Gsymbol *Gentry;
        struct node* left;
        struct node* right;
        struct node* third;
    };
    struct node* makeNode(int nodetype,int val,char* name,struct node* l,struct node* r,struct node* t);
    char* ch;
    int line = 1;
%}

%%

[0-9]+ {numb=atoi(yytext);yylval=makeNode(0,numb,NULL,NULL,NULL,NULL);return NUM;}
"+" {return *yytext;}
"-" {return *yytext;}
"*" {return *yytext;}
"/" {return *yytext;}
"%" {return *yytext;}
")" {return *yytext;}
"(" {return *yytext;}
"{" {return *yytext;}
"}" {return *yytext;}
"<" {return LT;}
">" {return GT;}
"<=" {return LE;}
">=" {return GE;}
"==" {return EQ;}
"!=" {return NE;}
"=" {return *yytext;}
"." {return *yytext;}
";" {return EOS;}
"," {return *yytext;}
"[" {return *yytext;}
"]" {return *yytext;}
"&" {return *yytext;}
[\"]([a-zA-Z0-9(). ]*)[\"] {ch=malloc(30);strcpy(ch,yytext);yylval=makeNode(12,0,ch,NULL,NULL,NULL);return STRNODE;}
"self" {return SELF;}
"extends" {return EXTENDS;}
"new"  {return NEW;}
"delete" {return DELETE;}
"int" {return INT;}
"str" {return STR;}
"null" {return null;}
"NULL" {return null;}
"string" {return STR;}
"begin" {return BEGIN;}
"end"   {return END;}
"class" {return CLASS;}
"endclass" {return ENDCLASS;}
"type"  {return TYPE;}
"endtype" {return ENDTYPE;}
"decl"  {return DECL;}
"enddecl" {return ENDDECL;}
"main"   {return MAIN;}
"read"  {return READ;}
"write" {return WRITE;}
"if"    {return IF;}
"then"  {return THEN;}
"else"  {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do"    {return DO;}
"endwhile" {return ENDWHILE;}
"initialize" {return INIT;}
"alloc"	{return ALLOC;}
"free"  {return FREE;}
"break"	{return BREAK;}
"continue" {return CONTINUE;}
"repeat" {return REPEAT;}
"until"  {return UNTIL;}
"return" {return RETURN;}
[a-zA-Z_][a-zA-Z0-9_]* {ch = malloc(20);strcpy(ch,yytext);
		      struct node* newNode = malloc(sizeof(struct node));
		      newNode->varname = ch;
		      newNode->nodetype = 1;
		      newNode->left = NULL;newNode->right=NULL;newNode->third=NULL;
		      //yylval=makeNode(1,0,ch,NULL,NULL,NULL);
		      yylval=newNode;
		      return ID;}
<<EOF>> {return END_OF_FILE;}
"/*"[a-zA-Z0-9{}\n ]*"*/"		{;}
"\n"    {line++;}
.	{;}
%%

int yywrap()
{
   return 1;
}
