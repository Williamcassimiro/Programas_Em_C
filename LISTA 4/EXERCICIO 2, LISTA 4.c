#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
    setlocale(LC_ALL,"");
    int x,n, maior=-9999999, menor=9999999;
    for (x=1;x<=5;x++){
        printf ("Informe um n�mero: ");
        scanf ("%d", &n);
        if (n > maior)
            maior = n;
        if (n < menor)
            menor = n;
    }
    printf ("O maior numero � %d e o menor � %d\n", maior, menor);
}
