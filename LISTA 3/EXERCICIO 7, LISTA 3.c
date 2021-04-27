#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
main(){
    setlocale(LC_ALL,"");
    float sat, snovo;
    char cargo;
    printf("Informe o salário atual: ");
    scanf("%f",&sat);
    fflush(stdin);
    printf("Informe o código do cargo: ");
    scanf("%c",&cargo);
    switch(cargo){
        case 'A':{
            snovo= sat*1.10;
            printf("O salário passou de %.2f reais para:\n %.2f reais", sat, snovo);
            break;
        }
        case 'T':{
            snovo= sat*1.30;
            printf("O salário passou de %.2f reais para:\n %.2f reais", sat, snovo);
            break;
        }
        case 'E':{
            snovo= sat*1.20;
            printf("O salário passou de %.2f reais para:\n %.2f reais", sat, snovo);
            break;
        }
        default:{
            snovo= sat*1.40;
            printf("O salário passou de %.2f reais para:\n %.2f reais", sat, snovo);
        }
    }
    return 0;
}
