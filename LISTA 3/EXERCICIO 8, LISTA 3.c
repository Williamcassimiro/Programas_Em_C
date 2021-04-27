#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL,"");
    float x, y, quadrante;
    printf("Informe a posição de X: ");
    scanf("%f",&x);
    printf("Informe a posição de Y: ");
    scanf("%f",&y);
    if(x<0&&y<0)
        printf("Terceiro quadrante!");
    else{
        if(x<0&&y>0){
            printf("Segundo quadrante!");
        }
        else{
            if(x>0&&y>0){
                printf("Primeiro quadrante!");
            }
            else{
                if(x>0&&y<0){
                    printf("Quarto Quadrante!");
                }
                else{
                    if(x==0&&y==0)
                        printf("Se encontra no 0!");
                }
                }
        }
    }
}
