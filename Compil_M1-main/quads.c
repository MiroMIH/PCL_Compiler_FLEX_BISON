#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"

typedef struct quadruple {
  char oper[100];
  char op1[100];
  char op2[100];
  char res[100];
} qdr;

qdr quad[1000];

extern int qc;
extern int t;

void quadr(char *opr, char *op1, char *op2, char *res) {
  strcpy(quad[qc].oper, opr);
  strcpy(quad[qc].op1, op1);
  strcpy(quad[qc].op2, op2);
  strcpy(quad[qc].res, res);
  qc++;
}

void add_quad(int num_quad, int colon_quad, char val[]) {
  if (colon_quad == 0)
    strcpy(quad[num_quad].oper, val);
  else if (colon_quad == 1)
    strcpy(quad[num_quad].op1, val);
  else if (colon_quad == 2)
    strcpy(quad[num_quad].op2, val);
  else if (colon_quad == 3)
    strcpy(quad[num_quad].res, val);
}

void afficher_qdr() {
  printf("*********************LesQuadruplets***********************\n");
  int i;
  for (i = 0; i < qc; i++) {
    printf("\n %d - ( %s , %s , %s , %s )", i, quad[i].oper, quad[i].op1,
           quad[i].op2, quad[i].res);
    printf("\n---------------------------------------------------\n");
  }
}

char* getTemp() {
    char str3[100] = "t";
    char str4[20];
    sprintf(str4, "%d", t);
    strcat(str3, str4);

    return strdup(str3);
}
char* getTempMinus() {
    char str3[100] = "t";
    char str4[20];
    sprintf(str4, "%d", t-1);
    strcat(str3, str4);

    return strdup(str3);
}
void shift(int pos) {
  for (int i = pos; i < qc - 1; i++) {
    strcpy(quad[i].oper, quad[i+1].oper);
    strcpy(quad[i].op1, quad[i+1].op1);
    strcpy(quad[i].op2, quad[i+1].op2);
    strcpy(quad[i].res, quad[i+1].res);
  }
  qc--;
}

