This is a front-end for LLVM Framework to support EXPL(Experimental Language) as given in https://silcnitc.github.io/expl.html. This front-end supports integer and string data types, user-defined data types, global and local variables, single and multi-dimensional arrays, dynamic memory allocation(with max size of 32 as specified by EXPL) as of now.


TO COMPILE:
> lex exptree.l
> yacc exptree.y
> gcc lex.yy.c y.tab.c -o expl
This will build an executable file "expl"

TO EXECUTE:
> ./expl "file-name"
