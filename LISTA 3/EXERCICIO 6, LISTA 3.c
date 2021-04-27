#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL,"");
    float notaa, notab, notac, notad, media;
    char tipo;
    printf("Informe a primeira nota:");
    scanf("%f",&notaa);
    printf("Informe a segunda nota: ");
    scanf("%f",&notab);
    printf("Informe a terceira nota: ");
    scanf("%f",&notac);
    printf("Informe a quarta nota: ");
    scanf("%f",&notad);
    fflush(stdin);
    printf("Informe o tipo de média a ser calculada: ");
    scanf("%c",&tipo);
    switch(tipo){
        case '1':{
            media= (notaa+notab+notac+notad)/4;
            printf("A média aritmética é: %f", media);
            break;
        }
        case '2':{
            media= (4/((1/notaa)+(1/notab)+(1/notac)+(1/notad)));
            printf("A média harmônica é: %f", media);
            break;
        }
        case '3':{
            media= pow(notaa*notab*notac*notad,1.0/4.0);
            printf("A média geométrica é: %f", media);
            break;
        }
        case '4':{
            media= pow(((notaa*notaa)+(notab*notab)+(notac*notac)+(notad*notad))/4,1.0/2.0);
            printf("A média quadrática é: %f", media);
            break;
        }
    }
}
