typedef struct fila Fila;

Fila *criarFila();
void destruirFila(Fila **f);
void verificarNulo(Fila *f);
int enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f);
int *primeiro(Fila *f);
int menu(Fila *f);
void mostrarFila(Fila f);

