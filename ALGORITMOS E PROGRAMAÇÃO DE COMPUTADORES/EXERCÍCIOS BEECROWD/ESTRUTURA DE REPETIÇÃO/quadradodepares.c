#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, i = 0;

    scanf("%d", &N);

    if ((N % 2 == 0) && (N > 5) && (N < 2000)) {
        while (i < N) {
            i += 2;
            printf("%d^2 = %.0f\n", i, pow(i, 2));
        }
    } else if ((N % 2 != 0) && (N > 5) && (N < 2000)) {
        while (i < N - 1) {
            i += 2;
            printf("%d^2 = %.0f\n", i, pow(i, 2));
        }
    }

    return 0;
}