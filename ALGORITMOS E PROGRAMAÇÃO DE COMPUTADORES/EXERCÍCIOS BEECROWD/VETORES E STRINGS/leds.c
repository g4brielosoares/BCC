#include <stdio.h>
#define TAM 100

int main() {
    char numeros[TAM] = "\0";
    int testes, leds;

    scanf("%d", &testes);

    for (int j = 0; j < testes; j++) {
        scanf("\n%[^\n]", numeros);

        for (int i = 0; numeros[i] != '\0'; i++) {
            if (numeros[i] == '0' || numeros[i] == '9' || numeros[i] == '6') {
                leds += 6;
            } else if (numeros[i] == '1') {
                leds += 2;
            } else if (numeros[i] == '2' || numeros[i] == '3' || numeros[i] == '5') {
                leds += 5;
            } else if (numeros[i] == '4') {
                leds += 4;
            } else if (numeros[i] == '7') {
                leds += 3;
            } else if (numeros[i] == '8') {
                leds += 7;
            }
        }
        printf("%d leds\n", leds);
        leds = 0;
    }

    return 0;
}