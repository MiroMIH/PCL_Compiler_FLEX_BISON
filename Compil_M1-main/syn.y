%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TS.h"
#include "quads.h"
#include "TSM.h"

extern FILE* yyin ;


int qc = 0;
char tmp[20], tmp2[20], tmp3[20], tmp4[20], tabName[20];
/* IF */
int deb_if;
int fin_if;
int deb_else;
int fin_else;
/* WHILE */
int deb_while;
int fin_while;
/* FOR */
int deb_for;
int fin_for;

//save operateur comparaison
char opcomp[100];


extern int line;
extern int column;
int saveType;
int yyparse();
int yylex();
int yyerror(char *s); 
  
int t = -1;
int j;
%}


%union
{
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
}
%token LEFTACC RIGHTACC pvg vrg MC_VAR MC_CODE MC_INTEGER MCWHILE MC_FLOAT MC_CONST

%token TADD TSUB TMUL TDIV  TAFF TSUP TINF TSUPEQ  TEQL TNEQL MC_IF MC_ELSE TPARLEFT TPARRIGHT TDOT
%token TOR TAND TNOT TRBRACKET TLBRACKET
%token MC_FOR dd MC_STRUCT

%left TSUP TINF TSUPEQ TINFEQ TEQL TNEQL
%left TADD TSUB
%left TMUL TDIV

//%type <entier>EXP

%type <exp_type>EXP

%token <str> idf
%token <entier> var_int
%token <FLOAT> var_float

%% 
S:  idf LEFTACC MC_VAR  LEFTACC DECLARATION RIGHTACC MC_CODE LEFTACC PARTINST RIGHTACC RIGHTACC {printf ("programme syntaxiquement juste \n");YYACCEPT ;}
;
DECLARATION: TYPE LISTIDF pvg DECLARATION  | MC_CONST idf TAFF EXP pvg DECLARATION {insert($2,1,0); insertType($2,1);}
|  TYPE idf TRBRACKET {insert($2,0,1); insertType($2,saveType);} var_int TLBRACKET pvg DECLARATION 
|   MC_STRUCT LEFTACC DECLARATION RIGHTACC idf {insertTsT($5);} pvg DECLARATION
|   MC_STRUCT {saveType = 3;} idf LISTIDF pvg DECLARATION{if(rechercherTsT($3)==0) printf("Erreur sémantique : La structure n'est pas declarée \n");}
|
;
LISTIDF: idf  vrg LISTIDF   {insert($1,0,0); insertType($1,saveType);}
|         idf              {insert($1,0,0); insertType($1,saveType);}
;
PARTINST:INST  PARTINST
|        INST 
|
;
INST:INST_IF
|    INST_AFF pvg
|    INST_WHILE
|    INST_FOR
;
INST_IF:INST_IF_1 MC_ELSE LEFTACC PARTINST RIGHTACC {
    fin_else = qc; 
    //add_quad(int num_quad, int colon_quad, char val[])
    char str[20];
    sprintf(str, "%d", fin_else);
    add_quad(fin_if,1,str);
}
;
INST_IF_1:INST_IF_2 LEFTACC  PARTINST RIGHTACC {
    fin_if = qc;
    quadr("BR","fin_else","",""); 
    /*deb else*/ 
    deb_else = qc; 
    //add_quad(int num_quad, int colon_quad, char val[])
    char str[20];
    sprintf(str, "%d", deb_else);
    add_quad(deb_if,1,str);
    }
;
INST_IF_2:MC_IF TPARLEFT COND_OR TPARRIGHT {
    deb_if = qc;
    quadr(opcomp,"","tmp_cond1","tmp_cond2");
    }
