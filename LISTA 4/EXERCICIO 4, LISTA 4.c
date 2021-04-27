#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
main(){
    setlocale(LC_ALL,"");
    int b, exp, exponencial;
    printf("Informe a base: ");
    scanf("%d",&b);
    printf("Informe o expoente: ");
    scanf("%d",&exp);
    exponencial= pow(b,exp);
    printf("O exponencial é: %d", exponencial);
}
