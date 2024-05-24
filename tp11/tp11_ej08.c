#include "/home/mgonzalezporzio/PI/tp11/tp11_ej08.h"
#include <stdlib.h>
#define BLOCK 10

struct setCDT {
    elemType * vec;
    size_t dim;   // elementos en el conjunto
    size_t size;  // elementos reservados
    compare cmp;
};

/* Retorna un nuevo conjunto vacío */
//porque aca aretorn aun puntero, no podria retornar la estructura?
setADT 
newSet(int (*compare)(elemType, elemType)){
    setADT aux=calloc(1,sizeof(struct setCDT));
    aux->cmp=compare;
    return aux;
}

void freeSet(setADT set){
    free(set->vec);
    free(set);
}

int isEmptySet(setADT set){
    return (set->dim==0);
}

int setContains(const setADT set, elemType element){
    for (int i=0 ; i<set->dim ; i++){
        if (!set->cmp(element,set->vec[i])){
            return 1;
        }
    }
    return 0;
}

int addElement(setADT set, elemType element){
    if (setContains(set,element)){
        return 0;
    }

    if (set->dim == set->size){
        set->size+=BLOCK;
        set->vec=realloc(set->vec,set->size * sizeof(set->vec[0]));
    }
    set->vec[set->dim++]=element;
    return 1;
}
 //esta funcion esta mla, como no tienen orden deberia hacer un cambio y poner el ultimo elemento en la posicion del elemento que elimine (en el ej 10 lo hago)
int deleteElement(setADT set, elemType element){
    int esta=0, j=0;
    
    for (int i=0; i<set->dim && !esta; i++){
        if (!esta && !set->cmp(element,set->vec[i])){
            esta=1;
            j=i;
            set->dim-=esta;
        }
        else if (esta){
            set->vec[j++]=set->vec[i];
        }
    }

    return esta;
}

int sizeSet(const setADT set){
    return set->dim;
}

setADT 
unionSet(setADT set1, setADT set2){
    setADT new=newSet(set1->cmp);

    int j=0, i=0;
    while (i<set1->dim || j<set2->dim){
        if (new->dim == new->size){
            new->size+=BLOCK;
            new->vec=realloc(new->vec, (new->size) * sizeof(new->vec[0]));
        }

        if (i<set1->dim){
            new->vec[new->dim++]=set1->vec[i++];
        }
        else if (!setContains(set1,set2->vec[j])){
            new->vec[new->dim++]=set2->vec[j++];
        }
        else{
            j++;
        }
    }
    return new;
}

setADT 
intersectionSet(setADT set1, setADT set2){
    setADT new=newSet(set1->cmp);
    int i=0;
    for (; i<set1->dim ; i++){
        if (setContains(set2,set1->vec[i])){
            if (new->dim == new->size){
                new->size+=BLOCK;
                new->vec=realloc(new->vec, new->size * sizeof(new->vec[0]));
            }
            new->vec[new->dim++]=set1->vec[i];
        }
    }
    return new;
}

setADT 
diffSet(setADT set1, setADT set2){
    setADT new=newSet(set1->cmp);
    int i=0;
    for (; i<set1->dim ; i++){
        if (!setContains(set2,set1->vec[i])){
            addElement(new,set1->vec[i]);
        }
    }
    return new;
}