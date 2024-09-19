#include <stdio.h>

int main() {
    int num = 0, numcoelhos = 0, numratos = 0, numsapos = 0, i = 0, total, quant;
    float porc_coelhos, porc_ratos, porc_sapos;
    char letra;

    scanf("%d", &total);

    while (i < total) {
        scanf("%d %c", &num, &letra);

        if ((num >= 1) && (num <= 15)) {
            if (letra == 'C' || letra == 'c') {
                numcoelhos = num + numcoelhos;
            } else if (letra == 'R' || letra == 'r') {
                numratos = num + numratos;
            } else if (letra == 'S' || letra == 's') {
                numsapos = num + numsapos;
            }
        }

        i++;
    }

    quant = numcoelhos + numratos + numsapos;
    porc_coelhos = (numcoelhos * 100.0) / quant;
    porc_ratos = (numratos * 100.0) / quant;
    porc_sapos = (numsapos * 100.0) / quant;

    printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\nPercentual de coelhos: %.2f %c\nPercentual de ratos: %.2f %c\nPercentual de sapos: %.2f %c\n", quant, numcoelhos, numratos, numsapos, porc_coelhos, 37, porc_ratos, 37, porc_sapos, 37);

    return 0;
}
