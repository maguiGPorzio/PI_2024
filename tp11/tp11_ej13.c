/*Se desea implementar una colección que permita guardar elementos genéricos sin repeticiones. La colección se llamará rankingADT, 
ya que tiene la particularidad que tiene que servir para acceder fácilmente a los elementos que están al tope del ranking. Los elementos 
van "escalando posiciones" en el ranking a medida que son consultados.
Si la colección tiene N elementos, se dice que el que está en el tope del ranking está en el puesto 1. El que está último en el ranking 
está en el puesto N del ranking.
*/

//aca lo estoy haciendo guardandome una copia de los elementos, el 11 lo hice haciendolo apuntar directamente

#include <stdio.h>
#include <stdlib.h>
#include "/home/mgonzalezporzio/PI/tp11/rankingADT.h"
#define BLOCK 10

struct rankingCDT {
    elemType ** rank;
    size_t dim;
    size_t size;
    compare cmp;
};

/* Crea un nuevo ranking. Recibe un vector con elementos, donde el primer
** elemento (elems[0]) está al tope del ranking (puesto 1), elems[1] en el 
** puesto 2, etc. Si dim es cero significa que no hay elementos iniciales
*/
rankingADT
newRanking(elemType elems[], size_t dim, compare cmp){
    rankingADT aux=malloc(sizeof(struct rankingCDT));
    aux->dim=dim;
    aux->size=dim;
    aux->cmp=cmp;
    aux->rank=NULL;
    if (aux->dim == 0){
        return aux;
    }
    
    aux->rank=realloc(aux->rank, dim*sizeof(aux->rank[0]));
    for (int i=0 ; i<dim ; i++){
        aux->rank[i]=malloc(sizeof(elemType));
        *(aux->rank[i])=elems[i];
    }
    return aux;
}

/* Agrega un elemento en la posición más baja del ranking, si no estaba.
** Si el elemento estaba, es equivalente a accederlo, por lo que sube un 
** puesto en el ranking
*/
void addRanking(rankingADT ranking, elemType elem){
    elemType ** aux=ranking->rank;
    for (int i=0 ; i<ranking->dim ; i++){
        int comp=ranking->cmp(*aux[i],elem);
        if (!comp && i>0){
            elemType aux2=*aux[i-1];
            *aux[i-1]=*aux[i];
            *aux[i]=aux2;
            return;
        }
        else if (!comp){
            return;
        }
    }
    if (ranking->size == ranking->dim){
        ranking->size+=BLOCK;
        ranking->rank=realloc(ranking->rank,ranking->size * sizeof(ranking->rank[0]));
    }
    ranking->rank[ranking->dim]=malloc(sizeof(elemType));
    *(ranking->rank[ranking->dim++])=elem;
}

/* La cantidad de elementos en el ranking */
size_t size(const rankingADT ranking){
    return ranking->dim;
}

/* Si n es una posición válida del ranking, guarda en elem el elemento que está 
** en el puesto n y retorna 1.
** Si no hay elemento en la posición n, retorna cero y no modifica *elem
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int getByRanking(rankingADT ranking, size_t n, elemType * elem){
    if (n >= ranking->dim){
        return 0;
    }

    *elem=*(ranking->rank[n]);
    addRanking(ranking,*elem);
    return 1;
}

/* top: entrada/salida
** Recibe cuántos elementos al tope del ranking se desean 
** Almacena cuántos pudo guardar (ver ejemplos)
** Si el ranking está vacío *top queda en cero y retorna NULL
*/
elemType * 
getTopRanking(const rankingADT ranking, size_t * top){
    elemType * ranks=NULL;
    size_t i=0;
    elemType ** aux=ranking->rank;
    for (; i < ranking->dim && i < *top; i++){
        if (i % BLOCK == 0){
            ranks=realloc(ranks,(i+BLOCK)*sizeof(ranks[0]));
        }
        ranks[i]=*(aux[i]);
    }
    *top=i;
    return ranks;
}

/* 1 si el elemento consultado está en el ranking, cero si no 
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int contains(rankingADT ranking, elemType elem){
    elemType ** aux=ranking->rank;
    for (int i=0 ; i < ranking->dim ; i++){
        if (!ranking->cmp(*aux[i],elem)){
            addRanking(ranking,*aux[i]);
            return 1;
        }
    }
    return 0;
}

/* Baja una posición en el ranking para el elemento que está en la posición n */
void downByRanking(rankingADT ranking, size_t n){
    if (n+1 >= ranking->dim){
        return;
    }

    elemType ** aux=ranking->rank;
    elemType aux2=*aux[n+1];
    *aux[n+1]=*aux[n];
    *aux[n]=aux2;
}

void freeRanking(rankingADT r){
    for (int i=0 ; i < r->size ; i++){
        free(r->rank[i]);
    }
    free(r->rank);
    free(r);
}

/* Retorna la posición en el ranking (1 es el tope) o 0 si no está en el ranking */
int position(const rankingADT r, elemType elem){
    for (int i=0 ; i < r->dim ; i++){
        if (!r->cmp(*r->rank[i],elem)){
            return i+1;
        }
    }
    return 0;
}