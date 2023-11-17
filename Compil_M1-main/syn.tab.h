/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
     LEFTACC = 258,
     RIGHTACC = 259,
     pvg = 260,
     vrg = 261,
     MC_VAR = 262,
     MC_CODE = 263,
     MC_INTEGER = 264,
     MCWHILE = 265,
     MC_FLOAT = 266,
     MC_CONST = 267,
     TADD = 268,
     TSUB = 269,
     TMUL = 270,
     TDIV = 271,
     TAFF = 272,
     TSUP = 273,
     TINF = 274,
     TSUPEQ = 275,
     TEQL = 276,
     TNEQL = 277,
     MC_IF = 278,
     MC_ELSE = 279,
     TPARLEFT = 280,
     TPARRIGHT = 281,
     TDOT = 282,
     TOR = 283,
     TAND = 284,
     TNOT = 285,
     TRBRACKET = 286,
     TLBRACKET = 287,
     MC_FOR = 288,
     dd = 289,
     MC_STRUCT = 290,
     TINFEQ = 291,
     idf = 292,
     var_int = 293,
     var_float = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 43 "syn.y"

    int entier;
    float FLOAT;
    char* str;
    struct {
		int intValue;
		char* strValue;
        int isInt;
        int val;
        int isComplex;
	} exp_type;



/* Line 1685 of yacc.c  */
#line 105 "syn.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


