#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
main(){
    setlocale(LC_ALL,"");
    char resp;
    int num;
    printf("Informe um caractere: ");
    scanf("%c",&resp);
        printf("Operador inv�lido!");
    switch(resp){
    case 'a':
        printf("Esta � uma vogal!");
        break;
    case 'e':
        printf("Esta � uma vogal!");
        break;
    case 'i':
        printf("Esta � uma vogal!");
        break;
    case 'o':
        printf("Esta � uma vogal!");
        break;
    case 'u':
        printf("Esta � uma vogal!");
        break;
    case '!':
        printf("Este � um caracter especial!");
        break;
    case '@':
        printf("Este � um caracter especial!");
        break;
    case '#':
        printf("Este � um caracter especial!");
        break;
    case '$':
        printf("Este � um caracter especial!");
        break;
    case '%':
        printf("Este � um caracter especial!");
        break;
    default:
        printf("Esta � uma consoante!");
    }
    return 0;
}
