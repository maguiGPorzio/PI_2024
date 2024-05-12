/*
Ejercicio 9
Escribir un programa (en no más de 15 líneas) para encontrar raíces de funciones en un intervalo dado. 
Se deberá recorrer el intervalo a incrementos de 0.001, evaluando la función en cada paso y escribiendo por salida estándar los 
puntos que son raíces. Los extremos del intervalo serán de tipo real y su valor estará dado por constantes del programa. 
Tener en cuenta no sólo el caso en el que el resultado de evaluar la función sea cero, sino también 
aquellos puntos en los cuales la función cambia de signo.
*/


#include <stdio.h>
#include <math.h>
#define INCREMENTO 0.001
#define POSITIVO 1
#define NEGATIVO 0
#define EPSILON 0.00001



double funcion(double x);

int
main (){
	int signoAnterior, signoActual; 
	double extremoIzq=-4, extremoDer=4;
	
	signoAnterior=((funcion(extremoIzq)<0) ? NEGATIVO : POSITIVO);
	
	while (extremoIzq<extremoDer){
		if (fabs(funcion(extremoIzq))<EPSILON){
			printf("\n %g es raiz\n", extremoIzq);
		}
		else{
			signoActual=((funcion(extremoIzq)<0) ? NEGATIVO : POSITIVO);
			if (signoActual!=signoAnterior){
				printf("\n %g es raiz\n", extremoIzq);
				signoAnterior=signoActual;
			}
		}
		extremoIzq+=INCREMENTO;
	}
	return 0;
}

double
funcion(double x)
{
    return sin(x);
}