#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
main(){
    setlocale(LC_ALL,"");
    int linhas=4, colunas=4, i,j;
    int matriz1[4][4], matriz2 [4][4], matriz3[4][4];
    for (i=0; i<linhas; i++) {
    for(j=0; j<colunas; j++)
    {
        printf("Insira os números da primeira Matriz [%d][%d]:",i+1,j+1);
        scanf("%d",&matriz1[i][j]);
        printf("Insira os números da segunda Matriz [%d][%d]",i+1,j+1);
        scanf("%d",&matriz2[i][j]);
        matriz3[i][j]=matriz1[i][j]+matriz2[i][j];
    }
}
    printf("\n\nA soma das matrizes é: \n\n");
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++)
            printf("%3.d\t",matriz3[i][j]);
            printf("\n\n\n");
    }
    getch();
    return 0;
}
