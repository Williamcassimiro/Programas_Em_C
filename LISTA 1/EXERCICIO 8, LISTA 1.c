/*Exerc�cio 8, Lista 1
Aluno: Vitor Hugo Batistella
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float sbruto, s2, sliquido, ir, previd;
    printf("Informe o sal�rio bruto: ");
    scanf("%f",&sbruto);
    s2= sbruto*0.915;
    previd= sbruto-s2;
    sliquido= s2*0.734;
    ir= s2-sliquido;
    printf("O valor destinado a previd�ncia �: %.2f\nO valor destinado ao imposto de renda �: %.2f\nO sal�rio liquido �: %.2f", previd, ir, sliquido);
    return 0;
}
