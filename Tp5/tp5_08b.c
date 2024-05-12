/*
Escribir un programa que ofrezca el siguiente menú para redondear un número x de varias formas e utilice 
la función anterior para cada una de ellas:

Redondeo al entero más cercano 
Redondeo a la décima más cercana.
Redondeo a la centésima más cercana.
Redondeo a la milésima más cercana.
*/

#include <stdio.h>
#include "getnum.h"
#include <math.h>

double redondeo(double numero, int decimales);
int menu ();

int
main (){
    float numero=getfloat("Ingrese el numero que desee redondear: ");
    int opcion;
    do {
        opcion=menu();
    }
    while (opcion<1 || opcion>4);

    printf("%g\n",redondeo(numero,opcion-1));
}

int
menu (){
    int opcion;
    printf("1-Redondeo al entero más cercano\n");
    printf("2-Redondeo a la décima más cercana\n");
    printf("3-Redondeo a la centésima más cercana\n");
    printf("4-Redondeo a la milésima más cercana\n");
    return opcion=getint(" ");
}

double
redondeo(double numero, int decimales){
    long factor;
    for (factor=1 ; decimales ; factor*=10, decimales--);
    return floor((numero*factor)+0.5)/factor;
}