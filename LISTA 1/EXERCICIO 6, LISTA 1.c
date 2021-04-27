#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    int b, delta, a, r1, r2, c;
    printf("Informe o valor de a: ");
    scanf("%d",&a);
    printf("Informe o valor de b: ");
    scanf("%d",&b);
    printf("Informe o valor de c: ");
    scanf("%d",&c);
    delta= (b*b)-4*(a*c);
    r1= (-b+sqrt(delta))/(2*a);
    r2= (-b-sqrt(delta))/(2*a);
    printf("Raiz 1 é igual a: %d\nRaiz 2 é igual a: %d", r1, r2);
    return 0;
}
