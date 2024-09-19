#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, maiorAB, maior;

    scanf("%d %d %d", &a, &b, &c);

    maiorAB = (a + b + abs(a - b)) / 2;
    maior = (c + maiorAB + abs(c - maiorAB)) / 2;

    printf("%d eh o maior\n", maior);

    return 0;
}