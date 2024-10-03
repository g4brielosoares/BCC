#include <stdio.h>
#define TAM 100

int main() {
    double N[TAM];

    scanf("%lf", &N[0]);

    for (int i = 0; i < (TAM - 1); i++) {
        N[i + 1] = N[i] / 2.0;
        if (i != 0) {
            printf("N[%d] = %.4lf\n", i + 1, N[i + 1]);
        } else {
            printf("N[%d] = %.4lf\n", i, N[i]);
            printf("N[%d] = %.4lf\n", i + 1, N[i + 1]);
        }
    }
    
    return 0;
}