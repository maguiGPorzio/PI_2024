/*Se desea implementar una colección que permita guardar elemType genéricos sin repeticiones. La colección se llamará rankingADT, 
ya que tiene la particularidad que tiene que servir para acceder fácilmente a los elemType que están al tope del ranking. Los elemType 
van "escalando posiciones" en el ranking a medida que son consultados.
Si la colección tiene N elemType, se dice que el que está en el tope del ranking está en el puesto 1. El que está último en el ranking 
está en el puesto N del ranking.

YA ME LO CORRIGIO MARCELO
*/

#include <stdio.h>
#include <stdlib.h>
#include "/home/mgonzalezporzio/PI/tp11/rankingADT.h"
#define BLOCK 10


struct rankingCDT {
    elemType * rank;
    size_t dim;
    size_t size;
    compare cmp;
};

static void
swap(rankingADT ranking, int index1, int index2){
    elemType aux=ranking->rank[index1];
    ranking->rank[index1]=ranking->rank[index2];
    ranking->rank[index2]=aux;
}

/* Crea un nuevo ranking. Recibe un vector con elemType, donde el primer
** elemento (elems[0]) está al tope del ranking (puesto 1), elems[1] en el 
** puesto 2, etc. Si dim es cero significa que no hay elemType iniciales
*/
rankingADT
newRanking(elemType elems[], size_t dim, compare cmp){
    rankingADT aux=malloc(sizeof(struct rankingCDT));
    aux->dim=dim;
    aux->size=dim;
    aux->cmp=cmp;
    aux->rank=NULL;
    
    if (dim==0){
        return aux;
    }

    aux->rank=realloc(aux->rank,dim * sizeof(aux->rank[0]));
    for (int i=0 ; i<dim ; i++){
        aux->rank[i]=elems[i];
    }

    return aux;
}

/* Agrega un elemento en la posición más baja del ranking, si no estaba.
** Si el elemento estaba, es equivalente a accederlo, por lo que sube un 
** puesto en el ranking
*/
void addRanking(rankingADT ranking, elemType elem){
    elemType * aux=ranking->rank;

    if (ranking->dim > 0 && !ranking->cmp(aux[0],elem)){
        return;
    }

    for (int i=1 ; i < ranking->dim ; i++){
        
        if (!ranking->cmp(aux[i],elem)){
            swap(ranking,i,i-1);
            return;
        }
    }


    if (ranking->size == ranking->dim){
        ranking->size+=BLOCK;
        ranking->rank=realloc(ranking->rank,ranking->size * sizeof(ranking->rank[0]));
    }
    ranking->rank[ranking->dim++]=elem;
}

/* La cantidad de elemType en el ranking */
size_t size(const rankingADT ranking){
    return ranking->dim;
}

/* Si n es una posición válida del ranking, guarda en elem el elemento que está 
** en el puesto n y retorna 1.
** Si no hay elemento en la posición n, retorna cero y no modifica *elem
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int getByRanking(rankingADT ranking, size_t n, elemType * elem){
    if (n > ranking->dim || n == 0){
        return 0;
    }

    *elem=ranking->rank[n-1];
    addRanking(ranking,ranking->rank[n-1]);
    return 1;
}

/* top: entrada/salida
** Recibe cuántos elemType al tope del ranking se desean 
** Almacena cuántos pudo guardar (ver ejemplos)
** Si el ranking está vacío *top queda en cero y retorna NULL
*/
elemType * 
getTopRanking(const rankingADT ranking, size_t * top){
    elemType * ranks=malloc(ranking->dim * sizeof(ranks[0]));
    size_t i=0;
    elemType * aux=ranking->rank;
    for (; i < ranking->dim && i < *top; i++){
        ranks[i]=aux[i];
    }
    *top=i;
    return ranks;
}

/* 1 si el elemento consultado está en el ranking, cero si no 
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int contains(rankingADT ranking, elemType elem){
    elemType * aux=ranking->rank;
    for (int i=0 ; i < ranking->dim ; i++){
        if ( ! ranking->cmp(aux[i],elem)){
            addRanking(ranking,aux[i]);
            return 1;
        }
    }
    return 0;
}

/* Baja una posición en el ranking para el elemento que está en la posición n */
void downByRanking(rankingADT ranking, size_t n){
    if (n > ranking->dim){
        return;
    }

    swap(ranking, n-1, n);
}

void freeRanking(rankingADT r){
    free(r->rank);
    free(r);
}

/* Retorna la posición en el ranking (1 es el tope) o 0 si no está en el ranking */
int position(const rankingADT r, elemType elem){
    for (int i=0 ; i < r->dim ; i++){
        if (! r->cmp(r->rank[i],elem)){
            return i+1;
        }
    }
    return 0;
}