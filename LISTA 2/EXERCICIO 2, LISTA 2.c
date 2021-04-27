#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Informe o número: ");
    scanf("%d",&n);
    if (n%2==0)
        printf("Este número é par.");
    else
        printf("Este número é ímpar.");
    return 0;
}
