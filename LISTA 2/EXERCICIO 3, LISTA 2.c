#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2;
    printf("Informe o n�mero: ");
    scanf("%f",&n1);
    printf("Informe o segundo n�mero: ");
    scanf("%f",&n2);
    if (n1>n2)
        printf("O n�mero %f � o maior", n1);
    else{
        if(n2>n1)
            printf("O n�mero %f � o maior", n2);
        else
            if(n2==n1)
                printf("Ambos s�o iguais");
    }
    return 0;
}
