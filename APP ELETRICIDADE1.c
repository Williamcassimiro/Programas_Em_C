#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

main(){
    int resis1,resis2,resis3, auxiliar;
    float resiseq;
    char tipoass;
    auxiliar=resis1;
    printf("Informe o valor em ohms do primeiro resistor: ");
    scanf("%d",&resis1);
    if(resis1>=100000||resis1<=0||resis1!=auxiliar){
        do{
        printf("Valor inválido!\n");
        resis1=0;
        auxiliar=0;
        printf("Informe um valor válido para o primeiro resistor: ");
        scanf("%d",&resis1);
        auxiliar=resis1;
        }
        while(resis1>=100000||resis1<0||resis1!=auxiliar);
    }
}
    /*printf("Informe o valor em ohms do segundo resistor: ");
    scanf("%d",&resis2);
    if(resis2>=100000||resis2<0){
        do{
            printf("Valor inválido!\n");
            resis2=0;
            printf("Informe um valor válido para o segundo resistor: ");
            scanf("%d",&resis2);
        }
        while(resis2>=100000||resis2<0);
    }
    printf("Informe o valor em ohms do terceiro resistor: ");
    scanf("%d",&resis3);
    if(resis3>=100000||resis3<0){
        do{
        printf("Valor inválido!\n");
        resis3=0;
        printf("Informe um valor válido para o terceiro resistor: ");
        scanf("%d",&resis3);
        }
        while(resis3>=100000||resis3<0);
    }
}

