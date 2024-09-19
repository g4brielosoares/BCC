#include <stdio.h>
#include <stdlib.h>
int main() {
  float f, c;
  system("cls");
  printf("Digite a temperatura em Fahrenheit: ");
  scanf("%f", &f);
  c = 5 * (f - 32) / 9;
  printf("A temperatura em Celcius e = %.1f", c);
  return 0;
}