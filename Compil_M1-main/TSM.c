#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct element2 {
  char *name;
  char *desc;
} e;

#define TABLE_SIZE 1000


int iTS = 0; // indice table des séparateurs
int iTM = 0; // indice table des mots clés
int iTsT  = 0; // indice pour la table qui contient les définition de struct

e TS[TABLE_SIZE]; // Table des séparateurs
char *TM[TABLE_SIZE]; // Table des mots clés
char *TSt[TABLE_SIZE]; // Table qui contient les définitions de struct

int rechercher(char* elementName) {
    for (int i = 0; i < iTS; i++) {
        if (strcmp(TS[i].name, elementName) == 0) {
            return 1;
        }
    }
    return 0;
}

int rechercherTM(char* elementName) {
    for (int i = 0; i < iTM; i++) {
        if (strcmp(TM[i], elementName) == 0) {
            return 1;
        }
    }
    return 0;
}
// Retourne 1 is existe, 0 sinon
int rechercherTsT(char* elementName) {
    for (int i = 0; i < iTsT; i++) {
        if (strcmp(TSt[i], elementName) == 0) {
            return 1;
        }
    }
    return 0;
}

void insertTS (char* elementName, char* elementDesc)
{
    if(rechercher(elementName) == 0)
    {
         TS[iTS].name = malloc(strlen(elementName) + 1);
    TS[iTS].desc = malloc(strlen(elementDesc) + 1);
    strcpy(TS[iTS].name, elementName);
    strcpy(TS[iTS].desc, elementDesc);
    iTS++;
    }
}

void insertTM(char *elementName) {
    if (rechercherTM(elementName) == 0) {
        TM[iTM] = malloc(strlen(elementName) + 1);
        strcpy(TM[iTM], elementName);
        iTM++;
    }
}

void insertTsT(char *elementName) {
    if (rechercherTsT(elementName) == 0) {
        TSt[iTsT] = malloc(strlen(elementName) + 1);
        strcpy(TSt[iTsT], elementName);
        iTsT++;
    }
}


void afficherTS() {
    printf("\nTable des séparateurs : \n");
    printf("|      Name      |           Desc          |\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < iTS; i++) {
        printf("| %-14s | %-24s |\n", TS[i].name, TS[i].desc);
    }
}

void afficherTM() {
    printf("\nTable des mots clés :\n");
    printf("|      Name      |\n");
    printf("-----------------\n");

    for (int i = 0; i < iTM; i++) {
        printf("| %-14s |\n", TM[i]);
    }
}


