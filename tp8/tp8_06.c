/*
Escribir un programa para hallar las raíces de una función matemática en un intervalo cerrado, recorriéndolo 
de forma tal que el intervalo quede dividido en 100000 (cien mil) particiones o subintervalos. Ejemplo: 
si el intervalo es [1, 50000] deberá evaluar la función en los puntos 1, 1.5, 2, etc. (también se tomarán 
como válidos los puntos 1, 1.49999, etc ).
El programa deberá solicitar los extremos del intervalo, imprimiendo los resultados en la salida estándar. 
La función a evaluar recibe y devuelve un valor real y está dada por la macro FUNCION.
La función que realice la búsqueda de las raíces debe recibir como parámetros una estructura que represente 
al intervalo,  regresando en su nombre una estructura que empaquete un arreglo con aquellas particiones donde 
haya raíces y la dimensión de dicho arreglo.
Para detectar una raíz se deben considerar dos casos:
Que la función cambie de signo entre dos puntos: En ese caso se agrega al arreglo una partición con ambos 
puntos.
Que la función se haga cero en un punto (considerando un error de EPSILON): En ese caso la partición que se 
agrega al arreglo de resultados está formada por el punto anterior al que se detectó como raíz y el próximo 
que no lo sea.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/* Función a evaluar, en TP posterior verán cómo pasar como parámetro
   una función (punteros a funciones) 
*/
#define FUNCION(x)	(sin(x))
#define PASOS 		100000
#define EPSILON 	0.000001
#define BLOQUE		10

typedef struct {
	double a,b ;
} tipoIntervalo;

typedef struct {
	int dim;
	tipoIntervalo * lista;
} tipoRaices;
			
/* Dado un intervalo busca subintervalos con raíces */
tipoRaices buscar_raices(tipoIntervalo);

/* Almacena un intervalo en la estructura tipoRaices, de no haber espacio ejecuta realloc() */
int almacenarRaiz(tipoRaices * resp, tipoIntervalo inter, int nuevaRaiz);

/* Libera la respuesta cuando deja de ser necesaria */
void freeRaices(tipoRaices resp);

/* Realiza la lectura de los extremos del intervalo */
void leerExtremos(tipoIntervalo *extremos);

/* Función que imprime los resultados en salida estándar */
void verResultados(tipoRaices respuesta);

int
main(void) {
	int opcion;
	tipoRaices respuesta;
	tipoIntervalo extremos;

	leerExtremos(&extremos);
	respuesta = buscar_raices(extremos);
	verResultados(respuesta);	
	if (respuesta.dim >= 0)
		freeRaices(respuesta);

	return 0;
}
 

void
verResultados(tipoRaices respuesta) {
	int i;
	
	if (respuesta.dim == -1) {	/* Corresponde a error de malloc() */
		puts("Error en el almacenamiento de raíces");
	} else if (respuesta.dim > 0) {
		for (i = 0; i < respuesta.dim; i++)
			printf("Raíz %d en [%f,%f]\n",
 				i+1,respuesta.lista[i].a, respuesta.lista[i].b);
	}
	else {
		puts("\nNo hay raíces en ese intervalo");
	}
}

tipoRaices
buscar_raices(tipoIntervalo extr) {
	double x,fx,fxant, incremento;
	tipoRaices respuesta = {0, NULL};
	int esRaiz = 0, error = 0;
	tipoIntervalo intActual;

	incremento = (extr.b - extr.a) / PASOS ;

	if (incremento == 0 )
		incremento = 0.00001;  

	
	/* Se recorre el intervalo, evaluando la función en cada punto */
	x = extr.a;
	fxant = fx = FUNCION(x);
	while ( x <= extr.b && !error ) {
		if ( fx*fxant < 0  ||  fabs(fx) < EPSILON) {
			/* Con el flag esRaiz se controla que no se indique más de una vez la misma raíz.
 		    ** Si el punto anterior ya era raíz, entonces extender el intervalo
			*/
 			if ( ! esRaiz ) {
				intActual.a = x - incremento;	 
    		}

			/* Si se detectó un cambio de signo es porque hay una raíz entre el x 
 			** anterior y el actual por lo tanto el fin del intervalo es x.
			** En cambio si x es raíz el extremo derecho del intervalo será el próximo x 
	 		*/
       		if ( fx * fxant < 0 )
				intActual.b = x;
 		    else
				intActual.b = x + incremento;
				
			/* Se almacena el nuevo intervalo, o actualiza uno existente */
			if ( !almacenarRaiz(&respuesta, intActual, !esRaiz) )	
				error = 1;	
		
       		esRaiz = 1;
 	    } else
			esRaiz = 0;

		/* Paso al próximo punto */
		x += incremento;
		fxant = fx; 

		fx = FUNCION(x);

	}
	return respuesta;
}


int 
almacenarRaiz(tipoRaices * resp, tipoIntervalo inter, int nuevaRaiz) {
	errno=0;
	// Si es una nueva raiz vemos si es necesario agrandar el espacio
	if ( nuevaRaiz){
	   if(resp->dim % BLOQUE == 0)	{
            tipoIntervalo * aux;
            aux = realloc(resp->lista, (resp->dim + BLOQUE)*sizeof(*aux));
            if (aux==NULL || errno==ENOMEM) {
			    free(resp->lista);
			    resp->dim = -1;
			    return 0;
		    }
		    resp->lista = aux;
	   }	
	   resp->dim++;
	}

	/* Se  almacena/actualiza  el intervalo */
	resp->lista[resp->dim-1] = inter;
	return 1;
}

void
freeRaices(tipoRaices resp) {
	free(resp.lista);
}

 
void 
leerExtremos(tipoIntervalo *extremos) {
	float a, b;

	/* leer extremos del intervalo */
	a = 1;
	b = 50000;
	if (a<b) {
		extremos->a = a;	
 	    extremos->b = b;
	} else {
		extremos->b = a; 
 		extremos->a = b;
	}
}