#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
main(){
    setlocale(LC_ALL,"");
    char str1[25]= "Ciência da Computação";
    char str2[17]= " UTFPR 2019.";
    strncat(str1, str2, 15);
    printf("string = %s\n", str1);
    getch();
    return 0;
}
