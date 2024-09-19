#include <stdio.h>

int main() {
    int N, seg, min, horas;
    scanf("%d", &N);

    horas = (N / 60) / 60;
    min = (N / 60) % 60;
    seg = N % 60;

    printf("%d:%d:%d\n", horas, min, seg);

    return 0;
}