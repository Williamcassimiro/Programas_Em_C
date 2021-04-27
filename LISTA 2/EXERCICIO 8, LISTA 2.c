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
    printf("O maior lado é: %d\n", a);
    if (a>(b+c))
        printf("Não é um triângulo!");
    else{
        if(a*a==(b*b)+(c*c))
            printf("É um triângulo retângulo!");
        else{
            if(a*a>(b*b)+(c*c))
                printf("É um triângulo obtusângulo!");
            else{
                if(a*a<(b*b)+(c*c))
                    printf("É um triângulo acutângulo!");
                else{
                    if((a==b)&&(b==c))
                        printf("É um triângulo equilátero!");
                    else{
                        if((a==b)||(a==c))
                            printf("É um triângulo isósceles!");
                    }
                }
            }
        }
    }
    return 0;
}
