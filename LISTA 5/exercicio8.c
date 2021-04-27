/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{

	int numero, cifra;

	printf("Digite valores inteiros:\n");
	scanf("%i", &numero);

	if (numero >= 0) {
		do {
		    cifra = numero % 10;
		    printf("%i", cifra);
		    numero /= 10;
		} while (numero != 0);
		  printf ("\n");
	}
    /*
	else if (numero < 1) {
		numero = numero * -1;
		printf("-");                    \\inverter os numeros negativos
	}
		do {
   		      cifra = numero % 10;
		      printf("%i", cifra);
		      numero /= 10;
		} while (numero != 0);
		  		printf ("\n"); */
}
