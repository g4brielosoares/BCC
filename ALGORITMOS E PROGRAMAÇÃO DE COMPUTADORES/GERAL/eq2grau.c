#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
  int a, b, c;
  float d, x1, x2;
  system("cls");
  printf("Escreva o valor de a:\n");
  scanf("%d", &a);
  printf("Escreva o valor de b:\n");
  scanf("%d", &b);
  printf("Escreva o valor de c:\n");
  scanf("%d", &c);
  d = pow(b,2) - (4 * a * c);
  x1 = (-(b) + sqrt(d)) / (2 * a);
  x2 = (-(b) - sqrt(d)) / (2 * a);
  printf("O valor de delta e %.1f\n", d);
  printf("O valor de x1 e %.0f\n", x1);
  printf("O valor de x2 e %.0f", x2);
  return 0;
}