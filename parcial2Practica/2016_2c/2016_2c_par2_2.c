/*
Se desea generar un TAD que almacene un conjunto de elementos genéricos no repetidos. Para ello se propone el siguiente contrato:
( nota 2022: el código original era con void * )
Para la correcta implementación, es fundamental que las funciones size, max, min y last sean lo más eficientes posibles.
*/
#include <stdio.h>
#include <stdlib.h>
#include "parcial2Practica/2016_2c_par2_2.h"

typedef struct node {
	elemType elem;
	struct node * tail;
} TNode;

typedef TNode * TList;

struct setCDT{
    TList set;
    size_t size;
    TList max;
    TList min;
    TList last;
    compare cmp;
};


/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío */
setADT newSet(compare comp){
    setADT aux=calloc(1,sizeof(struct setCDT));
    aux->cmp=comp;
    return aux;
}


/* Inserta elem siempre y cuando el elemento no esté
** en el conjunto. Retorna la cantidad total de elementos luego de agregar el elemento nuevo
*/
int add(setADT set, elemType elem){
    int esta;
}


/* Retorna cuántos elementos hay en el conjunto */
int size(const setADT set);


/* Retorna una copia del mayor elemento del conjunto, NULL si no hay elementos */
elemType * max(const setADT set);


/* Retorna una copia del menor elemento del conjunto, NULL si no hay elementos */
elemType * min(const setADT set);


/* Retorna una copia del último elemento agregado en el conjunto, NULL si está vacío */
elemType * last(const setADT set);


/* Retorna un vector con todos los elementos del conjunto, ordenados en forma ascendente */
elemType * setToArray(const setADT set);
