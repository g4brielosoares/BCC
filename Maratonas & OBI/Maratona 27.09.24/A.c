#include <stdio.h>
#include <string.h>

int main() {
    char refrao[100];
    char fala[100];

    while (scanf("%s", refrao) != EOF && scanf("%s", fala) != EOF) {
        if (strcmp(fala, "E lindo dizer!")) {
            printf("Suricato\n");
        } else if (strcmp(fala, "Sim, vai entender!")) {
            printf("Facocheiro\n");
        } else if (strcmp(fala, "Os seus problemas voce deve esquecer!")) {
            printf("leao\n;");
        }
    }
}