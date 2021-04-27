#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
main(){
    setlocale(LC_ALL,"");
    char resp;
    int num;
    printf("Informe um caractere: ");
    scanf("%c",&resp);
        printf("Operador inválido!");
    switch(resp){
    case 'a':
        printf("Esta é uma vogal!");
        break;
    case 'e':
        printf("Esta é uma vogal!");
        break;
    case 'i':
        printf("Esta é uma vogal!");
        break;
    case 'o':
        printf("Esta é uma vogal!");
        break;
    case 'u':
        printf("Esta é uma vogal!");
        break;
    case '!':
        printf("Este é um caracter especial!");
        break;
    case '@':
        printf("Este é um caracter especial!");
        break;
    case '#':
        printf("Este é um caracter especial!");
        break;
    case '$':
        printf("Este é um caracter especial!");
        break;
    case '%':
        printf("Este é um caracter especial!");
        break;
    default:
        printf("Esta é uma consoante!");
    }
    return 0;
}
