/*
Escribir un programa que realice la simulación de un bingo para dos jugadores, el cual imprimirá
paso a paso la bolilla extraída y los números faltantes (que aún no salieron) de cada cartón. Las bolillas 
están
representadas por los números del 1 al 90 y cada jugador tiene un cartón con 15 números distintos. Los
cartones son generados por el programa en forma aleatoria. No es necesario conservar los números que se
van marcando en cada cartón (cuando hay coincidencia con la bolilla extraída)
El tipo de datos a utilizar para el cartón será :
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5
#define CANT_NUMS_BOLILLERO 90
#define FILS 3
#define COLS 5

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

void 
mezclar(int vec[]){ 
    int posAleatoria,aux;
    for (int i=0 ; i<CANT_NUMS_BOLILLERO ; i++){
        posAleatoria=randInt(i,CANT_NUMS_BOLILLERO-1);
        aux=vec[i];
        vec[i]=vec[posAleatoria];
        vec[posAleatoria]=aux;
    }
}

void
generarCarton(int cartones[][N*COLS], int vec[], int jugador){
    int h=0;
    for (int i=0 ; i<FILS ; i++){
        for (int j=jugador*COLS ; j<COLS+(jugador*COLS); j++){
            cartones[i][j]=vec[h++];
        }
    }
}

void
generarCartones(int cartones[][N*COLS], int cantJugadores){
    int vec[CANT_NUMS_BOLILLERO];
    for (int i=0 ; i<CANT_NUMS_BOLILLERO ; i++){
        vec[i]=i+1;
    }

    for (int i=0 ; i<cantJugadores ; i++){
        mezclar(vec);
        generarCarton(cartones,vec,i);
    }
}

int 
sacarBolilla(int bolillas[], int *bolillero){
    int bolilla=bolillas[(*bolillero)-1];

    (*bolillero)--;

    return bolilla;
}

int 
buscarBolilla(int cartones[][N*COLS], int jugador, int bolilla){
    for (int i=0 ; i<FILS ; i++){
        for (int j=jugador*COLS ; j<COLS+(jugador*COLS); j++){
            if (bolilla==cartones[i][j]){
                cartones[i][j]=-1;
                return 1;
            }
        }
    }
    return 0;
}

int
controlarLinea(int cartones[],int jugador){
    for (int i=jugador*COLS ; i<COLS+jugador*COLS ; i++){
        if (cartones[i]!=-1){
            return 0;
        }
    }
    return 1;
}

int
controlarCarton(int cartones[][N*COLS], int jugador, int bolilla){
    int encontrado=buscarBolilla(cartones,jugador,bolilla), lineas=0;
    if (encontrado){
        for (int i=0 ; i<FILS ; i++){
            lineas+=controlarLinea(cartones[i],jugador);
        }
    }
    return lineas;
}

void
imprimirCarton(int cartones[][N*COLS], int jugador){
    printf("El carton del jugador %d ahora es: ", jugador+1);
    for (int i=0 ; i<FILS ; i++){
        for (int j=jugador*COLS ; j<COLS+(jugador*COLS); j++){
            if (cartones[i][j]!=-1){
                printf("| %d",cartones[i][j]);
            }
        }
    }
    printf("\n");
}


int *
jugar (int cartones[][N*COLS], int *dimGanadores){
    int bolillero=CANT_NUMS_BOLILLERO, bolillas[CANT_NUMS_BOLILLERO], bolilla, aux=0, lineas;
    int *ganadores;

    ganadores=malloc(N*sizeof(ganadores[0]));

    for (int i=0 ; i<CANT_NUMS_BOLILLERO ; i++){
        bolillas[i]=i+1;
    }
    mezclar(bolillas);

    while (aux!=FILS){
        bolilla=sacarBolilla(bolillas,&bolillero);
        for (int i=0 ; i<N ; i++){
            lineas=controlarCarton(cartones,i,bolilla);
            if (lineas>aux){
                aux=lineas;
            }

            if (lineas==FILS){
                ganadores[(*dimGanadores)++]=i+1;
            }

            imprimirCarton(cartones,i);
        }

    }
    ganadores=realloc(ganadores,(*dimGanadores)*sizeof(ganadores[0]));
    return ganadores;
}


int
main(){
    randomize();

    int cartones[FILS][N*COLS], *ganadores, cantGanadores=0;

    generarCartones(cartones,N);

    for (int i=0 ; i<FILS ; i++){
        printf("El carton %d es: ",i+1);
        for (int j=0 ; j<N*COLS ; j++){
            printf("%4d",cartones[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    ganadores=jugar(cartones,&cantGanadores);

    
    for (int i=0 ; i<cantGanadores ; i++){
        printf("El ganador fue el jugador: ");
        printf("%d", ganadores[i]);
        printf("\n");
    }
    printf("\n");

    free(ganadores);
    
    return 0;
}