;
INST_AFF: idf TAFF EXP {if(lookup($1)==NULL) printf("Variable %s non declarée affectation\n",$1); 

if(lookup($1)!=NULL) {
    updateVal($1,$3.val);

    if(lookup($1)->isConst ==1)
    {
        printf("ERREUR SEMANTIQUE : affectation à une constante %s\n",$1);
    }    
}
j = 0;
    if($3.isComplex ==1)
    {
        quadr(":=",getTemp(),"",$1);    
    }else {
        if($3.isInt==1)
        {
            char str1[10];
            sprintf(str1, "%d", $3.intValue);
            quadr(":=",str1,"",$1);    
        }else {
            quadr(":=",$3.strValue,"",$1);    
        }
    }
}
|   idf TRBRACKET var_int TLBRACKET TAFF EXP
|   idf TDOT idf TAFF EXP
;
INST_WHILE: INST_WHILE_COND LEFTACC PARTINST RIGHTACC {
    fin_while = qc;
    //fin_while++;
    char str[20];
    sprintf(str, "%d", fin_while);
    char str2[20];
    sprintf(str2, "%d", deb_while);
    quadr("BR",str2,"","");
    fin_while++; 
    sprintf(str, "%d", fin_while);
    add_quad(deb_while,1,str);
    //add_quad(fin_while,1,str);

}
;
INST_WHILE_COND: MCWHILE TPARLEFT COND_OR TPARRIGHT {
    deb_while = qc;
    quadr(opcomp,"","tmp_cond1","tmp_cond2");
    }
;
INST_FOR:INST_FOR_INDICE LEFTACC PARTINST RIGHTACC {
     fin_for = qc;
    //fin_while++;
    char str[20];
    sprintf(str, "%d", fin_for);
    char str2[20];
    sprintf(str2, "%d", deb_for);
    quadr("BR",str2,"","");
    fin_for++;
    sprintf(str, "%d", fin_for);
    add_quad(deb_for,1,str);
    //add_quad(fin_while,1,str);
}
;
INST_FOR_INDICE:MC_FOR TPARLEFT idf dd EXP dd EXP dd EXP  TPARRIGHT {
    if(lookup($3)==NULL) printf("Variable %s non declarée boucle for \n",$3);
    deb_for = qc;
    quadr(opcomp,"","tmp_cond1","tmp_cond2");
}
;
TYPE: MC_INTEGER {saveType = 1;}| MC_FLOAT {saveType = 2;}
;
EXP: EXP TADD EXP{ 
    char str1[10];
    char str2[10];
    $$.isComplex = 1;

    if($1.isInt)
    {
        sprintf(str1, "%d", $1.intValue);
        $$.val = $1.val;
            }else {
        strcpy(str1,$1.strValue);
    }
     if($3.isInt)
    {
        sprintf(str2, "%d", $3.intValue);
        $$.val = $$.val + $3.val;
        }else {
        strcpy(str2,$3.strValue);
    }
     char str3[100] = "t";
     char str4[20];
   
    sprintf(str4, "%d", t);
    strcat(str3, str4);
        t++;
    if(j==0)
    {
        quadr("+",str1,str2,getTemp());
    }else {
        quadr("+",getTempMinus(),str2,getTemp());
    }
    j++;
    }
|    EXP TSUB EXP { 
    char str1[10];
    char str2[10];
    $$.isComplex = 1;

    if($1.isInt)
    {
        sprintf(str1, "%d", $1.intValue);
        $$.val = $1.val;
            }else {
        strcpy(str1,$1.strValue);
    }
     if($3.isInt)
    {
        sprintf(str2, "%d", $3.intValue);
        $$.val = $$.val - $3.val;
        }else {
        strcpy(str2,$3.strValue);
    }
     char str3[100] = "t";
     char str4[20];
   
    sprintf(str4, "%d", t);
    strcat(str3, str4);
        t++;
    if(j==0)
    {
        quadr("-",str1,str2,getTemp());
    }else {
        quadr("-",getTempMinus(),str2,getTemp());
    }
    j++;
    }
|    EXP TMUL EXP { 
    char str1[10];
    char str2[10];
    $$.isComplex = 1;

    if($1.isInt)
    {
        sprintf(str1, "%d", $1.intValue);
        $$.val = $1.val;
            }else {
        strcpy(str1,$1.strValue);
    }
     if($3.isInt)
    {
        sprintf(str2, "%d", $3.intValue);
        $$.val = $$.val * $3.val;
        }else {
        strcpy(str2,$3.strValue);
    }
     char str3[100] = "t";
     char str4[20];
   
    sprintf(str4, "%d", t);
    strcat(str3, str4);
        t++;
    if(j==0)
    {
        quadr("*",str1,str2,getTemp());
    }else {
        quadr("*",getTempMinus(),str2,getTemp());
    }
    j++;
    }
