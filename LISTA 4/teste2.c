#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
    setlocale(LC_ALL,"");
    int i, n;
    float invfat, result, result2;
    printf("Digite o N:\n");
    scanf("%d", &n);
    result = 1.0;
    invfat = 1.0;
    for(i=1; i<=n; i++){
        invfat = invfat * 1.0/i;
        result = result + invfat;
    }
    result2= result-1;
    printf("O valor de E é: %f\n", result2);
}
