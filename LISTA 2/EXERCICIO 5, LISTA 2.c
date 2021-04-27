#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    int idade;
    printf("Informe a idade: ");
    scanf("%d",&idade);
    if (idade<=12)
        printf("É uma criança!");
    else{
        if (idade<=17)
            printf("É um adolescente!");
        else{
            if (idade>=18)
                printf("É um adulto!");
        }
    }
    return 0;
}
