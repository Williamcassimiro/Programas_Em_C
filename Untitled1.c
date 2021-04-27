#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
main(){
    setlocale(LC_ALL,"");
    char string[10];
    char str1[5]="abcd";
    strcpy(string,str1);
    puts(string);
}
