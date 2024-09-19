#include <stdio.h>
#include <stdlib.h>
int main() {
  int numero, total = 1;
  system("cls");
  printf("Voce deseja ver o fatorial de qual numero? ");
  scanf("%d", &numero);
  for(int i = numero; i > 0; i--) {
    total = i * total;
  }
  printf("O valor de %d fatorial e %d", numero, total);
  return 0;
}