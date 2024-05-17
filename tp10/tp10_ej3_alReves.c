#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "/home/mgonzalezporzio/PI/tp10/utillist.h"

// Tambien podria ser de tipo TList
TList order (TList list);


int main(void) {

  int v[] = {4,2,5,3};
  int dimV = sizeof(v)/sizeof(v[0]);
  TList list = fromArray(v, dimV);
  
  list=order(list);

  int o[] = {2,3};
  assert(checkElems(list, o, sizeof(o)/sizeof(o[0]))==1);

  printf ("OK!\n");
  return 0;
}

/*
Escribir una función recursiva order que dada una lista de enteros que debería estar ordenada en forma ascendente, 
elimine de la misma los elementos que no cumplan con ese orden. 
El primer elemento de la lista (si no está vacía) no cambia.

¿Qué tendrías que cambiar si te dijeran que no es el primero sino el último el que está bien?
Si la lista fuera 4 -> 2 -> 5 -> 3
Tendría que quedar 2 -> 3
Marcelo me propuso hacerla de esta manera
*/

TList
order (TList list){
    if (list==NULL || list->tail == NULL){ //si es NULL o tiene un unico elemento que termine
        return list;
    }
    
    list->tail=order(list->tail); 

    TList aux=(list->tail);

    if (list->elem >= aux->elem){
        free(list);
        return aux;
    }

    return list;

}