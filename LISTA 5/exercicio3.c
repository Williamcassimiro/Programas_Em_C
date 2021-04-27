#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
main(){
    int n,i;
    float a,valor = 1;
    printf("Informe o numero da raiz\n");
    scanf("%f",&a);
    printf("Informe a quantidade de interacoes\n");
    scanf("%d",&i);
    for(n=0; n <= i; n++){
        valor = 0.5*(valor + a/valor);
    }
    printf("%d interacoes, %f resultado",n-1,valor);
}
