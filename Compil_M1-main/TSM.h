#ifndef TSM_H
#define TSM_H

typedef struct element2 {
  char *name;
  char *desc;
} e;

typedef struct element2 e;

void insertTS (char* elementName, char* elementDesc);
void afficherTS();
void insertTM(char *elementName);
void afficherTM();
void insertTsT(char *elementName);
int rechercherTsT(char* elementName);

#endif
