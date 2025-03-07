#include <stdio.h>

float calc(int n) {
    if (n <= 1)
        return 1;
    return (1.0 / n) + calc(n - 1);
}

int main() {
    int n;
    
    scanf("%i", &n);
    printf("%f\n", calc(n));

    return 0;
}