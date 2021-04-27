#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

main(){
    char str[10]= "Vitor";
    int tam;
    tam= strlen(str);
    printf("A string %s vale %d\n", str, tam);
    getch();
    return 0;
}
