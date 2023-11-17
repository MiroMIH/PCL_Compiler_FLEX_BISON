%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syn.tab.h" 
#include "TSM.h"

extern YYSTYPE yylval;
int line=1;
int column=0;
%}
pfloat [+-]?[0-9][0-9]*[.][1-9][0-9]*  
pint [+-]?[0-9][0-9]*   
IDF [a-zA-Z]([a-z]|[0-9])*
COMMENTAIRE (%%.*\n) 
%%
{COMMENTAIRE} {column=1;line++;}
VAR    {
    insertTM(yytext);
    column=column+yyleng;return MC_VAR;}
CODE  {
    insertTM(yytext);
    column=column+yyleng;return MC_CODE;}
INTEGER       {
    insertTM(yytext);
    column=column+yyleng;return MC_INTEGER;}
FLOAT       {
    insertTM(yytext);
    column=column+yyleng;return MC_FLOAT;}
CONST      {
    insertTM(yytext);
    column=column+yyleng;return MC_CONST;}
IF        {
    insertTM(yytext);
    column=column+yyleng;return MC_IF;}
ELSE      {
    insertTM(yytext);
    column=column+yyleng; return MC_ELSE;}
WHILE      {
    insertTM(yytext);
    column=column+yyleng;return MCWHILE;}
FOR      {
    insertTM(yytext);
    column=column+yyleng;return MC_FOR;}
STRUCT      {
    insertTM(yytext);
    column=column+yyleng;return MC_STRUCT;}    
"+"         {
    insertTS(yytext,"plus");
    column=column+yyleng;return TADD;}
"-"         {
    insertTS(yytext,"moins");
    column=column+yyleng;return TSUB;}
"*"         {
    insertTS(yytext,"produit");
    column=column+yyleng;return TMUL;}
"/"         {
    insertTS(yytext,"division");
    column=column+yyleng;return TDIV;}
"{"         {
    insertTS(yytext,"accolade gauche");
    column=column+yyleng;return LEFTACC;}
"}"         {
    insertTS(yytext,"accolade droite");
    column=column+yyleng;return RIGHTACC;}
";"         {
    insertTS(yytext,"point virgule");
    column=column+yyleng;return pvg;}
","         {
    insertTS(yytext,"virgule");
    column=column+yyleng; return vrg;}
":"         {
    insertTS(yytext,"deux points");
    column=column+yyleng; return dd;}
">"         {
    insertTS(yytext,"superieure");
    column=column+yyleng;return TSUP;}
"<"         {
    insertTS(yytext,"inferieure");
    column=column+yyleng;return TINF;}
">="        {
    insertTS(yytext,"superieure ou egale");
    column=column+yyleng;return TSUPEQ;}
"<="        {
    insertTS(yytext,"inferieure ou egale");
    column=column+yyleng;return TINFEQ;}
"=="        {
    insertTS(yytext,"egale");
    column=column+yyleng;return TEQL;}
"!="        {
    insertTS(yytext,"n'est pas égale");
    column=column+yyleng;return TNEQL;}
"("         {
    insertTS(yytext,"parenthese gauche");
    column=column+yyleng;return TPARLEFT;}
")"         {
    insertTS(yytext,"parenthese droite");
    column=column+yyleng;return TPARRIGHT;}
"="         {
    insertTS(yytext,"affectation");
    column=column+yyleng;return TAFF;}
"||"         {
    insertTS(yytext,"OR");
    column=column+yyleng;return TOR;}
"&&"         {
    insertTS(yytext,"AND");
    column=column+yyleng;return TAND;}
"!"         {
    insertTS(yytext,"NOT");
    column=column+yyleng;return TNOT;}
"["         {
    insertTS(yytext,"crochet gauche");
    column=column+yyleng;return TRBRACKET;}
"]"         {
    insertTS(yytext,"crochet droit");
    column=column+yyleng;return TLBRACKET;}
"."         {
    insertTS(yytext,"point");
    column=column+yyleng;return TDOT;}
{pint}      {
    column=column+yyleng;
            if ((atoi(yytext)>= -32768) && (atoi(yytext)<=32767))
                {
					yylval.entier = atoi(yytext);
					return var_int;
				}
		  	else {
					printf("Erreur lexicale (ligne : %d , colonne: %d)", line, column);
					printf("LA VALEUR N'EST PAS ENTRE  -32768 -- 32767 \n");
                    return var_int;
				}          
            }
            
{pfloat}    {
    column=column+yyleng;
    yylval.FLOAT=atof(yytext);
    return var_float;}

[ \t]       {
    column=column+yyleng;}

\n          {
    line++; column=0;}
{IDF}       {
    column=column+yyleng;
    if(yyleng<=8)
        {
            yylval.str=strdup(yytext);
            return idf;
        }
    else 
    {
        printf ("ERROR LEXICAL: IDF DEPACE LA LONGEUR 8 : %s a la ligne %d et a la colonne %d \n", yytext, line, column);
    }
    }

.  {printf("Erreur lexical à la ligne %d et colonne %d  cause = %s \n",line,column,yytext);}
%%

int yywrap()
{

return 0;
}
