#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, result;
    char operac;
    printf("Informe o primeiro valor: ");
    scanf("%f",&n1);
    printf("Informe o segundo valor: ");
    scanf("%f",&n2);
    fflush(stdin);
    printf("Informe a opera��o desejada: ");
    scanf("%c",&operac);
    if (operac== '+' ){
        result= n1+n2;
        printf("O resultado �: %f", result);
    }
    else{
        if (operac== '-' ){
            result= n1-n2;
            printf("O resultado �: %f", result);
        }
        else{
            if(operac== '*' ){
                result= n1*n2;
                printf("O resultado �: %f", result);
            }
        }
            if(operac== '/' ){
                result= n1/n2;
                printf("O resultado �: %f", result);
            }
    }
    return 0;
}
