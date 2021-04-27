#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL,"");
    float largura, altura, latas, litros, m2;
    printf("Informe a altura da parede: ");
    scanf("%f",&altura);
    printf("Informe a largura da parede: ");
    scanf("%f",&largura);
    m2= altura*largura;
    litros= m2*3;
    latas= litros/2;
    printf("A quantidade de latas necessárias é: %f", latas);
}
