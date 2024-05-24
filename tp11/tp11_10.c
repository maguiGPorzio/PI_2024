#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/mgonzalezporzio/PI/tp11/tp11_ej10.h"
#define BLOCK 10


typedef struct node {
    elemType elemento;
    size_t cantApariciones;
    struct node * tail;
} node;

typedef struct node * TList;

struct bagCDT{
    node * totalElem;
    size_t dim;
    compare cmp;
};

static void
freeRec(TList totalElem){
    if (totalElem==NULL){
        return;
    }

    freeRec(totalElem->tail);
    free(totalElem);
}

/* Libera toda la memoria reservada por el TAD */
void freeBag( bagADT bag){
    freeRec(bag->totalElem);
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
unsigned int 
add(bagADT bag, elemType elem){
    TList aux=bag->totalElem;
    while (aux!=NULL){
        if (! bag->cmp(aux->elemento,elem)){
            aux->cantApariciones++;
            return aux->cantApariciones;
        }
        aux=aux->tail;
    }
    
    aux=malloc(sizeof(node));
    aux->cantApariciones=1;
    aux->elemento=elem;
    aux->tail=bag->totalElem;
    bag->totalElem=aux;
    bag->dim++;
    return 1;
}

TList
deleteRec(TList node, elemType elem, int * esta, compare cmp, size_t * dim){
    if (node==NULL){
        return NULL;
    }
    if (!cmp(elem,node->elemento)){
        node->cantApariciones-=1;
        if (node->cantApariciones == 0){
            TList aux=node->tail;
            free(node);
            *dim-=1;
            return aux;
        }
        *esta=node->cantApariciones;
        return node;
    }
    
    node->tail=deleteRec(node->tail,elem,esta,cmp,dim);
    return node;
}

/* Remueve una aparición de un elemento. Retorna cuántas veces está
** elem en el conjunto luego de haberlo borrado
*/
unsigned int 
delete(bagADT bag, elemType elem){
    int esta=0;
    bag->totalElem=deleteRec(bag->totalElem,elem,&esta,bag->cmp, & bag->dim);
    return esta;
}

/* Retorna cuántas veces aparece el elemento en el bag */
unsigned int count(const bagADT bag, elemType elem){
    TList aux=bag->totalElem;
    while (aux!=NULL){
        if (!bag->cmp(aux->elemento,elem)){
            return aux->cantApariciones;
        }
        aux=aux->tail;
    }
    return 0;
}
 
/* Retorna la cantidad de elementos distintos que hay en el bag */
unsigned int 
size(const bagADT bag){
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
    
    node auxPopular;
    auxPopular.cantApariciones=bag->totalElem->cantApariciones;
    auxPopular.elemento=bag->totalElem->elemento;

    TList aux=bag->totalElem;
    while (aux!=NULL){
        if (aux->cantApariciones > auxPopular.cantApariciones){
            auxPopular.cantApariciones=aux->cantApariciones;
            auxPopular.elemento=aux->elemento;
        }
        aux=aux->tail;
    }
    return auxPopular.elemento;
}