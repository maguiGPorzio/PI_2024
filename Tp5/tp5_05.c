/*
Escribir una función potencia, que reciba en dos parámetros de entrada la base (de tipo double) y el exponente (entero), y devuelva el valor de dicha potencia (En no más de 10 líneas).
	Por ejemplo, potencia(2,-4) debe devolver 0.0625. En caso de no poder calcularse el resultado debe devolver –1.
*/

#include <stdio.h>
#include <math.h>
#include <errno.h>
#define EPSILON 0.00001

double potencia(double base, int exponente);

int 
main (){
    printf("La potencia es %g \n",potencia(0,-4));
    return 0;
}

double 
potencia(double base, int exponente){
    if ((fabs(base)<EPSILON) && exponente<=0){
        errno = EDOM;
        return -1;
    }
    else { 
        double potencia;
        potencia=base;
        for (int i=1; i<fabs(exponente);i++){
            potencia*=base;
        }
        if (exponente<0){
            return 1/potencia;
        }
        else {
            return potencia;
        }
    }
}