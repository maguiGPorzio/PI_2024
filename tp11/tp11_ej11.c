#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/mgonzalezporzio/PI/tp11/tp11_ej11.h"
#define BLOCK 10

struct vectorCDT {
    elemType ** vec;
    size_t dim; //la cantidad de elemntos totales
    size_t size; //la cantidad de memoria reservada
    size_t elements; //cantidad de elementos que no son nulos
    compares cmp; //la funcion para comparar 
};

/* Crea un nuevo vector dinámico de elementos genéricos
** Inicialmente el vector está vacío
** Cada elemento a insertar será de tipo elemType
** Si no se pudo crear retorna NULL.
** La función compare retorna negativo si source es "menor" que target,
** positivo si source es "mayor""que target o cero si se los considera iguales
** (la misma convención que strcmp)
*/
vectorADT newVector(int (*compare)(elemType source, elemType target)){
    vectorADT aux=calloc(1,sizeof(struct vectorCDT));
    aux->cmp=compare;
    return aux;
}

/* Libera todos los recursos reservados por el TAD */
void freeVector(vectorADT v){
    free(v->vec);
    free(v);
}

/* Almacena los elementos de elems a partir de la posición index, donde elems es
un vector de dim elementos.
** En caso de ser necesario agranda el vector.
** El resto de los elementos del vector no se modifican y permanecen en la misma
posición.
** Si se recibe NULL o no se pudo insertar retorna cero.
** Si alguna posición está ocupada, la deja como estaba.
** Retorna cuántos elementos pudo almacenar.
** Ejemplo:
** si v tiene ocupadas las posiciones 1,3 y 6
** se invoca con index=2, dim=5
** el vector actual quedará con los mismos elementos en las posiciones 1, 3 y 6
** pero además v[2]=elems[0], v[4]=elems[2], v[5]=elems[3]
** y la función retorna 3
*/
size_t 
put(vectorADT v, elemType * elems, size_t dim, size_t index){
    if (elems==NULL){
        return 0;
    }

    if (v->size < index+dim){
        v->size=index+dim;
        v->vec=realloc(v->vec,v->size * sizeof(v->vec[0]));
    }

    size_t j=0;
    size_t elemAgreg=0;
    for (int i=0 ; i<index+dim ; i++){
        if (i>=index){
            if (v->vec[i] == NULL || i >= v->dim){
                v->vec[i]=elems + j;
                elemAgreg++;
            }
            j++;
        }
        else if (i >= v->dim){
            v->vec[i]=NULL;
        }
    }
    v->dim=v->size;
    v->elements+=elemAgreg;

    return elemAgreg;
}

/* Retorna el índice en el cual está insertado el elemento, o -1 si no lo
encuentra */
int getIdx(vectorADT v, elemType elem){
    elemType * aux;
    for (int i=0 ; i<v->dim ; i++){
        aux= v->vec[i];
        if (aux!=NULL && !(v->cmp(*aux,elem))){
            return i;
        }
    }
    return -1;
}

/* Elimina el elemento en la posición index. Si index está fuera del vector no
hace nada */
void deleteElement(vectorADT v, size_t index){
    if (index >= v->dim || v->vec[index] == NULL){
        return;
    }

    v->vec[index]=NULL;
    v->elements--;
}

/* Retorna cuántos elementos hay insertados en el vector */
int elementCount(vectorADT v){
    return v->elements;
}
