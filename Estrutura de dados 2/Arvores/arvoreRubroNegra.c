#include <stdio.h>

typedef enum {
    VERMELHO, 
    PRETO
} Cor;

typedef struct no {
    Cor cor;
    struct no *direita;
    struct no *esquerda;
    struct no *pai;
} No;

int correcao(No **raiz) {
    No *tio, *irmao, *papai = raiz->pai, *avo = raiz->pai->pai;

    if (raiz->pai == avo->esquerda) {
        tio = raiz->pai->pai->direita;

        if (tio->cor == VERMELHO) {
            papai->cor = PRETO;
            avo->cor = VERMELHO;
            tio->cor = PRETO;
            correcao(avo);
        } else {
            if (raiz == raiz->pai->direita) {
                irmao = raiz->pai->esquerda;
                RSE(papai);
                atualiza o nó a ser avaliado..
            }
            RSD(avo);
        }
    } 
}

No *criarNo() {

}

int inserir() {
    
}

int main() {

    return 0;
}