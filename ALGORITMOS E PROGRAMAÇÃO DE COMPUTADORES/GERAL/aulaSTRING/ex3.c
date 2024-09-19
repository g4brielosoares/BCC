#include <stdio.h>
#define TAM 10

int main() {
    char senha[TAM] = "pc01", str1[TAM];
    int i = 0;

    while (i == 0) {
        scanf("\n%[^\n]", str1);

        for (i = 0; str1[i] != '\0'; i++) {
            if (str1[i] != senha[i]) {
                printf("senha invalida\n");
                i = 0;
                break;
            }
        }
    }

    return 0;
}