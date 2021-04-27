/*Exercício 4, Lista 1
Aluno: Vitor Hugo Batistella
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float c, f;
    printf("Informe graus Celsius: ");
    scanf("%f", &c);
    f= (9*c+32)/5;
    printf("A temperatura em Fahrenheit é: %.2f\n", f);
    system("pause");
    return 0;
}
