/*
Ejercicio 8
La función floor puede ser utilizada para redondear un número a una cantidad específica de lugares decimales. 
Por ejemplo,  floor( x * 100 + .5 ) / 100  redondea x a la posición de los centésimos.
Escribir una función redondeo que reciba dos parámetros de entrada correspondientes al número a redondear y 
la cantidad de cifras decimales que se desean, y que devuelva en su nombre el número redondeado (en no más de 5 líneas).
*/

#include <stdio.h>
#include "getnum.h"
#include <math.h>

double
redondeo(double numero, int decimales){
    long factor;
    for (factor=1 ; decimales ; factor*=10, decimales--);
    return floor((numero*factor)+0.5)/factor;
}

int
main (){
    float numero=getdouble("Ingrese el numero a redondear: \n");
    int decimales=getint("Ingrese la cantidad de decimales que se deseen: \n");
    printf("El numero %f redondeado es %f\n",numero,redondeo(numero,decimales));
    return 0;
}