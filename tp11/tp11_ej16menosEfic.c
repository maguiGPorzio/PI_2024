/*
Se desea crear un TAD que dé soporte para almacenar y recuperar frases, donde cada frase tiene asociada una clave numérica 
(un valor entero positivo). Las claves son únicas (no puede haber dos frases con la misma clave, aunque sí podría pasar que dos 
claves tengan la misma frase).
Para ello se crea el siguiente contrato, y se cuenta además con un programa de prueba (leer completamente ambos antes de implementar el TAD).
No hay un límite previsto para la longitud de cada frase, pueden ser unos pocos o miles de caracteres.

ESTA BIEN ME DIJO MARCELO, PERO SI ME GUARDO LA LONGITUD DEL STRING PODRIA SER MAS EFICIENTE
LO HAGO DE NUEVO EN OTRO
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/tp11/phrasesADT.h"
#define BLOCK 20
#define LARGE_BLOCK 100
#define RANGE(keyFrom,keyTo)  (keyTo)-(keyFrom)+1

struct phrasesCDT{
    char ** passwords;
    size_t keyFrom;
    size_t keyTo;
    size_t size;
};

static int 
validateKey(size_t key, size_t keyFrom, size_t keyTo){
    return !(key > keyTo || key < keyFrom);
}
/*
* Recibe cuál será el rango de claves válidas a utilizar, por ejemplo si
* keyFrom=1001, keyTo=1500 habrá un máximo de 500 frases a almacenar
* keyFrom=1001, keyTo=3500 habrá un máximo de 2500 frases a almacenar
* Si los parámetros son inválidos retorna NULL
*/
phrasesADT 
newPhrasesADT(size_t keyFrom, size_t keyTo){
    if (keyFrom > keyTo){
        return NULL;
    }

    phrasesADT new=malloc(sizeof(struct phrasesCDT));
    new->size=0;
    new->keyFrom=keyFrom;
    new->keyTo=keyTo;
    new->passwords=calloc((RANGE(keyFrom,keyTo)),sizeof(new->passwords[0]));
    return new;
}

/* Libera toda la memoria reservada por el TAD */
void freePhrases(phrasesADT ph){
    char * * aux=ph->passwords;
    for (int i=0 ; i < RANGE(ph->keyFrom,ph->keyTo) ; i++){
        if (aux[i] != NULL){
            free(aux[i]);
        }
    }
    free(ph->passwords);
    free(ph);
}

static char *
putAux(const char * phrase){
    char * newPhrase=NULL;
    size_t i;

    for (i=0 ; phrase[i] ; i++){
        if (i % BLOCK == 0){
            newPhrase=realloc(newPhrase,(i+BLOCK)); //como es sizeof(char)==1 no lo pongo
        }
        newPhrase[i]=phrase[i];
    }
    
    newPhrase=realloc(newPhrase,(i+1));
    newPhrase[i]=0;

    return newPhrase;
}

/*
* Agrega una frase. Si la clave key es inválida retorna 0, sinó retorna 1 (uno)
* Si ya hay una frase asociada a la clave, actualiza la frase almacenada,
* reemplazándola por el parámetro phrase.
* Se almacena una copia de la frase.
*/
int put(phrasesADT ph, size_t key, const char * phrase){
    if (!validateKey(key,ph->keyFrom,ph->keyTo)){
        return 0;
    }

    size_t posicion= key - ph->keyFrom;

    if (ph->passwords[posicion] == NULL){
        ph->size++;
    }
    else{
        free(ph->passwords[posicion]);
    }

    ph->passwords[posicion] = putAux(phrase);
    return 1;
}

/*
* Retorna una copia de la frase asociada a la clave key. Si no hay frase asociada
* a la clave key retorna NULL, lo mismo si la clave es inválida.
*/
char * get(const phrasesADT ph, size_t key){
    if (!validateKey(key,ph->keyFrom,ph->keyTo)){
        return NULL;
    }

    int posicion= key - ph->keyFrom;

    if (ph->passwords[posicion] == NULL){
        return NULL;
    }

    char * phrase=putAux(ph->passwords[posicion]);
    return phrase;
}

/*
* Cantidad de frases almacenadas
*/
size_t size(const phrasesADT ph){
    return ph->size;
}

static void
copyString(char ** to, char * from, size_t * letters){
    for (int i=0 ; from[i] ; i++){
        if (*letters % LARGE_BLOCK == 0){
            to[0]=realloc(to[0],*letters + LARGE_BLOCK);
        }
        to[0][(*letters)++]=from[i];
    }
}

/*
* Retorna un string con todas las frases concatenadas
* Si no hay frases retorna un string vacío
*/
char * 
concatAll(const phrasesADT ph){
    // char * phrase=NULL;
    // size_t letters=0;
    // for (int i=0 ; i < RANGE(ph->keyFrom,ph->keyTo) ; i++){
    //     if (ph->passwords[i] != NULL){
    //         copyString(&phrase , ph->passwords[i] , &letters);
    //     }
    // }
    // phrase=realloc(phrase, letters + 1);
    // phrase[letters]=0;
    // return phrase;

    return concat(ph,ph->keyFrom,ph->keyTo);
}

/*
* Retorna un string con todas las frases concatenadas cuyas claves estén entre
* from y to inclusive. Si from o to son inválidas (están fuera del rango)
* retorna NULL
* Si no hay frases en ese rango, retorna un string vacío
*/
char * concat(const phrasesADT ph, size_t from, size_t to){
    if (from > to || from < ph->keyFrom || to > ph->keyTo){
        return NULL;
    }

    char * phrase=NULL;
    size_t letters=0;
    size_t pos;
    for (int i=from ; i < to ; i++){
        pos= i - ph->keyFrom;
        if (ph->passwords[pos] != NULL){
            copyString(&phrase , ph->passwords[pos] , &letters);
        }
    }
    phrase=realloc(phrase, letters + 1);
    phrase[letters]=0;
    return phrase;
}