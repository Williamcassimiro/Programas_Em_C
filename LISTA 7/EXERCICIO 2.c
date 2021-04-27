#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
main(){
    setlocale(LC_ALL,"");
    int i, j, x, cb=2, lb=2, ca=2, la=2;
    int matriza[la][ca], matrizb[lb][cb], matrizc[la][cb], zero=0;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                printf("Informe os números da Matriz A: ");
                scanf("%d",&matriza[i][j]);
            }
            printf("\n");
        }
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                printf("Informe os números da Matriz B:");
                scanf("%d",&matrizb[i][j]);
            }
            printf("\n");
        }
     for(i=0; i<2; i++){
         for(j=0; j<2; j++){
             matrizc[i][j]=0;
                 for(x=0; x<2; x++){
                     zero+= matriza[i][x] * matrizb[x][j];
                 }
                 matrizc[i][j]=zero;
                 zero=0;
         }
     }
        printf("Matriz resultada da multiplicação: \n\n");
            for(i=0;i<2;i++){
                for(j=0;j<2;j++){
                    printf("%6.d",matrizc[i][j]);
                }
                printf("\n\n");
            }
            printf("\n\n");
}
