#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    int n,x;
    float e = 0;
    printf("Informe a quantidade de numeros\n");
    scanf("%d",&n);
    for(x=1; x <= n; x++){
        if(x%2 == 0){
            e-=1.00/x;
        }else{
            e+=1.00/x;
        }
    }
    printf("resultado: %f",e);
}
