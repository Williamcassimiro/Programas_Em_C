#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    setlocale(LC_ALL,"");
    int cont=85;
    while(cont<=723){
        if(cont%7==0){
            printf("%d é divisor de 7!\n", cont);
            cont=cont+1;
        }
        else
            cont=cont+1;
    }

}
