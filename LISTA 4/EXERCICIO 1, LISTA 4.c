#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL,"");
    float a, cont=1;
    int  cont2=0;
    while(cont<=5){
        printf("Informe o valor de a: ");
        scanf("%f",&a);
        cont=cont+1;
        if(a<0)
            cont2= cont2+1;
    }
    printf("Há %d números negativos!", cont2);
}
