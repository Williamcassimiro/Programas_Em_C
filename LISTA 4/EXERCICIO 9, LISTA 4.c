#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
main(){
    setlocale(LC_ALL"");
    int n, cont1, cont2, fat;
    float resultado;
    printf("Informe um n�mero: ");
    scanf("%d",&n);
    cont1= 1;
    cont2=1;
    for (cont2=1;cont2<=n;cont2++)
        fat=n*(n-1);
    //N�O SEI COMO FAZER DAQUI PRA FRENTE, SINTO MUITO.
