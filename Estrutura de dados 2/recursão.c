#include <stdio.h>

void decrementoLACO(int N) {
    for (int i = N; i >= 0; i--) 
        printf("%i ", i);
}

void decrementoRECURSIVO(int N) {
    printf("%i ", N);
    if (N > 0) 
        decrementoRECURSIVO(N - 1);
}

int fatorial(int n) {
    if (n == 0) 
        return 1;
    else 
        return n * fatorial(n - 1);
}

int soma(int n) {
    if (n == 0) return 0;
    return n + soma(n - 1);
}

void fibonacci(int n) {
    if (n == 0 || n == 1) 
        printf("%i ", 1);
    else 
        printf("%i ", (n - 1 + n - 2)));

}

int main() {
    int N = 10;
    int n = 5;

    decrementoLACO(N);
    printf("\n");
    decrementoRECURSIVO(N);
    printf("\n%i\n", fatorial(n));
    printf("%i\n", soma(n));
    fibonacci(n);

    return 0;
}