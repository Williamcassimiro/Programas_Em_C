#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2;
    printf("Informe o número: ");
    scanf("%f",&n1);
    printf("Informe o segundo número: ");
    scanf("%f",&n2);
    if (n1>n2)
        printf("O número %f é o maior", n1);
    else{
        if(n2>n1)
            printf("O número %f é o maior", n2);
        else
            if(n2==n1)
                printf("Ambos são iguais");
    }
    return 0;
}