void Propagation_de_copie(int quadCount) {
  printf("-optimization propogation de copie \n-");
  //MAIN QUADRUPLE ARRAY AND TEMP ARRAYS TO PROGOROMA THE PROPOGATION
  qdr *p;
  qdr *ps;
  qdr *p1=quad;
  qdr *p2=quad;
  qdr *p3=quad;
  qdr *temp=quad;
  //VARIABLE TO SAVE OP1 AND OP2 AND OPR AND RESULTS
  char OPER[200];
  char OP1[200];
  char OP2[200];
  char RES[200];
  char RES2[200];
  int mod =0;
  int nb_shifted=0;
  for(int i=0;i<qc;i++)
  {
    //printf("i=%d\n",i);
    p = &p1[i];
    //printf("p[%d]=(%s,%s,%s,%s)\n",i,p->oper,p->op1,p->op2,p->res);
    //save p attributes
    //check if the quad isnt Branchement quad or an AFF(=) quadruple
    if(strcmp(p->oper ,":=")!=0 && strcmp(p->oper ,"BZ")!=0 && strcmp(p->oper ,"BR")!=0 )
    {
      printf("\t \t VERFIFYING QUADRUPLE NOT BRANCHEMENT QUAD OR AFFECTATION BRANCHEMENT \n");
      printf("\t \t p[%d]=(%s,%s,%s,%s) ", i, p->oper, p->op1, p->op2, p->res);
      //Variables storing
      strcpy(OPER , p->oper) ;
    	strcpy(OP1 , p->op1) ;
    	strcpy(OP2 , p->op2) ;
    	strcpy(RES , p->res) ;
      printf("  OPER=%s,",OPER);
      printf("  OP1= %s,",OP1);
      printf("  OP2= %s,",OP2);
      printf("  RES= %s\n",RES);
      //INIT P2 TO POINT TO THE NEXT ELEMENT OF P
      for(int j=i+1;j<qc;j++)
      {
        //The loop condition checks two things: whether p2 is not null and whether the result of p2 is not equal to OP1 and OP2.
        if(p2 != NULL && (strcmp(p2->res ,OP1)!=0 && strcmp(p2->res ,OP2)!=0))
        {
          printf("\t \t \t \t  The loop condition checks two things: whether p2 is not null and whether the result of p2 is not equal to OP1 and OP2.\n");
          p = &p2[j];
          printf("\t \t \t \t  p[%d]=(%s,%s,%s,%s)\n", j, p->oper, p->op1, p->op2, p->res);
          if((strcmp(p->op1 ,OP1)==0 && strcmp(p->op2 ,OP2)==0 && strcmp(p->oper ,OPER)==0) || (strcmp(p->op1 ,OP2)==0 && strcmp(p->op2 ,OP1)==0 && strcmp(p->oper ,OPER)==0))
    			{
            printf("\t \t \t \t \tInside the loop, the first if statement checks if p2 has the same operation (OPER), and the same operands (OP1, OP2) as the current instruction\n");
            printf("\t \t \t \t \tp[%d]=(%s,%s,%s,%s)\n", j, p->oper, p->op1, p->op2, p->res);
            printf("\t \t \t \t \t \tIf p2 matches, the code enters the if statement body, and p3 is set to the next instruction after p2. Then RES2 is assigned the value of p2's result.\n");
            int k=j+1;
            ps=&p2[k];   
            printf("\t \t \t \t \t \t p[%d]=(%s,%s,%s,%s)\n", k, ps->oper, ps->op1, ps->op2, ps->res);   
            strcpy(RES2 , p->res) ;    
            printf("\t \t \t \t \t \t RES2=%s\n",RES2);  
            printf("\t \t \t \t \t \tA nested loop starts with p3 and loops over the subsequent instructions until it finds an instruction that \n \t \t \t \t \t \tuses RES2 as either operand OP1 or operand OP2. Then, that operand is replaced with the value of RES.\n");
            for(;k<qc;k++)
            {
              ps=&p2[k];   
              printf("\t \t \t \t \t \t p[%d]=(%s,%s,%s,%s)\n", k, ps->oper, ps->op1, ps->op2, ps->res);
              if(strcmp(ps->op1 ,RES2)==0 )
    					{
    							strcpy(ps->op1,RES) ;
    							mod =1;
                  printf("\t \t \t \t \t \t p[%d]=(%s,%s,%s,%s)\n", k, ps->oper, ps->op1, ps->op2, ps->res);
    					}
    					if(strcmp(ps->op2 ,RES2)==0)
    					{
    							strcpy(ps->op2,RES) ;
    							mod =1;
                  printf("\t \t \t \t \t \t p[%d]=(%s,%s,%s,%s)\n", k, ps->oper, ps->op1, ps->op2, ps->res);

    					}            
		    	
            }
            if(mod==1)
            {
        	    printf("\t \t \t \t  \tAfter the nested loop, there is a conditional statement that checks if the current instruction is not the first instruction\n\t \t \t \t \t(listeQdr) and whether any changes (mod) have been made to the instruction. If these conditions are met,\n\t \t \t \t \tthe current instruction is removed from the list.\n");
              printf("\t \t \t \t  \tremove instruction at %d \n",j);
              shift(j); 
              nb_shifted++; 
           }
          }
              
        }
      }

    }
    mod=0;
  }
  printf("\t \t \tsecond part of function fixes the adressage of BZ and BR\n");
  p1=quad;
  p2=quad;
  p=&p1[0];
  ps=&p2[0];
  int value;
  char str[10];
  //printf("\t \t \tp[%d]=(%s,%s,%s,%s)\n", 0, p->oper, p->op1, p->op2, p->res);
  //printf("\t \t \tps[%d]=(%s,%s,%s,%s)\n", 0, ps->oper, ps->op1, ps->op2, ps->res);
  printf("\t\t\tshifted=%d\n",nb_shifted);
  if(nb_shifted>0)
  {
    //loop throught the quads
    //if its branchement BR or branchement BZ decrement the op1 by nb_shifted
    for(int i=0;i<qc;i++)
    {
      p=&p1[i];
      if(strcmp(p->oper ,"BZ")==0 || strcmp(p->oper ,"BR")==0 )
      {
        printf("\t \t \tp[%d]=(%s,%s,%s,%s)\n", i, p->oper, p->op1, p->op2, p->res);
        value=atoi(p->op1);
        printf("\t\t\tvalue=%d\n",value);
        value=value-nb_shifted;
        printf("\t\t\tvalue_new=%d\n",value);
        sprintf(str,"%d",value);
        strcpy(p->op1,str);
      }
    }
  }

}

