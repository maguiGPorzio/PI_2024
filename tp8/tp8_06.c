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


#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bibliotecas/getnum.h"
#define EPSILON 0.00001
#define FUNCION(x) ( (2*x*x) - (4*x) )
#define PARTICIONES 100000
#define BLOCK 10

typedef double particion[2];

typedef struct intervalos{
    double extremoInf;
    double extremoSup;
} intervalos;

typedef struct raices{
    particion * raices;
    int cantRaices;
} raices;



int
main (){
    intervalos extremos;
    double paso= solicitarExtremos(&extremos);
    mostrarExtremos(&extremos);

    raices raicesFun=buscarRaices(&extremos,paso);

    for (int i=0 ; i<raicesFun.cantRaices ; i++){
        printf("%f ,", raicesFun.raices[i][0]);
        printf("%f", raicesFun.raices[i][1]);
        puts("");
    }
    printf("%d\n",raicesFun.cantRaices);

    free(raicesFun.raices);
    return 0;
}

double
solicitarExtremos (intervalos * p){ //LISTO
    (p->extremoInf)=getdouble("Ingrese el extremo izquierdo del intervalo: ");
    do{ 
        (p->extremoSup)=getdouble("Ingrese el extremo derecho del intervalo: ");
    }
    while ((p->extremoInf)>(p->extremoSup));

    double paso = (inter->b - inter->a)/PARTICIONES;

    return paso;
}

void
mostrarExtremos(intervalos * p){ //LISTO
    printf("El extremo inferior es: %f\n",p->extremoInf);
    printf("El extremo superior es: %f\n",p->extremoSup);
}

raices
buscarRaices (intervalos * intervalo, double paso){
    raices raicesFuncion;
    double valorAnterior=FUNCION(intervalo->extremoInf), valorActual;

    raicesFuncion.raices=NULL;
    raicesFuncion.cantRaices=0;
    
    for (double i=intervalo->extremoInf ; i<=(intervalo->extremoSup) ; i+=paso){
        
        valorActual=FUNCION(i);

        if ((raicesFuncion.cantRaices)%BLOCK==0){
            raicesFuncion.raices=realloc(raicesFuncion.raices,((raicesFuncion.cantRaices)+BLOCK)*sizeof(raicesFuncion.raices[0]));
        }
    
        if (fabs(valorActual)<EPSILON && fabs(valorAnterior)>EPSILON){
            raicesFuncion.raices[raicesFuncion.cantRaices][0]=valorAnterior;
        }
        else if (fabs(valorActual)>EPSILON && fabs(valorAnterior)<EPSILON){
            raicesFuncion.raices[(raicesFuncion.cantRaices)++][1]=valorActual;
        }
        else if (signo(valorActual)!=signo(valorAnterior)){
            raicesFuncion.raices[raicesFuncion.cantRaices][0]=valorAnterior;
            raicesFuncion.raices[(raicesFuncion.cantRaices)++][1]=valorActual;
        }
        
        valorAnterior=valorActual;
    }
    raicesFuncion.raices=realloc(raicesFuncion.raices,raicesFuncion.cantRaices);
    return raicesFuncion;
}

int
signo (double valor){
    if (valor<0){
        return -1;
    }
    return 1;
}