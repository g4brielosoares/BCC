#include <stdio.h>
#include<math.h>

int main() {
    float x1, x2, y1, y2, distancia, p1, p2, produto;

    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);

    p1 = x2 - x1;
    p2 = y2 - y1;
    produto = pow(p1, 2) + pow(p2, 2);
    distancia = sqrt(produto);

    printf("%.4f\n", distancia);

    return 0;
}