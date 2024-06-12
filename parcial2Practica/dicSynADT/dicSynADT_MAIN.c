#include "/home/mgonzalezporzio/PI/dicSynADT.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void freeAll(char ** v) {
    for(size_t i=0; v[i] != NULL; i++) {
        free(v[i]);
    }
    free(v);
}

int
main(void) {
    dicSynADT dic = newDicSyn();
    char ** aux;
    aux = words(dic);
    assert(aux[0] == NULL);
    free(aux);
    aux = synonyms(dic, "casa");
    assert(aux[0] == NULL);
    free(aux);
    char word[50];
    strcpy(word, "vivienda");
    add(dic, "casa", word);
    assert(size(dic)==2);
    strcpy(word, "Hogar");
    add(dic, "casa", word);
    assert(size(dic)==3);
    strcpy(word, "almondiga");
    add(dic, "albondiga", word);
    add(dic, "casa", "hogar");
    aux = synonyms(dic, "Hogar");
    assert(aux[0] == NULL);
    free(aux);
    assert(size(dic)==5);
    // "casa" y "vivienda"
    // Puede venir en minúscula o mayúscula
    // "casa", "Hogar" y "vivienda"
    // No realiza ningún cambio
    aux = synonyms(dic, "CASA");
    assert(strcmp(aux[0], "Hogar")==0);
    assert(strcmp(aux[1], "vivienda")==0);
    assert(aux[2] == NULL);
    freeAll(aux);
    // "CASA" es lo mismo que "casa"
    aux = words(dic);
    assert(strcmp(aux[0], "albondiga")==0);
    assert(strcmp(aux[1], "almondiga")==0);
    assert(strcmp(aux[2], "casa")==0);
    assert(strcmp(aux[3], "Hogar")==0);
    assert(strcmp(aux[4], "vivienda")==0);
    assert(aux[5] == NULL);
    freeAll(aux);
    add(dic, "hogar", "casa");
    // Ahora "casa" es sinónimo de "Hogar",
    // pero el size no cambia, ya estaba "Hogar"
    assert(size(dic)==5);
    aux = synonyms(dic, "hogar");
    assert(strcmp(aux[0], "casa")==0);
    assert(aux[1] == NULL);
    freeAll(aux);
    freeDict(dic);
    puts("OK, Correcto, Bien");
    return 0;
}