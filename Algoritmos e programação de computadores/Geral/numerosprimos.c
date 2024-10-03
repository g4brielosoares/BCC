#include <stdio.h>
#include <stdlib.h>
int main() {
  int numero, Rdivisao = 0;
  system("cls");
  printf("Insira o numero desejado: ");
  scanf("%d", &numero);
  for (int i = 1; i <= numero; i++) {
    if (numero % i == 0) {
      Rdivisao++;
    }
  }
  if (Rdivisao > 2) {
    printf("%d nao e primo", numero);
  } else {
    printf("%d e primo", numero);
  }
  return 0;
}