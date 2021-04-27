/*Exercício 3, Lista 1
Aluno: Vitor Hugo Batistella
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float b, h, a;
    printf("Informe a base: ");
    scanf("%f", &b);
    printf("Informe a altura: ");
    scanf("%f", &h);
    a= b*h/2;
    printf("A área deste triângulo é: %.2f", a);
    return 0;
}
