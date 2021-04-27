#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
main(){
    setlocale(LC_ALL,"");
    char sexo;
    float altura, pideal;
    printf("Informe a altura: ");
    scanf("%f",&altura);
    fflush(stdin);
    printf("Informe o sexo com M ou H: ");
    scanf("%c",&sexo);
    switch(sexo){
        case 'H': {
            pideal= ((72.7*altura)-58);
            printf("O peso ideal é: %f", pideal);
            break;
        }
        case 'M': {
            pideal= ((62.1*altura)-44.7);
            printf("O peso ideal é: %f", pideal);
            break;
        }
    }
}
