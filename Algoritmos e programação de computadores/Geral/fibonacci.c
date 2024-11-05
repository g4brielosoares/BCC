#include <stdio.h>

int main() {
    int fib[20], i;

    fib[0] = 0;
    fib[1] = 1;

    for (i = 0; i <= 20; i++) {
        if (i >= 2) fib[i] = fib[i - 1] + fib[i - 2];
        printf("F(%d) = %d\n", i, fib[i]);
    }

  return 0;
}