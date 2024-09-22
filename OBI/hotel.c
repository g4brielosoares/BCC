#include <stdio.h>

int main () {
    int valorDiaria, aumentoDiaria, diaDaChegada, total, mes = 31;

    scanf("%d%d%d", &valorDiaria, &aumentoDiaria, &diaDaChegada);

    if (diaDaChegada == 1) {
        total = mes * valorDiaria;
    } else if (diaDaChegada <= 15) {
        total = (mes - diaDaChegada + 1) * (valorDiaria + aumentoDiaria * (diaDaChegada - 1));
    } else {
        total = (mes - diaDaChegada + 1) * (valorDiaria + aumentoDiaria * 14);
    }
    
    printf("%d\n", total);

    return 0;
}