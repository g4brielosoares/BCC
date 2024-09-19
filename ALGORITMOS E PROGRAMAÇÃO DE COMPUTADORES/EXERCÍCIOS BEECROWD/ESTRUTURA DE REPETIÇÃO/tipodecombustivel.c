#include <stdio.h>

int main() {
    int N, gasolina = 0, alcool = 0, diesel = 0;

    do {
        scanf("%d", &N);
        switch(N) {
            case 1:
                alcool++;
                break;
            case 2:
                gasolina++;
                break;
            case 3:
                diesel++;
                break;
            default:
                break;
        }
    } while (N != 4);

    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", alcool, gasolina, diesel);


    return 0;
}