void Propagation_de_expression() 
{
  printf("-PROPOGATION DE EXPRESSON COMMON \n");
  /*the concept in which optimization of expression common is based on*/
  qdr *p;
  qdr *ps;
  qdr *pf;
  qdr *p1=quad;
  qdr *p2=quad;
  qdr *p3=quad;
  //VARIABLE TO SAVE OP1 AND OP2 AND OPR AND RESULTS
  char OPER[200];
  char OP1[200];
  char OP2[200];
  char RES[200];
  char RES2[200];
  char RES_OLD[200];
  char RES_NEW[200];
  
  int LENGTH_OF_CHANGE=0;

  //first level
  for(int i=0;i<qc;i++)
  {
    p = &p1[i];
    //printf("|p[%d]=(%s,%s,%s,%s)\n",i,p->oper,p->op1,p->op2,p->res);
    //save p attributes
    //check if the quad isnt Branchement quad or an AFF(=) quadruple
    if(strcmp(p->oper ,":=")==0)
    {
      //printf("\t|CHECKING IF CURRENT QUAD IS AFFECATION\n");
      //printf("\t|p[%d]=(%s,%s,%s,%s)\n",i,p->oper,p->op1,p->op2,p->res);
      //printf("\t|AFFECTATION RESULT : %s \n",p->op1);
      //printf("\t|OLD AFFECATAION : %s\n",p->res);

      //second level
        int k=i+1;
        LENGTH_OF_CHANGE=0;
        strcpy(RES_NEW,"SAME") ;
        strcpy(RES_OLD,"NOT SAME") ;
        while(k<qc && (strcmp(RES_NEW,RES_OLD)!=0))
        {
        pf = &p1[k];
         //printf("\t\t|COUNTING LENGTH OF CHANGE \n");
         //printf("\t\t|p[%d]=(%s,%s,%s,%s)\n",k,pf->oper,pf->op1,pf->op2 ,pf->res);
         strcpy(RES_NEW, pf->res) ;
         strcpy(RES_OLD, p->res) ;
         //printf("\t\t|RES_NEW=%s , RES_OLD=%s \n",RES_NEW,RES_OLD);
         LENGTH_OF_CHANGE++;
         k++;
        }
        //printf("\t\t\t LENGTH OF CHANGE = %d \n",LENGTH_OF_CHANGE);
      
      //LENGTH OF CHANGE LOOP COUNT
      for(int j=i+1;j<i+LENGTH_OF_CHANGE;j++)
      {
        ps=&p2[j];
        if(strcmp(ps->oper ,":=")!=0 && strcmp(ps->oper ,"BZ")!=0 && strcmp(ps->oper ,"BR")!=0 )
    {
          //printf("\t\t\t|p[%d]=(%s,%s,%s,%s)\n",j,ps->oper,ps->op1,ps->op2,ps->res);
          strcpy(OPER, p->oper) ;
    	    strcpy(OP1 , p->op1) ;
    	    strcpy(OP2 , p->op2) ;
    	    strcpy(RES , p->res) ;
          if((strcmp(ps->res ,OP1)!=0 && strcmp(ps->res ,OP2)!=0))
          {
            //printf("\t\t\t|OLD used AS OP1 OR OP 2\n");
            //printf("\t\t\t|p[%d]=(%s,%s,%s,%s)\n",j,ps->oper,ps->op1,ps->op2,ps->res);

            if((strcmp(ps->op1 ,RES)==0 || strcmp(ps->op2 ,OP1)==0 ))
    			{
            strcpy(RES2,p->res);
            //printf("\t\t\t|res[OLD]=%s\n",RES);
            //printf("\t\t\t|res[NEW]=%s\n",OP1);

              //printf("\t\t\t\t\t\t|OLD:p[%d]=(%s,%s,%s,%s)\n",j,ps->oper,ps->op1,ps->op2,ps->res);
              if(strcmp(ps->op1 ,RES2)==0 )
    					{
    							strcpy(ps->op1,OP1) ;
    					}
    					if(strcmp(ps->op2 ,RES2)==0)
    					{
    							strcpy(ps->op2,OP1) ;
    					}
              //printf("\t\t\t\t\t\t|NEW:p[%d]=(%s,%s,%s,%s)\n",j,ps->oper,ps->op1,ps->op2,ps->res);
            }
           
          }
        }
    }
      }
  }
  }



