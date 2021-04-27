#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, media;
    printf("Informe a primeira nota: ");
    scanf("%f",&n1);
    printf("Informe a segunda nota: ");
    scanf("%f",&n2);
    media= (n1+n2)/2;
    if (media>=6){
        printf("A média é %f\n", media);
        printf("Aluno aprovado!");
    }
    else{
        printf("A média é %f\n", media);
        printf("Aluno reprovado!");
    }
    return 0;
}
