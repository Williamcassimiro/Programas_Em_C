#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float n;
    printf("Informe o número: ");
    scanf("%f",&n);
    if (n>=0)
        printf("Este número é positivo.");
    else
        printf("Este número é negativo.");
    return 0;
}
