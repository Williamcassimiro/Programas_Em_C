#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    int n1, n2, n3, tipo, a, b, c;
    printf("Informe o valor do primeiro lado: ");
    scanf("%d",&n1);
    printf("Informe o valor do segundo lado: ");
    scanf("%d",&n2);
    printf("Informe o valor do terceiro lado: ");
    scanf("%d",&n3);
    if ((n1>n2&&n3)){
        a= n1;
        b= n2;
        c= n3;
    }
    else{
        if(n2>n1&&n3){
            a= n2;
            b= n1;
            c= n3;
        }
        else{
            if(n3>n1&&n2){
                a= n3;
                b= n2;
                c= n1;
            }
            else{
                if((n1==n2)&&(n2==n3))
                    a= n1;
                    b= n2;
                    c=n3;
            }
        }
    }
    printf("O maior lado �: %d\n", a);
    if (a>(b+c))
        printf("N�o � um tri�ngulo!");
    else{
        if(a*a==(b*b)+(c*c))
            printf("� um tri�ngulo ret�ngulo!");
        else{
            if(a*a>(b*b)+(c*c))
                printf("� um tri�ngulo obtus�ngulo!");
            else{
                if(a*a<(b*b)+(c*c))
                    printf("� um tri�ngulo acut�ngulo!");
                else{
                    if((a==b)&&(b==c))
                        printf("� um tri�ngulo equil�tero!");
                    else{
                        if((a==b)||(a==c))
                            printf("� um tri�ngulo is�sceles!");
                    }
                }
            }
        }
    }
    return 0;
}
