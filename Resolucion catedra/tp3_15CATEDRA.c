#include <stdio.h>
#include "getnum.h"

/* Solo se consideran binarios positivos */
int main(void)
{
    int binario;
    int decimal = 0;
    int base = 1;
    int resto;

    binario = getint("Ingrese un numero binario (hasta 10 digitos):");

    for (base = 1; binario > 0; binario /= 10, base *= 2)
    {
        if ((resto = binario % 10) > 1)
        {
            puts("\nNo es un numero binario !!!");
            return 1;
        }
        else if (resto)
            decimal += base;
    }
    printf("\nEquivalente decimal = %d\n", decimal);

    return 0;
}