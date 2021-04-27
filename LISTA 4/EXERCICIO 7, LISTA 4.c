#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    setlocale(LC_ALL,"");
    int n;
    float i, soma;
    printf("Digite um número: ");
    scanf("%d",&n);
    soma=0;
    for(i=1;i<=n;i++){
        float resultado=1/i;
        printf("\nTermo: %.2f", resultado);
        soma=soma+resultado;
    }
    printf("\nA soma dos termos é: %c %.3f\n", 160, soma);
    return 0;
}
