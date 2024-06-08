#include "/home/mgonzalezporzio/PI/multiSetADT.h"
#include <stdio.h>
#include <stdlib.h>
#define BLOCK 10

struct elem{
    elemType elem;
    size_t amountAp;
    struct elem * nextElem;
};

struct multiSetCDT{
    struct elem * firstElem;
    size_t count;
};

/* Retorna un nuevo multiSet de elementos genéricos. Al inicio está vacío */
multiSetADT newMultiSet(){
    multiSetADT new=calloc(1, sizeof(struct multiSetCDT));
    return new;
}

struct elem *
addRec(struct elem * elements, elemType elem, int * app){
    if (elements == NULL || elem < elements->elem){ //deberia usar compare pero como tengo INTS en el programa de prueba use eso derecho 
        struct elem * new=calloc(1,sizeof(struct elem));
        new->elem=elem;
        new->amountAp=1;
        new->nextElem=elements;
        return new;
    }

    if (elem == elements->elem){
        elements->amountAp++;
        *app=elements->amountAp;
        return elements;
    }

    elements->nextElem=addRec(elements->nextElem, elem, app);
    return elements;
}

/* Inserta un elemento. Retorna cuántas veces está elem en el conjunto
** luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
unsigned int add(multiSetADT multiSet, elemType elem){
    int app=1;
    multiSet->firstElem=addRec(multiSet->firstElem,elem,&app);
    if (app == 1){
        multiSet->count++;
    }
    return app;
}

/* Retorna cuántas veces aparece el elemento en el multiSet */
unsigned int count(const multiSetADT multiSet, elemType elem){
    struct elem * aux=multiSet->firstElem;
    while (aux!=NULL){
        if (aux->elem == elem){
            return aux->amountAp;
        }
        aux=aux->nextElem;
    }
    return 0;
}

/* Retorna la cantidad de elementos distintos que hay en el multiSet */
unsigned int size(const multiSetADT multiSet){
    return multiSet->count;
}

struct elem *
removeRec(struct elem * elements, elemType elem, int * app){
    if (elements == NULL || elem < elements->elem){
        return elements;
    }

    if (elem == elements->elem){
        elements->amountAp--;
        if (elements->amountAp > 0){
            *app=elements->amountAp;
            return elements;
        }
        struct elem * aux=elements->nextElem;
        free(elements);
        return aux;
    }

    elements->nextElem=removeRec(elements->nextElem, elem, app);
    return elements;
}

/* Elimina una repetición del elemento. Retorna cuántas veces está elem el conjunto
** luego de haberlo borrado (si el elemento no estaba, retorna cero)
*/
int removes(multiSetADT multiSet, elemType elem){
    int app=0;
    multiSet->firstElem=removeRec(multiSet->firstElem, elem, &app);
    if (!app){
        multiSet->count--;
    }
    return app;
}

struct elem *
removeAllRec(struct elem * elements, elemType elem){
    if (elements == NULL || elem < elements->elem){
        return elements;
    }

    if (elem == elements->elem){
        struct elem * aux=elements->nextElem;
        free(elements);
        return aux;
    }

    elements->nextElem=removeAllRec(elements->nextElem, elem);
    return elements;
}

/* Elimina todas las apariciones de un elemento. */
void removeAll(multiSetADT multiSet, elemType elem){
    multiSet->firstElem=removeAllRec(multiSet->firstElem, elem);
}

/* Retorna un vector con los elementos que menos aparecen en el conjunto
** Si el conjunto está vacío retorna NULL
** En el parámetro de salida dim almacena la cantidad de elementos del vector
*/
elemType * minElements(const multiSetADT multiSet, int * dim){
    if (multiSet->firstElem == NULL){
        return NULL;
    }

    elemType * minElem=malloc(BLOCK * sizeof(elemType));
    int i=0, j=BLOCK;
    struct elem * aux=multiSet->firstElem->nextElem;
    elemType min=multiSet->firstElem->elem;
    minElem[i++]=min;

    while (aux!=NULL){
        if (i == j){
            j+=BLOCK;
            minElem=realloc(minElem, j * sizeof(elemType));
        }

        if (aux->elem == min){
            minElem[i++]=aux->elem;
        }
        else if (aux->elem < min){
            min=aux->elem;
            i=0;
            minElem[i++]=aux->elem;
        }

        *dim=i;
        aux=aux->nextElem;
    }

    return minElem;
}