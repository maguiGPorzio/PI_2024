#include <stdio.h>
#include <math.h>
#include "getnum.h"


double redondeo(double numero, unsigned int cifras);
unsigned int menu(void);

int
main(void)
{
    float num;
    int opcion;

    num = getfloat("\nIngrese un numero real:");

    opcion = menu();
    if (opcion >= 1 && opcion <= 4)
        printf("El numero es %g\n", redondeo(num, opcion - 1));
    else
        printf("Opción inválida\n");

    return 0;
}

unsigned int menu(void)
{
    int opcion;

    printf("\n1 - Redondeo al entero más cercano\n");
    printf("2 - Redondeo a la décima más cercana\n");
    printf("3 - Redondeo a la centésima más cercana\n");
    printf("4 - Redondeo a la milésima más cercana\n");

    do {
        opcion = getint("Ingrese una opción:");
    } while (opcion < 0);
    
    return opcion;
}

double
redondeo(double numero, unsigned int cifras)
{
    long factor;

    for (factor = 1; cifras; factor *= 10, cifras--)
        ;

    return floor(numero * factor + 0.5) / factor;
}