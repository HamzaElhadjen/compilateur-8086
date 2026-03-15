
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_BeginProject = 258,
     mc_EndProject = 259,
     mc_Setup = 260,
     mc_Run = 261,
     mc_define = 262,
     mc_const = 263,
     mc_if = 264,
     mc_then = 265,
     mc_else = 266,
     mc_endIf = 267,
     mc_loopwhile = 268,
     mc_endloop = 269,
     mc_for = 270,
     mc_in = 271,
     mc_to = 272,
     mc_endfor = 273,
     mc_out = 274,
     mc_AND = 275,
     mc_OR = 276,
     mc_NON = 277,
     PVG = 278,
     DPT = 279,
     PIPE = 280,
     ACCO = 281,
     ACCF = 282,
     CROV = 283,
     CRMF = 284,
     PARO = 285,
     PARF = 286,
     AFF = 287,
     PLUS = 288,
     MINS = 289,
     MULT = 290,
     DIV = 291,
     LEQ = 292,
     GEQ = 293,
     LT = 294,
     GT = 295,
     EQ = 296,
     NEQ = 297,
     EGAL = 298,
     IDF = 299,
     mc_integer = 300,
     mc_float = 301,
     CHAINE = 302,
     CST_INT = 303,
     CST_FLOAT = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 12 "syntax.y"

    int entier;
    float numvrg;
    char* str;
    struct { char* ids[50]; int count; } idlist;
    struct { char value[50]; char type[10]; } val;



/* Line 1676 of yacc.c  */
#line 111 "syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


