#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
main(){
    setlocale(LC_ALL,"");
    int quant, cod;
    float valor;
    printf("Informe o código do item: ");
    scanf("%d",&cod);
    switch(cod){
        case 100:{
        printf("Informe a quantidade de cachorros quentes: ");
        scanf("%d",&quant);
        valor= quant*1.30;
        printf("O valor final é de: %.2f reais", valor);
        break;
        }
        case 101:{
        printf("Informe a quantidade de Baurus simples: ");
        scanf("%d",&quant);
        valor= quant*1.50;
        printf("O valor final é de: %.2f reais", valor);
        break;
        }
        case 102:{
        printf("Informe a quantidade de Baurus com ovo:" );
        scanf("%d",&quant);
        valor= quant*1.80;
        printf("O valor é de: %.2f reais", valor);
        break;
        }
        case 103:{
        printf("Informe a quantidade de Hamburgueres: ");
        scanf("%d",&quant);
        valor= quant*2.00;
        printf("O valor é de: %.2f reais", valor);
        break;
        }
        case 104:{
        printf("Informe a quantidade de X-Saladas: ");
        scanf("%d",&quant);
        valor= quant*3.00;
        printf("O valor é de: %.2f reais", valor);
        break;
        }
        case 105:{
        printf("Informe a quantidade de refrigerantes: ");
        scanf("%d",&quant);
        valor= quant*1.75;
        printf("O valor é de: %.2f reais", valor);
        break;
        }
        default:
            printf("Código de produto inválido!");
    }
    return 0;
}
