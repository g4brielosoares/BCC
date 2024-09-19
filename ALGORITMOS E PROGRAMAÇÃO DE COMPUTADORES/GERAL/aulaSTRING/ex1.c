#include <stdio.h>
#define TAM 100

void leia_str(char *s) {
    scanf("\n%[^\n]", s);
}

int tamanho_str(char *s) {
    int t = 0;
    for (t = 0; s[t] != '\0';t++) {
    }
    return t;
}

int main() {
    char str[TAM];

    leia_str(str);
    printf("Total de %d caracteres\n", tamanho_str(str));

    return 0;
}