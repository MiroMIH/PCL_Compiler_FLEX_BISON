#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

typedef struct element {
  char *name;
  int type;    // 1 pour int , 2 pour float, 3 pour struct -1 for not initialized
  float value;
  int isConst; // 1 for true / 0 for false
  int isArray; // 1 for true / 0 for false
  struct element *next;
} el;

// struct TypeTS *ptr;
el *TSH[HASH_TABLE_SIZE] = {NULL};


int getPos(char *string) {
  int total = 0;
  for (int i = 0; i < strlen(string); i++) {
    total += string[i];
  }
  return (total%100);
}

// return the element pointer if it exists, NULL instead
el *lookup(char *elementName) {
  int pos = getPos(elementName);
  el *cur = TSH[pos];

  while (cur != NULL) {
    if (strcmp(cur->name, elementName) == 0) {
      return cur;
    }
    cur = cur->next;
  }

  return NULL;
}

void insert(char *elementName, int is_const,int is_array) {

  
  if (lookup(elementName) == NULL) {
    int pos = getPos(elementName);
    el *newElement = (el *)malloc(sizeof(el));
    newElement->name = elementName;
    newElement->value = 0;
    newElement->type = -1;
    newElement->isArray = is_array;
    newElement->isConst = is_const;
    newElement->next = NULL;
    if (TSH[pos] == NULL) {
      TSH[getPos(elementName)] = newElement;
    } else {
      struct element *cur = TSH[pos];
      while (cur->next != NULL) {
        cur = cur->next;
      }
      cur->next = newElement;
    }
    // strcpy(TSH[getPos(elementName)]->name,elementName);
  } else
    printf("double declaration de %s\n", elementName);
}

void insertType(char *elementName, int elementType) {
  if (lookup(elementName) != NULL) {
    int pos;
    pos = getPos(elementName);
    struct element *cur = TSH[pos];
    if (pos != -1) {
      while (strcmp(cur->name, elementName) != 0) {
        cur = cur->next;
      }
      cur->type = elementType;
    }
  }
}

void updateVal(char *elementName, float value) {
  if (lookup(elementName) != NULL) {
    int pos;
    pos = getPos(elementName);
    struct element *cur = TSH[pos];
    if (pos != -1) {
      while (strcmp(cur->name, elementName) != 0) {
        cur = cur->next;
      }
      cur->value = value;
    }
  }
}

void afficher() {
  printf("\nTable des symboles : \n");
  printf("%-9s | %-20s | %-10s | %-8s| %-8s| %-8s\n", "POS", "Name", "Type", "Value", "isConst","isArray");
  printf("---------------------------------------------------------------------------\n");
  int i = 0;
  while (i < HASH_TABLE_SIZE) {
    if (TSH[i] != NULL && strlen(TSH[i]->name) != 0) {
      int j = 0;
      struct element *cur = TSH[i];

      while (cur != NULL) {
        printf("(%d) %-5d | %-20s | %-10d |  %-10.2f | %-9d| %-9d\n", j, i, cur->name, cur->type, cur->value,
               cur->isConst,cur->isArray);
        j++;
        cur = cur->next;
      }
    }
    i++;
  }
}

void writeToAsm(FILE * f) {
  
  int i = 0;
  while (i < HASH_TABLE_SIZE) {
    if (TSH[i] != NULL && strlen(TSH[i]->name) != 0) {
      int j = 0;
      struct element *cur = TSH[i];

      while (cur != NULL) {
       
        fprintf(f, "\t%s\n", strcat(cur->name, " DW ?"));
        j++;
        cur = cur->next;
      }
    }
    i++;
  }
}