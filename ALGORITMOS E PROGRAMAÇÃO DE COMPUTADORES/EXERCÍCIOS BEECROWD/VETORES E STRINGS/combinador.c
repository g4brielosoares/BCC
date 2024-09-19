#include <stdio.h>
#define TAM 51

int tamanho(char *s) {
    int contador;
    for (contador = 0; s[contador] != '\0'; contador++) {
    }
    return contador;
}

int main() {
    char string1[TAM], string2[TAM], aux[TAM * 3];
    int casos = 0;

    scanf("%d", &casos);

    for (int i = 0; i < casos; i++) {
        int incremento = 0, tamanho1 = 0, tamanho2 = 0;
        
        scanf("%s", string1);
        scanf("%s", string2);
        tamanho1 = tamanho(string1);
        tamanho2 = tamanho(string2);

        for (int k = 0, l = 0; k < tamanho1 || l < tamanho2; k++, l++) {
            if(k < tamanho1) {
                aux[incremento++] = string1[k];
                k++;
            }
            if(l < tamanho2) {
                aux[incremento++] = string2[l];
                l++;
            }
        }
        aux[incremento] = '\0';
        printf("%s\n", aux);
    }

    return 0;
}