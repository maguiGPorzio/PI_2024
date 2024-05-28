#include "/home/mgonzalezporzio/PI/tp11/moveToFrontADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    elemType head;
    struct node * tail;
} node;

typedef node * ls;

struct moveToFrontCDT{
    ls list;
    ls next;
    size_t size;
    compare cmp;
};

/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío */
moveToFrontADT 
newMoveToFront(compare cmp){
    moveToFrontADT new=calloc(1,sizeof(struct moveToFrontCDT));
    new->cmp=cmp;
    return new;
}
static void
freeList(ls list){
    if (list==NULL){
        return;
    }

    ls aux=list->tail;
    free(list);
    freeList(aux);
}

/* Libera toda la memoria reservada por el TAD */
void freeMoveToFront(moveToFrontADT moveToFront){
    freeList(moveToFront->list);
    free(moveToFront);
}

static ls
addAux(elemType elem){
    ls newNode=malloc(sizeof(node));
    newNode->head=elem;
    newNode->tail=NULL;
    return newNode;
}

static ls
addRec(ls list, elemType elem, compare cmp, int * esta){
    if (list == NULL){
        *esta=0;
        ls new=addAux(elem);
        return new;
    }

    if (!cmp(list->head,elem)){
        *esta=1;
        return list;
    }

    list->tail=addRec(list->tail, elem, cmp, esta);
    return list;
}
 
/* Inserta un elemento si no está. Lo inserta al final.
** Retorna 1 si lo agregó, 0 si no.
*/
unsigned int add(moveToFrontADT moveToFront, elemType elem){

    int esta=0;
    moveToFront->list=addRec(moveToFront->list,elem, moveToFront->cmp, &esta);
    moveToFront->size+=!esta;

    return !esta;
}
  
/* Retorna la cantidad de elementos que hay en la colección */
unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->size;
}
 
/* Se ubica al principio del conjunto, para poder iterar sobre el mismo */
void toBegin(moveToFrontADT moveToFront){
    moveToFront->next=moveToFront->list;
}

/* Retorna 1 si hay un elemento siguiente en el iterador, 0 si no */
int hasNext(moveToFrontADT moveToFront){
    return moveToFront->next != NULL;
}

/* Retorna el siguiente elemento. Si no hay siguiente elemento, aborta */
elemType next(moveToFrontADT moveToFront){
    if (!hasNext(moveToFront)){
        exit(1);
    }

    elemType elem=moveToFront->next->head;
    moveToFront->next=moveToFront->next->tail;
    return elem;
}

static ls
getRec(ls list,elemType elem,compare cmp, ls * direcElem){
    if (list == NULL){
        return list; 
    }

    if (!cmp(list->head,elem)){
        *direcElem=list;
        return list->tail;
    }

    list->tail=getRec(list->tail, elem, cmp, direcElem);
    return list;
}

/* Retorna una copia del elemento. Si no existe retorna NULL.
** Para saber si el elemento está, usa la función compare. 
** Si el elemento estaba lo ubica al principio.
 */
elemType *
get(moveToFrontADT moveToFront, elemType elem){

    ls direcElem=NULL; //me guardo la direccion de memoria del elemento en caso de que este
    moveToFront->list=getRec(moveToFront->list, elem, moveToFront->cmp, &direcElem);

    if (direcElem != NULL){
        //lo muevo al principio el elemento
        direcElem->tail=moveToFront->list;
        moveToFront->list=direcElem;
        
        elemType * elemento=malloc(sizeof(elemType));
        *elemento=direcElem->head;

        return elemento;
    }

    return NULL;
}