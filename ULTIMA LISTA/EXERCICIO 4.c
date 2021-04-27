#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
main(){
    setlocale(LC_ALL,"");
    char nome[15];
    strcpy(nome, "VITOR HUGO");
    printf("Olá %s", nome);
}
