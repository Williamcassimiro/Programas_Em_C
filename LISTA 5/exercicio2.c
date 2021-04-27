#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
main(){
    char letra;
    int diarias, x=0;
    float valor_diarias, valor_taxa, valor_total;
    do{
        printf("Informe a quantas diarias vc vai querer\n");
        scanf("%d",&diarias);
        valor_diarias = diarias * 50.00;
        if(diarias < 15){
            valor_taxa = 4.00;
        }else if(diarias > 15){
            valor_taxa = 3.00;
        }else{
            valor_taxa = 3.60;
        }
        valor_total = valor_diarias + (diarias * valor_taxa);
        printf("O valor total das diarias será: %f.\n caso deseje encerrar digite 'n'\n", valor_total);
        scanf("%c", &letra);
        if(letra == 'n' || letra == 'N'){
            x=1;
        }
    }while(x==0);
}
