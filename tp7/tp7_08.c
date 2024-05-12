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
#define NUMS_BOLILLERO 90
#define FILS_CARTON 3
#define COLS_CARTON 5

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

void 
mezclar(int vec[]){ //CHECKED
    int posAleatoria,aux;
    for (int i=0 ; i<NUMS_BOLILLERO ; i++){
        posAleatoria=randInt(i,NUMS_BOLILLERO-1);
        aux=vec[i];
        vec[i]=vec[posAleatoria];
        vec[posAleatoria]=aux;
    }
}

void
cartonAleatorio (TipoCarton carton, int vec[]){ //CHECKED
    int h=0;
    for (int i=0 ; i<FILS_CARTON ; i++){
        for (int j=0 ; j<COLS_CARTON  ; j++){
            carton[i][j]=vec[h++];
        }
    }
}

void 
generarCarton(TipoCarton carton, int cantNums){ //CHECKED
    int vec[NUMS_BOLILLERO];
    for (int i=0 ; i<NUMS_BOLILLERO ; i++){
        vec[i]=i+1;
    }

    mezclar(vec);

    cartonAleatorio(carton, vec);
}

int
sacarBolilla(int bolillero[], int * cantBolillas){ //CHECKED

    int bolilla=bolillero[(*cantBolillas)-1];

    (*cantBolillas)--;

    return bolilla;
}

int 
controlarLinea(TipoLinea linea){ //CHECKED
    for (int i=0 ; i<COLS_CARTON ; i++){
        if (linea[i]!=-1){
            return 0;
        }
    }
    return 1;
}

int
buscarBolilla(TipoCarton carton, int bolilla, int numsCarton){ //CHECKED
    for (int i=0 ; i<FILS_CARTON ; i++){
        for (int j=0 ; j<COLS_CARTON; j++){
            if (bolilla==carton[i][j]){
                carton[i][j]=-1;
                return 1;
            }
        }
    }
    return 0; 
}

int
controlarCarton(TipoCarton carton, int bolilla, int numsCarton){ 
    int encontrado, lineas=0;
    encontrado=buscarBolilla(carton,bolilla,numsCarton);
    if (encontrado){
        for (int i=0 ; i<FILS_CARTON; i++){
            lineas+=controlarLinea(carton[i]);
        }
    }
    return lineas;
}

void
imprimirCarton(TipoCarton carton){
    for (int i=0 ; i<FILS_CARTON ; i++){
        for (int j=0 ; j<COLS_CARTON ; j++){
            if (carton[i][j]!=-1){
                printf("%4d",carton[i][j]);
                printf("|");
            }
        }
    }
    printf("\n");
}

int
jugar (TipoCarton carton1,TipoCarton carton2, int numsCarton){
    int bolillero[NUMS_BOLILLERO]={0}, bolilla, cantBolillas=NUMS_BOLILLERO , lineasCompletas1=0, lineasCompletas2=0, aux;
    
    for (int i=0 ; i<NUMS_BOLILLERO ;i++){
        bolillero[i]=i+1;
    }

    mezclar(bolillero);

    bolilla=sacarBolilla(bolillero, &cantBolillas);

    lineasCompletas1=controlarCarton(carton1,bolilla,numsCarton);
    lineasCompletas2=controlarCarton(carton2,bolilla,numsCarton);

    while (lineasCompletas1!=FILS_CARTON && lineasCompletas2!=FILS_CARTON){

        bolilla=sacarBolilla(bolillero, &cantBolillas);

        aux=controlarCarton(carton1,bolilla,numsCarton);
        lineasCompletas1=((aux) ? (aux) : (lineasCompletas1));

        aux=controlarCarton(carton2,bolilla,numsCarton);
        lineasCompletas2=((aux) ? (aux) : (lineasCompletas2));

        printf("Los numero que todavia no salieron del carton 1 son: ");
        imprimirCarton(carton1);

        printf("Los numero que todavia no salieron del carton 2 son: ");
        imprimirCarton(carton2);

    }

    if (lineasCompletas1==FILS_CARTON && lineasCompletas2==FILS_CARTON){
        return 11;
    }
    else if (lineasCompletas1==FILS_CARTON){
        return 10;
    }
    else{
        return 1;
    }
}


int
main(){
    randomize();

    int numsCarton=FILS_CARTON * COLS_CARTON, ganador;
    TipoCarton carton1, carton2;

    generarCarton(carton1,numsCarton);
    generarCarton(carton2,numsCarton);

    ganador=jugar(carton1,carton2,numsCarton);

    if (ganador==11){
        puts("Ambos ganaron");
    }
    else if (ganador==10){
        puts("El ganador fue el jugador 1");
    }
    else{
        puts("El ganador fue el jugador 2");
    }
}

