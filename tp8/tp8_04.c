/*
Simular un juego de naipes de 52 cartas, en el cual se mezcle el mazo y se tomen las 5 primeras cartas, 
indicando si se obtuvo alguna de las siguientes configuraciones:
PAR:  hay sólo dos de las cinco cartas con igual valor
PIERNA:  hay sólo tres de las cinco cartas de igual valor
POKER: hay cuatro cartas con igual valor

Extender el punto anterior de modo tal que jueguen la computadora contra el usuario hasta que se acabe el 
mazo o el usuario decida no seguir jugando. Acumular los puntajes obtenidos por ambos jugadores considerando 
que el ganador de cada mano obtiene 1 punto y solo se considera empate (un punto para cada uno) una mano donde 
ambos jugadores tienen la misma configuración y con la misma figura (de coincidir sólo en configuración, gana 
aquella de figura mayor).
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT_PALOS 4
#define NUMS_POR_PALO 13
#define CANT_CARTAS 5

// Función para generar un número aleatorio normalizado en [0,1) 
double randNormalize(){
    return rand () / ((double) RAND_MAX+1);
}

// Función para generar un número entero aleatorio en el rango [left, right]
int randInt(int left, int right){
    return ((int)(randNormalize()*(right-left+1)) + left);
}

// Función para inicializar la semilla del generador de números aleatorios
void randomize(){
    srand ((int)time(NULL));
}

enum TIPO {PAR=1, PIERNA, POKER};

typedef struct naipes{
    char * palo;
    char * valor;
} naipes;


void
mezclar(naipes maso[], int cantCartas){
    int aleatorio;
    naipes aux;
    for (int i=0 ; i<cantCartas ; i++){
        aleatorio=randInt(i,cantCartas-1);
        aux=maso[i];
        maso[i]=maso[aleatorio];
        maso[aleatorio]=aux;
    }
}
int 
iguales (naipes carta, naipes cartas[], int cantCartas, int pos){
    int cantIguales=0;
    for (int i=pos ; i<cantCartas ; i++){
        if (carta.valor==cartas[i].valor){
            cantIguales++;
        }
    }
    return cantIguales;
}

int 
verCartas(naipes cartas[],int cantCartas){
    int cantIgual=0, aux=0;
    for (int i=0 ; i<cantCartas ; i++){
        cantIgual=iguales(cartas[i],cartas,cantCartas,i);
        if (cantIgual==POKER){
            return POKER;
        }
        if (cantIgual==PIERNA){
            return PIERNA;
        }
        if (cantIgual>aux){
            aux=cantIgual;
        }
    }
    return aux;
}

int 
main (){
    randomize();
    char * palos[] = {"Diamante", "Corazon", "Trebol", "Picas"};
    char * numeros[] = {"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "Jota", "Reina", "Rey"};

    naipes maso[CANT_PALOS*NUMS_POR_PALO];

    int h=0;

    for (int i=0 ; i<CANT_PALOS ; i++){
        for (int j=0 ; j<NUMS_POR_PALO ; j++){
            maso[h].palo=palos[i];
            maso[h].valor=numeros[j];
            h++;
        }
    }

    mezclar(maso, CANT_PALOS*NUMS_POR_PALO);

    naipes cartas[CANT_CARTAS];

    for (int i=0 ; i<CANT_CARTAS ; i++){
        cartas[i]=maso[i];
    }

    int cantIguales=verCartas(cartas,CANT_CARTAS);

    if (cantIguales==PAR){
        printf("PAR\n");
    }
    else if (cantIguales==PIERNA){
        printf("PIERNA\n");
    }
    else if (cantIguales==POKER){
        printf("POKER\n");
    }

    return 0;
}