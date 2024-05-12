#include <stdio.h>
#include "getnum.h"
#define MAX_ENTERO 1023

int main(void)
{
    int decimal;
    long binario;
    int pot;

    do
    {
        printf("Ingrese un nÃºmero entero (entre 0 y %d):", MAX_ENTERO);
        decimal = getint("");
        if (decimal < 0 || decimal > MAX_ENTERO)
            puts("Error de entrada");
    } while (decimal < 0 || decimal > MAX_ENTERO);

    for (binario = 0, pot = 1; decimal > 0; decimal /= 2, pot *= 10)
        if (decimal % 2)
            binario += pot;

    printf("\nEquivalente binario: %ld\n", binario);

    return 0;
}