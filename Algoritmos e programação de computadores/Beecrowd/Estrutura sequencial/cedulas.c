#include <stdio.h>

int main() {
    int N, N100, N50, N20, N10, N5, N2, N1;

    do {
        scanf("%d", &N);
    } while (N < 0 && N > 1000000);
    
    N100 = N / 100;
    N50 = (N % 100) / 50;
    N20 = ((N % 100) % 50) / 20;
    N10 = (((N % 100) % 50) % 20) / 10;
    N5 = ((((N % 100) % 50) % 20) % 10) / 5;
    N2 = (((((N % 100) % 50) % 20) % 10) % 5) / 2;
    N1 = ((((((N % 100) % 50) % 20) % 10) % 5) % 2) / 1;

    printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", N, N100, N50, N20, N10, N5, N2, N1);

    return 0;
}