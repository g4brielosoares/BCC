#include <stdio.h>

int primoRec(int n, int i) {
    if (i <= 0)
        return 0;    
    if (i == 1)
        return 1;
    if (n % i == 0)
        return 0;
    return primoRec(n, i - 1);
}

int primo(int n) {
    return primoRec(n, n - 1);
}

int main() {
    int n;

    scanf("%i", &n);

    if (primo(n) == 1)
        printf("Nao e primo\n");   
    else
        printf("E primo\n");

    return 0;
}