#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
  float peso, altura, IMC;
  system("cls");
  printf("Qual o seu peso? ");
  scanf("%f", &peso);
  printf("Qual a sua altura? ");
  scanf("%f", &altura);
  IMC = peso / pow(altura, 2);
  printf("O seu IMC e %.1f\n", IMC);
  if (IMC < 18.5) {
    printf("Voce esta abaixo do seu peso ideal!");
  } else if (IMC >= 18.5 && IMC < 25.0) {
    printf("Voce esta no seu peso ideal!");
  } else if (IMC >= 25.0) {
    printf("Voce esta acima do seu peso ideal!");
  }
  return 0;
}