//Exercício 2, Lista 1
//Aluno: Vitor Hugo Batistella
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main () {
    float n1, n2, soma, sub, div, mult;
    setlocale(LC_ALL, "Portuguese");
    printf("Informe o primeiro valor: ");
    scanf("%f", &n1);
    printf("Informe o segundo valor: ");
    scanf("%f", &n2);
    soma= n1+n2;
    sub= n1-n2;
    div= n1/n2;
    mult= n1*n2;
    printf("A soma é: %.2f\nA subtração é: %.2f\nA divisão é: %.2f\nE a multiplicação é: %.2f", soma, sub, div, mult);

    return 0;
}
