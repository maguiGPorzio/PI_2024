/*
Una partícula realiza un camino aleatorio dentro de un círculo de acuerdo a la siguientes reglas:
En tiempo t = 0 la partícula está en el centro ( x = 0, y = 0).
La partícula hace un paso aleatorio en una de las cuatro direcciones dada por
x = x - 1
x = x + 1
y = y - 1
y = y + 1
La caminata termina cuando se sale fuera del círculo ( x2 + y2>= r2 ).

Considerando cada punto como una estructura de componentes cartesianas y teniendo en cuenta que el 
tiempo se mide con un contador que se incrementa  en cada paso de la partícula, escribir un programa 
que para distintos tamaños de círculos determine experimentalmente la relación entre el tiempo requerido 
para terminar la caminata y el valor del radio.

Mostrar los valores hallados mediante una tabla cuyas columnas sean:
Radio
Tiempo
Relación (radio / tiempo)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R_MINIMO 10
#define R_MAXIMO 1000

typedef struct {
    int x,y; 
} tipoPunto;


/* Simula el movimiento de una partícula dentro de un círculo partiendo desde un origen dado.
** Retorna la cantidad de unidades de tiempo que tarda en salir del circulo 
*/
int simulacion(int radio, tipoPunto origen);

/* genera un movimiento aleatorio en forma vertical u horizontal 
** actualizando la posición de la partícula 
*/
void mover (tipoPunto *particula);

/* devuelve 1 si la posición de la partícula esta fuera del circulo */
int salio (tipoPunto particula, int radio);


int
main (void) {
	unsigned long tiempo;
	int radio;

	srand(time(NULL));

	printf("\n\nSimulacion del movimiento de una particula\n");
	printf ("\n%10s%10s%10s\n","Radio","Tiempo","T/R");
	printf ("----------------------------------\n");

	tipoPunto orig = {0,0};
	for (radio = R_MINIMO; radio < R_MAXIMO; radio+= (R_MAXIMO-R_MINIMO)/10) {
		tiempo = simulacion( radio, orig);
		printf ("%10d%10lu%10.2f\n",radio,tiempo,(float)tiempo/radio);
	}

	printf("\n\n");

	return 0;
}

// No recibimos un puntero a tipoPunto porque es un struct con solo dos int
int 
simulacion(int radio, tipoPunto origen) {
	unsigned long tiempo;

	tiempo = 0;
	do {
		tiempo++;
		mover ( &origen );
	} while (!salio(origen, radio));

	return tiempo;
}

 
void
mover(tipoPunto *particula) {
	int i;
	i = rand() % 4;
	switch (i)
	{
		case 0: particula->x--; break;
	    case 1: particula->y--; break;
		case 2: particula->x++; break;
	    case 3: particula->y++; break;
	}
	/* Otra forma de hacerlo seria :
	*	static int movim[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	*
	* 	i= randInt(0, sizeof(movim)/sizeof(movim[0]));
	*
	*	particula->x += movim[i][0];
	*	particula->y += movim[i][1];
	*/
}

// TODO: hacer una macro y no una función
int 
salio (tipoPunto particula, int radio) {
	return ( (particula.x * particula.x + particula.y * particula.y) > radio * radio );
}