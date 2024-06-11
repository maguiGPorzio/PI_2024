#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/moveToBackADT.h"

typedef struct elementList{
    elemType element;
    struct elementList * nextElement;
}elementList;

struct moveToBackCDT{
    elementList * firstElement;
    size_t amountElements;
};

/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío */
moveToBackADT newmoveToBack(){
    moveToBackADT newElements=calloc(1,sizeof(struct moveToBackCDT));
    return newElements;
}

void freemoveToBackRec(elementList * list){
    if (list == NULL){
        return;
    }

    elementList * aux=list->nextElement;
    free(list);
    freemoveToBackRec(aux);
}

/* Libera todos los recursos del TAD */
void freemoveToBack(moveToBackADT m){
    freemoveToBackRec(m->firstElement);
    free(m);
}

static elementList * 
isPresent(elementList * listElem,elemType elem){
    if (listElem ==  NULL){
        return NULL;
    }

    if (!compare(listElem->element,elem)){
        return listElem;
    }

    return isPresent(listElem->nextElement, elem);
}

/* Inserta un elemento si no está en el conjunto. Lo inserta al
principio.
** Retorna 1 si lo agregó, 0 si no.
*/
unsigned int add(moveToBackADT m, elemType elem){
    if (isPresent(m->firstElement,elem) != NULL){
        return 0;
    }

    elementList * listElem=malloc(sizeof(elementList));
    listElem->element=elem;
    listElem->nextElement=m->firstElement;
    m->firstElement=listElem;

    m->amountElements++;

    return 1;
}

/* Retorna una copia del elemento. Si no existe retorna NULL.
** Si el elemento estaba lo intercambia con el que sigue. */
elemType * 
getElement(moveToBackADT m, elemType elem){

    elementList * aux=isPresent(m->firstElement, elem);

    if (aux == NULL){
        return NULL;
    }

    elemType * copy=malloc(sizeof(elemType));
    *copy=aux->element;

    if (aux->nextElement != NULL){
        aux->element=aux->nextElement->element;
        aux->nextElement->element=*copy;
    }

    return copy;
}

/* Retorna la cantidad de elementos que hay en el conjunto */
unsigned int size(const moveToBackADT m){
    return m->amountElements;
}

/* Retorna un vector con todos los elementos del conjunto
** y deja en *dim la dimensión del vector
** Si el conjunto es vacío retorna NULL y dim no cambia.
*/
elemType * getAll(const moveToBackADT m, size_t * dim){
    if (m->amountElements == 0){
        return NULL;
    }

    elemType * vec=malloc(m->amountElements * sizeof(elemType));
    elementList * aux=m->firstElement;
    int i=0;
    for ( ; i < m->amountElements ; i++){
        vec[i]=aux->element;
        aux=aux->nextElement;
    }
    *dim=i;
    return vec;
}

static elementList *
deleteRec(elementList * listElem, elemType elem, int * deleted){
    if (listElem == NULL){
        return listElem;
    }

    if (!compare(listElem->element, elem)){
        elementList * aux=listElem->nextElement;
        free(listElem);
        *deleted=1;
        return aux;
    }

    listElem->nextElement=deleteRec(listElem->nextElement,elem,deleted);
    return listElem;
}

/* Elimina un elemento si está en el conjunto.
** Retorna 1 si lo borró, 0 si no.
*/
unsigned int delete(moveToBackADT m, elemType elem){
    int deleted=0;
    m->firstElement=deleteRec(m->firstElement, elem, &deleted);
    m->amountElements-=deleted;
    return deleted;
}