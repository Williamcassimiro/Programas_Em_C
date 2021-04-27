#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
main(){
    setlocale(LC_ALL,"");
    int idade, dias, meses, anos;
    printf("Informe a idade em dias: ");
    scanf("%d",&idade);
    dias= idade;
    anos= idade/365;
    meses= anos*12;
    printf("Esta pessoa viveu por\n %d em dias\n %d em meses\n %d em anos", dias, meses, anos);
    return 0;
}
