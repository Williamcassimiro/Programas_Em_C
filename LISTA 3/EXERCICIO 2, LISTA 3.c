#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
main(){
    setlocale(LC_ALL,"");
    int n1, n2;
    printf("Informe o primeiro n�mero: ");
    scanf("%d",&n1);
    printf("Informe o segundo n�mero: ");
    scanf("%d",&n2);
    if (n1%n2==0)
        printf("Estes n�meros s�o m�ltiplos!");
    else
        printf("Estes n�meros n�o s�o m�ltiplos!");
    return 0;
}
