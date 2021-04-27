//Exercício 1, Lista 1
//Aluno: Vitor Hugo Batistella
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
main()
{
    float nota, media, cont, acum;
    setlocale(LC_ALL, "Portuguese");
    cont= 1;
    acum= 0;
    while(cont<=4){
        printf("Informe uma nota: ");
        scanf("%f",&nota);
        cont= cont+1;
        acum= acum+nota;
    }
    media= acum/4;
    printf("A média é: %.2f\n", media);
    system("pause");
    return 0;
}
