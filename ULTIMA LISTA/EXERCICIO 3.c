#include <stdio.h>
#include <string.h>
main(){
    char str1[5]= "abcd";
    char str2[5]= "abce";
    int resposta;
    resposta= strcmp(str1,str2);
    printf("A resposta eh %d", resposta);
}
