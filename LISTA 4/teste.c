#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
    setlocale(LC_ALL,"");
    int i, n;
    float fat, result;
    printf("Digite um numero:\n");
    scanf("%d", &n);
    result = 1.0;
    fat = 1.0;
    for(i=1; i<=n; i++){
        fat = fat * i;
        result = result + 1.0/fat;
    }
    //printf("%f\n", fat);
    printf("O valor de E é: %f\n", result);
    return 0;
}
