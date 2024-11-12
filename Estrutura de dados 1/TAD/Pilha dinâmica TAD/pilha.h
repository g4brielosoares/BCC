
typedef struct pilha Pilha;

Pilha *criar_pilha();
void destruir_pilha(Pilha **p);
int empilhar(Pilha *p, int vlr);
int desempilhar(Pilha *p);
int *topo(Pilha *p);
void mostrar_pilha(Pilha *p);
int testar_pilha_nula(Pilha *p);
