struct node{
    int nodetype;		//type of internal node Read/Write/Op
    int val;			//Value incase of a NUM node/offset in case of an array
    char* varname;		//Var name
    struct Typetable* type;	//type of variable
    struct ClassTable* class;
    struct Gsymbol *Gentry;
    struct Lsymbol *Lentry;
    struct node* left;		
    struct node* right;
    struct node* third;
    struct Paramstruct* paramList;
};

struct Gsymbol{
    char* name;			//name of the identifier
    struct Typetable* type;	//type of the identifier
    struct ClassTable* class;
    int size;			//size
    int binding;		//address allocated
    int rowSize;		//Number of rows in case of a 2D array
    struct Paramstruct *paramList;
    int flabel;   
    struct Gsymbol *next;
};

struct Lsymbol{
    char* name;
    struct Typetable* type;
    int binding;
    struct Lsymbol* next;
};

struct Paramstruct{
    char* name;
    struct Typetable* type;
    struct Paramstruct* next;
};

struct Typetable{
    char* name;
    int size;
    struct Fieldlist *fields;
    struct Typetable* next;
};

struct Fieldlist{
    char* name;
    int size;								//Used with classes for nested class declarations
    int fieldIndex;
    struct Typetable* type;
    struct ClassTable* Ctype;
    struct Fieldlist* next;
};

struct ClassTable{
    char* name;
    struct Fieldlist* fields;
    struct Memberfunclist* Vfuncptr;
    struct ClassTable* parentClass;
    int class_index;
    int fieldCount;
    int methodCount;
    struct ClassTable* next;
};

struct Memberfunclist{
    char* name;
    struct Typetable *type;
    struct Paramstruct* paramList;
    int funcPosition;
    int flabel;
    struct Memberfunclist* next;
};

struct StringNames{                                     //structure to store strings which should be allocated in LLVM
    char* name;
    int index;
    struct StringNames* next;
};

#define NUM_NODE       0
#define VAR_NODE       1
#define OP_NODE        2
#define WRITE_NODE     3
#define READ_NODE      4
#define EMPTY_NODE     5
#define IF_NODE        6
#define IFELSE_NODE    7
#define WHILE_NODE     8
#define BRK_NODE       9
#define CON_NODE       10
#define DOWHL_NODE     11
#define STR_NODE       12
#define PTR_NODE       13
#define ADD_NODE       14
#define FUNC_NODE      15
#define RET_NODE       16
#define FIELD_NODE     17
#define INIT_NODE      18
#define ALLOC_NODE     19
#define FREE_NODE      20
#define NULL_NODE      21
#define NEW_NODE       22
#define DELETE_NODE    23
#define SELF_NODE      24
#define FIELDFUNC_NODE 25

#define reg_index int

struct node* makeNode(int nodetype,int val,char* name,struct node* l,struct node* r,struct node* t,struct Paramstruct* paramList);

void generateInitCode();

void generateFuncCode(struct node* tree,char* name);

void generateMainCode(struct node* tree);

struct Lsymbol* generateArgsCode(struct node* tree);

reg_index getReg();

void freeReg();

int getLabel();

reg_index codegen(struct node* tree,FILE* target_file);

struct Lsymbol* LInstall(struct Lsymbol* head,char* name,char* type);

void Install(struct node *varNode, char* type, int size,int rowSize,struct Paramstruct* paramList);

void checkParam(char* name,struct Paramstruct* paramList);

void TypeTableInitialize();

void TInstall(char* name);

void TInstallFields(char* name,int size,struct Fieldlist* Fields);

struct Typetable* TLookup(char* name);

struct Fieldlist* FInstall(struct Fieldlist* Fields,char* name,char* typename,int* fieldSize);

struct Typetable* getType(char* name,struct Typetable* type,struct ClassTable* class,struct node* Field);

struct Typetable* getFuncType(char* name,struct ClassTable* class,struct node* Field);

int checkArgs(struct node* args,struct Paramstruct* paramList,char* funcName);

struct ClassTable* CInstall(char* name,char* parentName);

struct ClassTable* CLookup(char *name);

void ClassFInstall(struct ClassTable* class,char* type,char* name);

void ClassMInstall(struct ClassTable* class,char* name,char* type,struct Paramstruct* paramList);

struct StringNames* InstallString(struct StringNames* S,char* name);

struct StringNames* StrLookup(struct StringNames* S,char* name);

struct Memberfunclist* Class_MLookup(struct ClassTable* class,char* name);

struct Fieldlist* Class_FLookup(struct ClassTable* class,char* name);

int str_len(char* str);
