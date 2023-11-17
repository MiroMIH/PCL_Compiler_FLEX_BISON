#ifndef TS_H
#define TS_H

typedef struct element {
  char *name;
  int type;    // 1 pour int , 2 pour float, 3 pour struct -1 for not initialized
  float value;
  int isConst; // 1 for true / 0 for false
  int isArray; // 1 for true / 0 for false
  struct element *next;
} el;



typedef struct element el;

int getPos(char *string);
void insert(char *elementName, int is_const,int is_array);
void insertType(char *elementName, int elementType);
el *lookup(char *elementName);
void afficher();
void updateVal(char *elementName, float value);
void writeToAsm(FILE * f);

#endif
