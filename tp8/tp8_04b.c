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
#define CANT_CARTAS_PARTIDO 5
#define CANT_JUGADORES 2
#define CANT_FIGURAS 3

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

typedef struct naipes{ //caracterizacion cartas
    int palo;
    int valor;
} naipes;

typedef struct puntos{ //caracterizacion puntaje
    int computadora;
    int usuario;
} puntos;


void
mezclar(naipes maso[], int cantCartas){//mezcla el maso de cartas 
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
verCartas(naipes cartas[],int cantCartas){ //verifica cuantas cartas tienen el mismo valor
    int apariciones[NUMS_POR_PALO]={0};
    int aux, max=1, aparicion;

    for (int i=0 ; i<cantCartas ; i++){
        aux=cartas[i].valor;
        apariciones[aux]++;
    }
    
    for (int i=0 ; i<cantCartas ; i++){
        aux=cartas[i].valor;
        aparicion=apariciones[aux];
        if (max<aparicion){
            max=aparicion;
        }
    }
    return max;
}

void
repartir (naipes * maso, naipes cartasUsuario[], naipes cartasComputadora[]){
    int i=0,j=0,h=0;
    while (i<CANT_CARTAS_PARTIDO){
        cartasUsuario[i++]=maso[h++];
        cartasComputadora[j++]=maso[h++];
    }
}
void 
imprimirCartas(char * palos[], char * numeros[], naipes cartas[], char jugador[]){
    printf("Las cartas %s son: ", jugador);
    for (int i=0 ; i<CANT_CARTAS_PARTIDO ; i++){
        printf("%s de %s ", numeros[cartas[i].valor],palos[cartas[i].palo]);
    }
    puts("");
}

puntos *
revisarPuntaje(naipes cartasUsuario[], naipes cartasComputadora[]){
    puntos * puntajeActualizado=malloc(sizeof(puntos));

    puntajeActualizado->computadora=1;
    puntajeActualizado->usuario=1;

    int numsUsuario[NUMS_POR_PALO]={0};
    int numsComputadora[NUMS_POR_PALO]={0};

    for (int i=0 ; i<CANT_CARTAS_PARTIDO ; i++){
        numsComputadora[cartasComputadora[i].valor]+=1;
        numsUsuario[cartasUsuario[i].valor]+=1;
    }

    for (int i=NUMS_POR_PALO-1 ; i>NUMS_POR_PALO-1-CANT_FIGURAS ; i--){
        if (numsUsuario[i]>numsComputadora[i]){
            puntajeActualizado->computadora=0;
            return puntajeActualizado;
        }

        if (numsUsuario[i]<numsComputadora[i]){
            puntajeActualizado->usuario=0;
            return puntajeActualizado;
        }
    }

    return puntajeActualizado;
}

void 
imprimirConfiguracion(int puntaje,char jugador[]){
    puts("");
    printf("%s ", jugador);
    if (puntaje==2){
        printf("HIZO PAR\n");
    }
    else if (puntaje==3){
        printf("HIZO PIERNA\n");
    }
    else if (puntaje==4){
        printf("HIZO POKER\n");
    }
    else{
        printf("TIENE TODAS LAS CARTAS DE DISTINTO VALOR\n");
    }
}

puntos * 
jugar(naipes * maso){

    static char * palos[] = {"Diamante", "Corazon", "Trebol", "Picas"};
    static char * numeros[] = {"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "Jota", "Reina", "Rey"};

    puntos * puntaje=malloc(sizeof(puntos));

    naipes cartasUsuario[CANT_CARTAS_PARTIDO],cartasComputadora[CANT_CARTAS_PARTIDO];

    repartir(maso,cartasUsuario,cartasComputadora);

    imprimirCartas(palos,numeros,cartasComputadora,"de la computadora");
    imprimirCartas(palos,numeros,cartasUsuario,"del usuario");

    puntaje->computadora=verCartas(cartasComputadora, CANT_CARTAS_PARTIDO);
    imprimirConfiguracion(puntaje->computadora,"La computadora");
    puntaje->usuario=verCartas(cartasUsuario, CANT_CARTAS_PARTIDO);
    imprimirConfiguracion(puntaje->usuario,"El usuario");

    if ((puntaje->computadora)==(puntaje->usuario)){
        free(puntaje);
        puntaje=revisarPuntaje(cartasUsuario,cartasComputadora);
    }
    else if ((puntaje->computadora)>(puntaje->usuario)){
        puntaje->computadora=1;
        puntaje->usuario=0;
    }
    else{
        puntaje->computadora=0;
        puntaje->usuario=1;
    }

    return puntaje;
}

int 
main (){
    randomize();

    naipes maso[CANT_PALOS*NUMS_POR_PALO];
    puntos * puntaje;

    puntos puntajeTotal;
    puntajeTotal.usuario=0;
    puntajeTotal.computadora=0;

    int h=0;

    for (int i=0 ; i<CANT_PALOS ; i++){
        for (int j=0 ; j<NUMS_POR_PALO ; j++){
            maso[h].palo=i;
            maso[h].valor=j;
            h++;
        }
    }

    mezclar(maso, CANT_PALOS*NUMS_POR_PALO);

    char c;
    int cartasTotales=CANT_PALOS*NUMS_POR_PALO;

    printf("Ingrese EOF para salir del juego: \n");
    for (int j=0 ; ((c=getchar())!=EOF) && (j+10<cartasTotales) ; j+=10){
        while ((c=getchar())!='\n');
        puntaje=jugar(maso+j);
        puts("");
        printf("El puntaje del usuario es %d, y el de la computadora es %d\n",puntaje->usuario, puntaje->computadora);
        puntajeTotal.usuario+=puntaje->usuario;
        puntajeTotal.computadora+=puntaje->computadora;
        free(puntaje);
        puts("");
        printf("Quedan %d cartas en el maso\n",CANT_PALOS*NUMS_POR_PALO-j-10);
        printf("Ingrese EOF para salir del juego: \n");
    }

    printf("Se termino el juego. El puntaje de la computadora es %d y el del usuario %d \n",puntajeTotal.computadora,puntajeTotal.usuario);
    return 0;
}