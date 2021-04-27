#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float x1, x2, y1, y2, dist;
    printf("Informe o valor de x1: ");
    scanf("%f",&x1);
    printf("Informe o valor de x2: ");
    scanf("%f",&x2);
    printf("Informe o valor de y1: ");
    scanf("%f",&y1);
    printf("Informe o valor de y2: ");
    scanf("%f",&y2);
    dist= sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    printf("A distância é: %f", dist);
    return 0;
}
