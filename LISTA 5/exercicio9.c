#include <stdio.h>


void main()

{

    int  num, binario, decimal = 0, base = 1, x;



    printf("Digite o numero binario (1 e 0) \n"); scanf("%d", &num);

    binario = num;

    while (num > 0)

    {

        x = num % 10;

        decimal = decimal + x * base;

        num = num / 10 ;

        base = base * 2;

    }

    printf("O numero Binario é = %d \n", binario);

    printf("O seu equivalente em decimal sera = %d \n", decimal);

}
