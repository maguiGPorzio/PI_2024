/*
Escribir un programa que realice la simulación de un bingo para dos jugadores, el cual imprimirá
paso a paso la bolilla extraída y los números faltantes (que aún no salieron) de cada cartón. Las bolillas 
están
representadas por los números del 1 al 90 y cada jugador tiene un cartón con 15 números distintos. Los
cartones son generados por el programa en forma aleatoria. No es necesario conservar los números que se
van marcando en cada cartón (cuando hay coincidencia con la bolilla extraída)
El tipo de datos a utilizar para el cartón será :

//CHECKED EN GITHUB
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CANT_NUMS_BOLILLERO 90
#define FILS 3
#define COLS 5

typedef int TipoLinea[5];
typedef TipoLinea TipoCarton [3];

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

int
elegirCantidadJugadores (){
    int cantJugadores; 
    do{
        printf("Ingrese la cantidad de jugadores: ");
        scanf("%d",&cantJugadores);
        while (getchar()!='\n');
    }
    while (cantJugadores<1);

    return cantJugadores;
}

void 
mezclar(int bolillero[], int dim){ 
    int posAleatoria,aux;
    for (int i=0 ; i<dim ; i++){
        posAleatoria=randInt(i,dim-1);
        aux=bolillero[i];
        bolillero[i]=bolillero[posAleatoria];
        bolillero[posAleatoria]=aux;
    }
}

void 
generarCarton(TipoCarton * cartones, int bolillero[], int jugador){
    int h=0;
    printf("El carton del jugador %d es: \n",jugador+1);
    for (int i=0 ; i<FILS ; i++){
        for (int j=0 ; j<COLS ; j++){
            cartones[jugador][i][j]=bolillero[h++];
            printf("%4d",cartones[jugador][i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void
generarCartones(TipoCarton * cartones, int cantJugadores){ 
    int bolillero[90];

    for (int i=0 ; i<CANT_NUMS_BOLILLERO ; i++){
        bolillero[i]=i+1;
    }

    for (int i=0 ; i<cantJugadores ; i++){
        mezclar(bolillero,CANT_NUMS_BOLILLERO);
        generarCarton(cartones,bolillero,i);
    }

}
 
int 
sacarBolilla(int bolillero[], int * bolillas){ 
    int bolilla=bolillero[(*bolillas)-1];
    (*bolillas)--;
    return bolilla;
}

int
buscarBolilla(TipoCarton * cartones, int jugador, int bolilla){
    for (int i=0 ; i<FILS ; i++){
        for (int j=0 ; j<COLS ; j++){
            if (cartones[jugador][i][j]==bolilla){
                cartones[jugador][i][j]=-1;
                return 1;
            }
        }
    }
    return 0;
}

int 
controlarLinea (TipoCarton * cartones, int jugador, int fila){
    for (int i=0 ; i<COLS ; i++){
        if (cartones[jugador][fila][i]!=-1){
            return 0;
        }
    }
    return 1;
}

int
controlarCarton(TipoCarton * cartones, int jugador, int bolilla){
    int encontrada=buscarBolilla(cartones,jugador,bolilla), lineas=0;
    if (encontrada){
        for (int i=0 ; i<FILS ;i++){
            lineas+=controlarLinea(cartones,jugador,i);
        }
    }
    return lineas;
}

void
imprimirCarton (TipoCarton * cartones, int jugador){
    printf("El carton del jugador %d ahora es: ", jugador+1);
    for (int i=0 ; i<FILS ; i++){
        for (int j=0 ; j<COLS ; j++){
            if (cartones[jugador][i][j]!=-1){
                printf("|%4d",cartones[jugador][i][j]);
            }
        }
    }
    printf("\n");
}

int *
jugar(TipoCarton * cartones, int cantJugadores, int * h){
    int bolillero[CANT_NUMS_BOLILLERO];
    for (int i=0 ; i<CANT_NUMS_BOLILLERO ; i++){
        bolillero[i]=i+1;
    }
    mezclar(bolillero,CANT_NUMS_BOLILLERO);

    int aux=0, bolilla, bolillas=CANT_NUMS_BOLILLERO, lineas;
    int * ganadores=malloc(cantJugadores*sizeof(int));
    while (aux!=FILS){
        bolilla=sacarBolilla(bolillero,&bolillas);
        for (int i=0 ; i<cantJugadores ; i++){
            lineas=controlarCarton(cartones,i,bolilla);
            if (aux<lineas){
                aux=lineas;
            }
            if (lineas==FILS){
                ganadores[(*h)++]=i+1;
            }
            imprimirCarton(cartones,i);
        }
    }
    ganadores=realloc(ganadores,(*h)*sizeof(int));
    return ganadores;
}

int
main(){
    randomize();

    int cantJugadores, dimGanadores=0;
    cantJugadores=elegirCantidadJugadores(); 
    
    TipoCarton * cartones=malloc(cantJugadores*sizeof(TipoCarton));
    generarCartones(cartones, cantJugadores);

    int * ganadores=jugar(cartones,cantJugadores,&dimGanadores);

    for (int i=0 ; i<dimGanadores ; i++){
        printf("El ganador fue el jugador: ");
        printf("%d", ganadores[i]);
        printf("\n");
    }
    printf("\n");

    free(ganadores);
    free(cartones);
    
    return 0;
}
