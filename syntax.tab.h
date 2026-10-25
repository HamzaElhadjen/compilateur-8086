/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    kw_begin_project = 258,        /* kw_begin_project  */
    kw_end_project = 259,          /* kw_end_project  */
    kw_setup = 260,                /* kw_setup  */
    kw_run = 261,                  /* kw_run  */
    kw_define = 262,               /* kw_define  */
    kw_const = 263,                /* kw_const  */
    kw_if = 264,                   /* kw_if  */
    kw_then = 265,                 /* kw_then  */
    kw_else = 266,                 /* kw_else  */
    kw_end_if = 267,               /* kw_end_if  */
    kw_loop_while = 268,           /* kw_loop_while  */
    kw_end_loop = 269,             /* kw_end_loop  */
    kw_for = 270,                  /* kw_for  */
    kw_in = 271,                   /* kw_in  */
    kw_to = 272,                   /* kw_to  */
    kw_end_for = 273,              /* kw_end_for  */
    kw_out = 274,                  /* kw_out  */
    kw_input = 275,                /* kw_input  */
    kw_and = 276,                  /* kw_and  */
    kw_or = 277,                   /* kw_or  */
    kw_not = 278,                  /* kw_not  */
    assign_arrow = 279,            /* assign_arrow  */
    plus = 280,                    /* plus  */
    minus = 281,                   /* minus  */
    multiply = 282,                /* multiply  */
    divide = 283,                  /* divide  */
    less_equal = 284,              /* less_equal  */
    greater_equal = 285,           /* greater_equal  */
    less_than = 286,               /* less_than  */
    greater_than = 287,            /* greater_than  */
    equal_equal = 288,             /* equal_equal  */
    not_equal = 289,               /* not_equal  */
    equal = 290,                   /* equal  */
    semicolon = 291,               /* semicolon  */
    colon = 292,                   /* colon  */
    comma = 293,                   /* comma  */
    pipe = 294,                    /* pipe  */
    lbrace = 295,                  /* lbrace  */
    rbrace = 296,                  /* rbrace  */
    lbracket = 297,                /* lbracket  */
    rbracket = 298,                /* rbracket  */
    lparen = 299,                  /* lparen  */
    rparen = 300,                  /* rparen  */
    identifier = 301,              /* identifier  */
    kw_integer = 302,              /* kw_integer  */
    kw_float = 303,                /* kw_float  */
    string_literal = 304,          /* string_literal  */
    int_literal = 305,             /* int_literal  */
    float_literal = 306            /* float_literal  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "syntax.y"

    int entier;
    float numvrg;
    char* str;   
    struct { char* ids[50]; int count; } idlist;
    struct { 
        char value[50];   
        char type[10];    
        char result[20];  
    } val;
    int num;              /* pour stocker qc a un instant donne */

#line 128 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
