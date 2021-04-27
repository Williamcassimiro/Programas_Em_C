#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, n3;
    printf("Informe o primeiro valor: ");
    scanf("%f",&n1);
    printf("Informe o segundo valor: ");
    scanf("%f",&n2);
    printf("Informe o terceiro valor: ");
    scanf("%f",&n3);
    if ((n1<n2)&&(n2<n3))
        printf("%f, %f, %f", n1, n2, n3);
    else{
        if ((n2<n1)&&(n1<n3))
            printf("%f, %f, %f", n2, n1, n3);
        else{
            if((n3<n1)&&(n1<n3))
                printf("%f, %f, %f", n3, n1, n2);
            else{
                if((n1<n3)&&(n3<n2))
                    printf("%f, %f, %f", n1, n3, n2);
                else{
                    if((n2<n3)&&(n3<n1))
                        printf("%f, %f, %f", n2, n3, n1);
                    else{
                        if((n3<n2)&&(n2<n1))
                            printf("%f, %f, %f", n3, n2, n1);
                    }
                }
            }
        }
    }
    return 0;
}
