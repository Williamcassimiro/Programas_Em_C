#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float n;
    printf("Informe o n�mero: ");
    scanf("%f",&n);
    if (n>=0)
        printf("Este n�mero � positivo.");
    else
        printf("Este n�mero � negativo.");
    return 0;
}
