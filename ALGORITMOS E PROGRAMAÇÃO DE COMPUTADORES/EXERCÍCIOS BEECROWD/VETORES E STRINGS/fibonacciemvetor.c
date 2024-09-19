#include <stdio.h>

int main() {
    int quant;
    unsigned long long fib[60], N;

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 60; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    scanf("%llu", &quant);
    while (quant--) {
        scanf("%llu", &N);
        printf("Fib(%llu) = %llu\n", N, fib[N]);
    }

    return 0;
}