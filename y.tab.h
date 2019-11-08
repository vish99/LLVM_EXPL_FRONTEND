/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ENDCLASS = 259,
    DECL = 260,
    ENDDECL = 261,
    TYPE = 262,
    ENDTYPE = 263,
    INT = 264,
    STR = 265,
    null = 266,
    STRNODE = 267,
    MAIN = 268,
    RETURN = 269,
    INIT = 270,
    ALLOC = 271,
    FREE = 272,
    NEW = 273,
    DELETE = 274,
    SELF = 275,
    EXTENDS = 276,
    NUM = 278,
    EOS = 279,
    END_OF_FILE = 280,
    ID = 281,
    READ = 282,
    WRITE = 283,
    END = 284,
    IF = 285,
    ENDIF = 286,
    WHILE = 287,
    ENDWHILE = 288,
    THEN = 289,
    DO = 290,
    ELSE = 291,
    GT = 292,
    LT = 293,
    GE = 294,
    LE = 295,
    EQ = 296,
    NE = 297,
    AND = 298,
    OR = 299,
    BREAK = 300,
    CONTINUE = 301,
    REPEAT = 302,
    UNTIL = 303
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ENDCLASS 259
#define DECL 260
#define ENDDECL 261
#define TYPE 262
#define ENDTYPE 263
#define INT 264
#define STR 265
#define null 266
#define STRNODE 267
#define MAIN 268
#define RETURN 269
#define INIT 270
#define ALLOC 271
#define FREE 272
#define NEW 273
#define DELETE 274
#define SELF 275
#define EXTENDS 276
#define BEGIN 277
#define NUM 278
#define EOS 279
#define END_OF_FILE 280
#define ID 281
#define READ 282
#define WRITE 283
#define END 284
#define IF 285
#define ENDIF 286
#define WHILE 287
#define ENDWHILE 288
#define THEN 289
#define DO 290
#define ELSE 291
#define GT 292
#define LT 293
#define GE 294
#define LE 295
#define EQ 296
#define NE 297
#define AND 298
#define OR 299
#define BREAK 300
#define CONTINUE 301
#define REPEAT 302
#define UNTIL 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

#define YYSTYPE struct node*
extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
