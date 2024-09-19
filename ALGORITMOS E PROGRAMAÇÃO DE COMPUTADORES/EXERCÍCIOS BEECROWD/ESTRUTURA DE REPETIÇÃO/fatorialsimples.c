#include <stdio.h>

int main() {
    int N, total = 1;

    do {
    scanf("%d", &N);
    } while (N < 0 || N > 13);

    for (int i = N; i > 0; i--) {
        total = total * i;
    }

    printf("%d\n", total);

    return 0;
}