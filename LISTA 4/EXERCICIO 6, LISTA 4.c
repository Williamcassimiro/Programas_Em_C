#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
main(){
    setlocale(LC_ALL,"");
    int cont=1000;
    while(cont<=1999){
        if(cont%11==5){
            printf("%d tem resto 5 quando dividido por 11!\n", cont);
            cont=cont+1;
        }
        else
            cont=cont+1;
    }
}
