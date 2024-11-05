#include <stdio.h>

int main() {
    int vitorias = 0;
    char entrada, buffer;
    
    for (int i = 0; i < 6; i++) {
        scanf("%c%c", &entrada, &buffer);
        if (entrada == 'V' || entrada == 'v') vitorias++;
    }

    if (vitorias >= 5) {
        printf("1\n");
    } else if (vitorias >= 3) {
        printf("2\n");
    } else if (vitorias >= 1) {
        printf("3\n");
    } else {
        printf("-1\n");
    }

    return 0;
}