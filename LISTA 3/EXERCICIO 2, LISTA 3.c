#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
main(){
    setlocale(LC_ALL,"");
    int n1, n2;
    printf("Informe o primeiro número: ");
    scanf("%d",&n1);
    printf("Informe o segundo número: ");
    scanf("%d",&n2);
    if (n1%n2==0)
        printf("Estes números são múltiplos!");
    else
        printf("Estes números não são múltiplos!");
    return 0;
}
