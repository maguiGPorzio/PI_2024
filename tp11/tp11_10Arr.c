#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/mgonzalezporzio/PI/tp11/tp11_ej10.h"
#define BLOCK 10

typedef struct elementos{
    elemType elemento;
    size_t cantApariciones;
} elementos;

struct bagCDT{
    elementos * totalElem;
    size_t dim;
    size_t size;
    compare cmp;
};

/**
** Retorna 0 si los elementos son iguales 
*/

/* Libera toda la memoria reservada por el TAD */
void freeBag(bagADT bag){
    free(bag->totalElem);
    free(bag);
}
 
/* Retorna un nuevo bag de elementos genéricos. Al inicio está vacío */
bagADT newBag(compare cmp){
    bagADT aux=calloc(1,sizeof(struct bagCDT));
    aux->cmp=cmp;
    return aux;
}
 
/* Inserta un elemento. Retorna cuántas veces está
** elem en el conjunto luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
unsigned int add(bagADT bag, elemType elem){

    elementos * aux;
    for (int i=0 ; i<bag->dim ; i++){
        aux=(bag->totalElem) + i;
        if (!bag->cmp(aux->elemento,elem)){
            aux->cantApariciones+=1;
            return aux->cantApariciones;
        }
    }

    if (bag->dim == bag->size){
        bag->size+=BLOCK;
        bag->totalElem=realloc(bag->totalElem,bag->size * sizeof(elementos));
    }

    aux= (bag->totalElem) + (bag->dim++);
    aux->cantApariciones=1;
    aux->elemento=elem;
    return 1;

}

/* Remueve una aparición de un elemento. Retorna cuántas veces está
** elem en el conjunto luego de haberlo borrado
*/
unsigned int delete(bagADT bag, elemType elem){
    
    elementos * aux;
    for (int i=0 ; i<bag->dim ; i++){
        aux=(bag->totalElem) + i;
        if (!bag->cmp(aux->elemento,elem)){
            aux->cantApariciones-=1;
            if (aux->cantApariciones == 0){
                aux->elemento=bag->totalElem[bag->dim - 1].elemento;
                aux->cantApariciones=bag->totalElem[bag->dim - 1].cantApariciones;
                bag->dim--;
                return 0;
            }
            return aux->cantApariciones;
        }
    }

    //si no esta que devuelve?
    return 0;
}

/* Retorna cuántas veces aparece el elemento en el bag */
unsigned int count(const bagADT bag, elemType elem){
    elementos * aux;
    for (int i=0 ; i<bag->dim ; i++){
        aux=(bag->totalElem) + i;
        if (!bag->cmp(aux->elemento,elem)){
            return aux->cantApariciones;
        }
    }

    return 0;
}
 
/* Retorna la cantidad de elementos distintos que hay en el bag */
unsigned int size(const bagADT bag){
    return bag->dim;
}
 
/* Retorna el elemento que aparece más veces. Si hay más de uno 
** con esa condición, retorna cualquiera de los dos. 
** Precondicion: el bag no debe estar vacio. En caso de estar vacío, aborta
** la ejecución
*/
elemType mostPopular(bagADT bag){
    if (bag->totalElem == NULL){
        exit(1);
    }

    int maxApar=bag->totalElem->cantApariciones;
    elemType elemMaxApar=bag->totalElem->elemento;

    elementos * aux;
    for (int i=1 ; i<bag->dim ; i++){
        aux=(bag->totalElem) + i;
        if (aux->cantApariciones > maxApar){
            maxApar=aux->cantApariciones;
            elemMaxApar=aux->elemento;
        }
    }

    return elemMaxApar;
}
