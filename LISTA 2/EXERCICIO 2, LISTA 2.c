#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Informe o n�mero: ");
    scanf("%d",&n);
    if (n%2==0)
        printf("Este n�mero � par.");
    else
        printf("Este n�mero � �mpar.");
    return 0;
}
