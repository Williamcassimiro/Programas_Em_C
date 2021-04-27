/*Exercício 8, Lista 1
Aluno: Vitor Hugo Batistella
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float sbruto, s2, sliquido, ir, previd;
    printf("Informe o salário bruto: ");
    scanf("%f",&sbruto);
    s2= sbruto*0.915;
    previd= sbruto-s2;
    sliquido= s2*0.734;
    ir= s2-sliquido;
    printf("O valor destinado a previdência é: %.2f\nO valor destinado ao imposto de renda é: %.2f\nO salário liquido é: %.2f", previd, ir, sliquido);
    return 0;
}
