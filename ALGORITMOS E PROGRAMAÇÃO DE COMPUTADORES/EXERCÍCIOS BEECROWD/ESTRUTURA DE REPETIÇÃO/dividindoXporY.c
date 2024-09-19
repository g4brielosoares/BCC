#include <stdio.h>

int main() {
    float N, x, y, resultado_divisao;

    scanf("%f", &N);

    for (int i = 0; i < N; i++) {
        scanf("%f %f", &x, &y);

        resultado_divisao = x / y;

        if (y == 0) {
            printf("divisao impossivel\n");
        } else {
            printf("%.1f\n", resultado_divisao);    
        }
    }

    return 0;
}