void elimination_expression_commune() 
{
  printf("-elimination d'expression commune\n");
  /*the concept in which optimization of expression common is based on*/
  qdr *p;
  qdr *ps;
  qdr *pf;
  qdr *p1=quad;
  qdr *p2=quad;
  qdr *p3=quad;
  //VARIABLE TO SAVE OP1 AND OP2 AND OPR AND RESULTS
  char OPER[200];
  char OP1[200];
  char OP2[200];
  char RES[200];
  char RES2[200];
  int mod=0;
  int nb_shifted=0;
  for(int i=0;i<qc;i++)
  {
    p = &p1[i];
    //printf("|p[%d]=(%s,%s,%s,%s)\n",i,p->oper,p->op1,p->op2,p->res);
    //save p attributes
    //check if the quad isnt Branchement quad or an AFF(=) quadruple
    if(strcmp(p->oper ,":=")!=0 && strcmp(p->oper ,"BZ")!=0 && strcmp(p->oper ,"BR")!=0 )
    {
      //printf("\t|current quadruple is not branchement quad or affectation\n");
      //printf("\t|p[%d]=(%s,%s,%s,%s)\n",i,p->oper,p->op1,p->op2,p->res);
      for(int j=i+1;j<qc;j++)
      {
        ps=&p2[j];
        //printf("\t\t|looping subquadruples from first quad\n");
        //printf("\t\t|p[%d]=(%s,%s,%s,%s)\n",j,ps->oper,ps->op1,ps->op2,ps->res);
        //printf("\t\t\t|subsequences that arent branchement quad or affecations\n");
        //printf("\t\t\t|p[%d]=(%s,%s,%s,%s)\n",j,ps->oper,ps->op1,ps->op2,ps->res);
          strcpy(OPER, p->oper) ;
    	    strcpy(OP1 , p->op1) ;
    	    strcpy(OP2 , p->op2) ;
    	    strcpy(RES , p->res) ;
          //printf("\t\t\t|res=%s\n",RES);
          if((strcmp(ps->res ,OP1)!=0 && strcmp(ps->res ,OP2)!=0))
          {
            //printf("\t\t\t\t|checking that there is no relation between the two quadruples ie op1 or op2 is used as result in sub quad\n");
            if((strcmp(ps->op1 ,OP1)==0 && strcmp(ps->op2 ,OP2)==0 && strcmp(ps->oper ,OPER)==0) || (strcmp(ps->op1 ,OP2)==0 && strcmp(ps->op2 ,OP1)==0 && strcmp(ps->oper ,OPER)==0))
    			{
            //printf("\t\t\t\t\t|checking if the subquad as the same oper op1 and op2 and mainquad\n");
            int k=j+1;
            strcpy(RES2,ps->res);
            //printf("\t\t\t\t\t|res2=%s\n",RES2);
            for(k;k<qc;k++)
            {
              pf=&p3[k];
              //printf("\t\t\t\t\t\t|OLD:p[%d]=(%s,%s,%s,%s)\n",k,pf->oper,pf->op1,pf->op2,pf->res);
              if(strcmp(pf->op1 ,RES2)==0 )
    					{
    							strcpy(pf->op1,RES) ;
    							mod =1;
    					}
    					if(strcmp(pf->op2 ,RES2)==0)
    					{
    							strcpy(pf->op2,RES) ;
    							mod =1;
    					}
              //printf("\t\t\t\t\t\t|NEW:p[%d]=(%s,%s,%s,%s)\n",k,pf->oper,pf->op1,pf->op2,pf->res);
            }
            if(mod==1)
            {
        	    //printf("\t \t \t \t  \tAfter the nested loop, there is a conditional statement that checks if the current instruction is not the first instruction\n\t \t \t \t \t(listeQdr) and whether any changes (mod) have been made to the instruction. If these conditions are met,\n\t \t \t \t \tthe current instruction is removed from the list.\n");
              //printf("\t \t \t \t  \tremove instruction at %d \n",j);
              shift(j); 
              nb_shifted++; 
           }
          }
        }
    }
  }
  }
  //printf("\t \t \tsecond part of function fixes the adressage of BZ and BR\n");
  p1=quad;
  p2=quad;
  p=&p1[0];
  ps=&p2[0];
  int value;
  char str[10];
  //printf("\t \t \tp[%d]=(%s,%s,%s,%s)\n", 0, p->oper, p->op1, p->op2, p->res);
  //printf("\t \t \tps[%d]=(%s,%s,%s,%s)\n", 0, ps->oper, ps->op1, ps->op2, ps->res);
  printf("\t\t\tshifted=%d\n",nb_shifted);
  if(nb_shifted>0)
  {
    //loop throught the quads
    //if its branchement BR or branchement BZ decrement the op1 by nb_shifted
    for(int i=0;i<qc;i++)
    {
      p=&p1[i];
      if(strcmp(p->oper ,"BZ")==0 || strcmp(p->oper ,"BR")==0 || strcmp(p->oper ,"BG")==0 || strcmp(p->oper ,"BGE")==0 || strcmp(p->oper ,"BL")==0 || strcmp(p->oper ,"BLE")==0 || strcmp(p->oper ,"BE")==0 || strcmp(p->oper ,"BNE")==0)
      {
        //printf("\t \t \tp[%d]=(%s,%s,%s,%s)\n", i, p->oper, p->op1, p->op2, p->res);
        value=atoi(p->op1);
        //printf("\t\t\tvalue=%d\n",value);
        value=value-nb_shifted;
        //printf("\t\t\tvalue_new=%d\n",value);
        sprintf(str,"%d",value);
        strcpy(p->op1,str);
      }
    }
  }
}







