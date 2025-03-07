#include <stdio.h>

int calcRec(int n, int x) {
    if (n <= 0) return 0;
    if (n % 10 == x)
        return 1 + calcRec(n / 10, x);
    return calcRec(n / 10, x);
}

int main() {
    int n, x;
    
    scanf("%i%i", &n, &x);
    printf("%i\n", calcRec(n, x));

    return 0;
}