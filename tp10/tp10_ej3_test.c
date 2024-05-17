#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "/home/mgonzalezporzio/PI/tp10/utillist.h"

// Tambien podria ser de tipo TList
void order (TList list);


int main(void) {

  int v[] = {1,1,2,1,0,-1,3,3,3,3,3,10,9,100,100,998};
  int dimV = sizeof(v)/sizeof(v[0]);
  TList list = fromArray(v, dimV);
  
  order(list);
  int o[] = {1,2,3,10,100,998};
  assert(checkElems(list, o, sizeof(o)/sizeof(o[0]))==1);

  order(list);
  assert(checkElems(list, o, sizeof(o)/sizeof(o[0]))==1);
  freeList(list);
 
  TList empty = NULL;
  order(empty);
  assert(empty ==NULL);

  list = fromArray(v,1);
  order(list);
  assert(list->elem ==1 && list->tail == NULL);
  freeList(list);

  int w[] = {1,1,1,1,1,1,1,1,1,1};
  list = fromArray(w, sizeof(w)/sizeof(w[0]));
  order(list);
  assert(list->elem ==1 && list->tail == NULL);
  freeList(list);

  printf ("OK!\n");
  return 0;
}

/*
Escribir una función recursiva order que dada una lista de enteros que debería estar ordenada en forma ascendente, 
elimine de la misma los elementos que no cumplan con ese orden. 
El primer elemento de la lista (si no está vacía) no cambia.
*/

void
order (TList list){
  if (list==NULL || list->tail == NULL){ //si es NULL o tiene un unico elemento que termine
    return;
  }

  order(list->tail); 

  TList aux=list->tail; 

  if (aux->elem <= list->elem){ 
    list->tail=aux->tail; 
    free(aux); 
  }
}

/*

RESOLUCION CATEDRA

// Como el primero no se elimina, puede ser void
void order (TList list) {
  if (list == NULL || list->tail == NULL)
      return;

  if (list->elem >= list->tail->elem) {
    TList auxToFree = list->tail;
    list->tail = auxToFree->tail;
    free(auxToFree);
    // Seguimos procesando list, puede que siga desordenada
    order(list);
  } else {
    order(list->tail);
  }

}
*/