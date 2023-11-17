typedef struct quadruple{
  char *oper;
  char *op1;
  char *op2;
  char *res;
} qdr;

void quadr(char opr[], char op1[], char op2[], char res[]);
void add_quad(int num_quad, int colon_quad, char val[]);
void afficher_qdr();
char* getTemp();
char* getTempMinus();
void afficher_qdr_opti();
void Propagation_de_copie();
void elimination_expression_commune();
void  Propagation_de_expression();
void shift(int pos);
void generateCodeObjet();

