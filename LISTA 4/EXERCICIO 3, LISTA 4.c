#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    setlocale(LC_ALL,"");
    int n, fat;
    printf("Informe um n�mero: ");
    scanf("%d",&n);
    for(fat=1; n>1; n=n-1)
        fat=fat*n;
    printf("O fatorial � %d", n, fat);
}
