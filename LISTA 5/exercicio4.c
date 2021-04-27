#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
main(){
    int n,x;
    float valor = 1,valor_total = 1;
    printf("Informe a quantidade de numeros\n");
    scanf("%d",&n);
    for(x=1; x < n; x++){
        valor *= 2;
        valor_total += valor;
    }
    printf("resultado: %f",valor_total);
}