//THIS FUNCTION OUTPUT THE OPTMIZED QUADRUPLE
void afficher_qdr_opti() {
  printf("*********************Les Quadruplets apres optimisation***********************\n");
  int i;
  for (i = 0; i < qc; i++) {
    printf("\n %d - ( %s , %s , %s , %s )", i, quad[i].oper, quad[i].op1,quad[i].op2, quad[i].res);
    printf("\n---------------------------------------------------\n");
  }
}


// Partie code objet


char acc[20];

char code [100][200];

int codeIndex = 0;

char instLoad[] = "LOAD";

void generateCodeObjet ()
{
   int etiq[100];
   int e = 0;
   FILE *file;
    file = fopen("prog.asm", "w");

    if (file == NULL) {
        printf("Error opening the file.\n");
    }

    fprintf(file, "TITLE prog.asm: Example,\n\n");
    fprintf(file, "Pile segment stack ;\n");
    fprintf(file, "dw 100 dup(?)\n");
    fprintf(file, "Pile ends\n\n");
    fprintf(file, "DATA segment\n");
    writeToAsm(file);
    fprintf(file, "DATA ends\n\n");
    fprintf(file,"CODE segment\n");
    fprintf(file,"MAIN:\n");
    fprintf(file,"\t\tASSUME CS: CODE, DS:DATA\n");
    fprintf(file,"\t\tMOV AX,DATA\n");
    fprintf(file,"\t\tMOV DX,AX\n\n");

    for(int i=0;i < qc ;i++)
    {
      if(quad[i].oper[0] == 'B')
      {
        etiq[e] = atoi(quad[i].op1);
              e++;
      }
    }

     for(int i=0;i < qc ;i++)
  {
    for(int z = 0;z<e;z++)
          {
            if(etiq[z] == i)
                {
                  fprintf(file,"label_%d : \n",i);
                }
          } 
    switch(quad[i].op1[0])
    {
      case 't':
        switch(quad[i].oper[0]) {
        case '+':
        fprintf(file, "\t\tADD AX ,%s\n", quad[i].op2);
          break;
        case '-':
        fprintf(file, "\t\tSUB AX ,%s\n", quad[i].op2);
          break;
        case '*':
        fprintf(file, "\t\tMOV BX ,%s\n", quad[i].op2);
        fprintf(file, "\t\tMULT BX\n");
          break;
        case '/':
        fprintf(file, "\t\tMOV BX ,%s\n", quad[i].op2);
        fprintf(file, "\t\tDIV BX\n");
          break;
        case ':':
          fprintf(file, "\t\tMOV %s ,AX\n", quad[i].res);
          break;
        }
          break;

      default  :
          switch(quad[i].oper[0]) {
            case '+':
            fprintf(file, "\t\tMOV AX, %s\n", quad[i].op1);
            fprintf(file, "\t\tADD AX, %s\n", quad[i].op2);
              break;
            case '-':
            fprintf(file, "\t\tMOV AX, %s\n", quad[i].op1);
            fprintf(file, "\t\tSUB AX, %s\n", quad[i].op2);

              break;
            case '*':
            fprintf(file, "\t\tMOV AX, %s\n", quad[i].op1);
            fprintf(file, "\t\tMOV BX, %s\n", quad[i].op2);
            fprintf(file, "\t\tMULT BX\n");

              break;
            case '/':
              fprintf(file, "\t\tMOV AX, %s\n", quad[i].op1);
              fprintf(file, "\t\tMOV BX, %s\n", quad[i].op2);
              fprintf(file, "\t\tDIV BX\n");
              break;
            case ':':
              fprintf(file, "\t\tMOV AX, %s\n", quad[i].op1);
              fprintf(file, "\t\tMOV %s, AX\n", quad[i].res);

              break;
            case 'B':
              fprintf(file,"\t\tCMP AX, BX\n");
              switch(quad[i].oper[1])
              {
                case 'G':
                if(quad[i].oper[2]=='E')
                {
                  fprintf(file,"\t\tJAE label,%s\n",quad[i].op1);
                }else {
                  fprintf(file,"\t\tJA label,%s\n",quad[i].op1);
                }
                break;
                case 'L':
                 if(quad[i].oper[2]=='L')
                {
                  fprintf(file,"\t\tJBE label,%s\n",quad[i].op1);
                }else {
                  fprintf(file,"\t\tJB label,%s\n",quad[i].op1);
                }
                break;
                case 'N':
                fprintf(file,"\t\tJNE label,%s\n",quad[i].op1);
                break;
                case 'E':
                fprintf(file,"\t\tJE label,%s\n",quad[i].op1);
                break;
                case 'R':
                fprintf(file,"\t\tJMP label,%s\n",quad[i].op1);
                break;
              }
              
              break;
          }    
          break;
          
    }
    
    }
    
    fprintf(file,"MAIN    ENDS\n\t\tEND MAIN");
    fclose(file);

    printf("object code is generated successfuly\n");
  }



void printCodeObjet()
{
    printf("----------Code Objet---------\n");
    for (int i = 0; i < codeIndex; i++) {
        printf("%s\n", code[i]);
    }
     
}


