typedef struct deque Deque;

Deque criarDeque();
No *criarNo();
void destruirDeque(Deque **d);
int inserirNoInicio(Deque *d, int valor);
int inserirNoFim(Deque *d, int valor);
int removerNoInicio(Deque *d);
int removerNoFim(Deque *d);
int *consultarInicio(Deque *d);
int *consultarFim(Deque *d);
void mostrarDeque(Deque *d);
void verificarNulo(Deque *d);