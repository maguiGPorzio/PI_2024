/*
Se desea implementar un TAD para registrar la cantidad de apariciones de
elementos,de cualquier tipo
*/

#include "/home/mgonzalezporzio/PI/elemCountADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    elemtype eleme; //el elemeto
    size_t appear; //cantidad de apariciones
    struct element * nextElement;
}element;

struct elemCountCDT{
    compare cmp; //funcion de comparacion
    size_t amountDif; //cantidad de elementos distintos
    element * firstElem;
    element * next;
};

/* Crea todos los recursos para el TAD
 ** Arranca inicialmente sin elementos.
 */
 elemCountADT newElemCount(compare cmp){
    elemCountADT new=calloc(1,sizeof(struct elemCountCDT));
    new->cmp=cmp;
    return new;
 }

 static element *
 countElemRec(element * el, compare cmp, elemtype elem, size_t * app){
    int c;
    if (el == NULL || (c=cmp(el->eleme,elem)) > 0){
        element * new=malloc(sizeof(element));
        new->nextElement=el;
        new->appear=1;
        new->eleme=elem;
        return new;
    }

    if (!c){
      *app=++el->appear;
      return el;
    }

    el->nextElement=countElemRec(el->nextElement, cmp, elem, app);
    return el;
 }

 /* Registra una aparición de elem y retorna la cantidad actual de
 ** apariciones registradas.
 */
 size_t countElem(elemCountADT elemCountAdt, elemtype elem){
    size_t app=1;

    elemCountAdt->firstElem=countElemRec(elemCountAdt->firstElem, elemCountAdt->cmp, elem, &app);

    if (app == 1){
        elemCountAdt->amountDif++;
    }

    return app;
 }

 /* Retorna la cantidad de elementos distintos registrados. */
 size_t distinctElems(elemCountADT elemCountAdt){
    return elemCountAdt->amountDif;
 }

 /* Funciones de iteración para que se puedan consultar todos los elementos
 ** registrados en forma ordenada
 ** junto con la cantidad de apariciones de cada uno.
 */
 void toBegin(elemCountADT elemCountAdt){
    elemCountAdt->next=elemCountAdt->firstElem;
 }
 size_t hasNext(elemCountADT elemCountAdt){
    return elemCountAdt->next != NULL;
 }
 elemtype next(elemCountADT elemCountAdt, size_t * count){
    if (!hasNext(elemCountAdt)){
        exit(1);
    }
    elemtype aux=elemCountAdt->next->eleme;
    *count=elemCountAdt->next->appear;
    elemCountAdt->next=elemCountAdt->next->nextElement;
    return aux;
 }

 void
 freeRec(element * elems){
   if (elems == NULL){
      return;
   }

   element * aux=elems->nextElement;
   free(elems);
   freeRec(aux);
 }

 /* Libera los recursos utilizados por el TAD */
 void freeElemCount(elemCountADT elemCountAdt){
   freeRec(elemCountAdt->firstElem);
   free(elemCountAdt);
 }