|    EXP TDIV EXP { 
    char str1[10];
    char str2[10];
    $$.isComplex = 1;
    if($3.isInt == 1 && $3.val == 0)
    {
        printf("Erreur sémantique : Division sur 0\n");
        printf("%d",$3.val);
    }
    if($3.isInt == 0 && lookup($3.strValue) != NULL)
    {
        if(lookup($3.strValue)->value == 0)
        {
            printf("Erreur sémantique : Division sur 0\n");
        }
    }

    if($1.isInt)
    {
        sprintf(str1, "%d", $1.intValue);
        $$.val = $1.val;
            }else {
        strcpy(str1,$1.strValue);
    }
     if($3.isInt)
    {
        sprintf(str2, "%d", $3.intValue);
        if($3.val != 0)
        {
            $$.val = $$.val / $3.val;
        }
        }else {
        strcpy(str2,$3.strValue);
    }
     char str3[100] = "t";
     char str4[20];
   
    sprintf(str4, "%d", t);
    strcat(str3, str4);
        t++;
    if(j==0)
    {
        quadr("/",str1,str2,getTemp());
    }else {
        quadr("/",getTempMinus(),str2,getTemp());
    }
    j++;
    }
|    TPARLEFT EXP TPARRIGHT { $$ = $2; }
|    idf 
{if(lookup($1)==NULL) printf("Variable %s non declarée expression \n",$1); 
{            $$.strValue = $1;  $$.isInt = 0; $$.isComplex = 0;}}
|    var_int {    $$.intValue = $1; $$.isInt = 1; $$.val = $1; $$.isComplex = 0; }
|    var_float {    $$.intValue = $1; $$.isInt = 1;  $$.val = $1; $$.isComplex = 0;}
|   idf TRBRACKET var_int TLBRACKET {$$.intValue = atoi($1); $$.isInt = 1;  $$.val = atoi($1); $$.isComplex = 0;}
|   idf TDOT idf {$$.intValue = atoi($1); $$.isInt = 1;  $$.val = atoi($1); $$.isComplex = 0;}
;
COND_OR: COND_OR TOR COND_AND
|       COND_AND
;
COND_AND:COND_AND TAND COND_NOT
|       COND_NOT
;
COND_NOT:TNOT COND_EXP
|       COND_EXP
;
COND_EXP:EXP_COMP
;
EXP_COMP: EXP_COMP TADD EXP_COMP 
|         EXP_COMP TSUB EXP_COMP 
|         EXP_COMP TMUL EXP_COMP 
|         EXP_COMP TDIV EXP_COMP 
|         EXP_COMP TSUP EXP_COMP {
    char str[] = "BG";
    strcpy(opcomp,str);
    }
|         EXP_COMP TINF EXP_COMP {
    
    char str[] = "BL";
    strcpy(opcomp,str);
    
}
|         EXP_COMP TINFEQ EXP_COMP {
    
    char str[] = "BLE";
    strcpy(opcomp,str);
    
}
|         EXP_COMP TSUPEQ EXP_COMP {
    char str[] = "BGE";
    strcpy(opcomp,str);
    }
|         EXP_COMP TEQL EXP_COMP 
 {
    char str[] = "BE";
    strcpy(opcomp,str);
    }
|         EXP_COMP TNEQL EXP_COMP 
{
    char str[] = "BNE";
    strcpy(opcomp,str);
    }
|         idf {if(lookup($1)==NULL) printf("Variable %s non declarée expression comp\n",$1);}
|         var_int
|         var_float
|         idf TRBRACKET var_int TLBRACKET
|         idf TDOT idf
;
%%
int yyerror(char* msg)
{printf("%s ligne %d et colonne %d",msg,line,column);
return 0;
}
int main()  {    

    /*printf("%d\n", lookup("x"));
    printf("%d\n", lookup("y"));
    printf("%d\n", lookup("z"));
    printf("%d\n", lookup("w")); // should return -1*/
    //print_symbol_table();
    yyin=fopen("example.txt","r");  
    yyparse();  
    afficherTS(); // Afficher la table des séparateurs
    afficherTM(); // Afficher la table des mots clés
    afficher(); // Afficher la table des symboles

    afficher_qdr(); //Afficher les quadruplets

    Propagation_de_expression();
    elimination_expression_commune();

    afficher_qdr_opti();
    generateCodeObjet();

 
return 0;  
} 
