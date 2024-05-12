#include <stdio.h>
#include "getnum.h"

#define DIGITO 5
#define ERROR 0.000000001

int main(void)
{
    float x;
    long parteEntera;
    int contador = 0;

    x = getfloat("Ingrese un número real: ");
    printf("\nNúmero leído: %20.9f\n", x);

    if (x < 0)
        x *= -1;

    parteEntera = (long)x;
    x = x - parteEntera;

    while (parteEntera != 0)
    {
        if ((parteEntera % 10) == DIGITO)
            contador++;
        parteEntera /= 10;
    }

    printf("\nDígitos iguales a %d en parte entera:  %d\n",
           DIGITO, contador);
    contador = 0;

    while (x > ERROR)
    {
        x *= 10;
        parteEntera = (long)x;
        if (parteEntera == DIGITO)
            contador++;
        x = x - parteEntera;
    }

    printf("\nDígitos iguales a %d en parte decimal: %d\n",
           DIGITO, contador);
    return 0;
}