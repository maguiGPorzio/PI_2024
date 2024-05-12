/*
Ejercicio 7 
Escribir una función real para calcular aproximadamente el valor de ex  por  medio de la serie  1 + x + x2 / 2! + x3 / 3! + ....... 
Dicha función recibe como parámetros de entrada el valor de x. (En no más de 10 líneas)
Hacer un programa que invoque a la función y escriba el resultado de la misma y el valor de la función exp(x) de C.
	
¿Cómo harías para fijar la precisión de cálculo de la función?
*/

#include <stdio.h> 
#include <math.h>
#include "getnum.h"
#define EPSILON 0.0000001

double ex (double x);

int 
main (){
    double eEstimado, eReal, x;
    
	x = getfloat("Ingrese el valor de x para calcular exp(x): ");
	if (x < 0)
		printf("Solo para positivos\n");
	else
	{
		eEstimado = ex(x);
		eReal = exp(x);
		printf("\nValor calculado: %f\n", eEstimado);
		printf("Valor real: %f\n", eReal);
	}
	return 0;
}



double 
ex (double x){
    double valor=1,potencia=x;
    double factorial=1,anterior=0;
    if (x<0){
        return -1;
    }
    else{
        for (int i=2 ; valor-anterior>EPSILON ; i++){
            anterior=valor;
            valor+=potencia/factorial;
            potencia*=x;
            factorial*=i;
        }
        return valor;
    }
}

