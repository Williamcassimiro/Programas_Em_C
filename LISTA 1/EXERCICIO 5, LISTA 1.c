/*Exercício 5, Lista 1
Aluno: Vitor Hugo Batistella
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float raio, vol;
    printf("Informe o raio da esfera: ");
    scanf("%f", &raio);
    vol= (4*3.14*raio*raio*raio)/3;
    printf("O volume desta esfera é: %.2f", vol);
    return 0;
}
