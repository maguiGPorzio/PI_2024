//
// Created on 29/05/2024.
//
#include "/home/mgonzalezporzio/PI/dictADT.h"
#include <string.h>
#include <ctype.h>
#define BLOCK 10

#define LETTERS ('Z'-'A'+1)

typedef struct node {
    char * word;
    char * def;
    size_t lenDef; // longitud de def (cantidad de caracteres)
    struct node * tail;
} node;

typedef struct node * List;

struct letter {
    size_t wordsCount;  // Cantidad de palabras que empiezan con esta letra
    List first;
};

struct dictCDT {
    size_t count;  // Cantidad de palabras en el diccionario
    struct letter words[LETTERS];
};

dictADT newDict(){
    dictADT new=calloc(1,sizeof(struct dictCDT));
    return new;
}

void freeDict(dictADT d);

static void
copyDef (List node , const char * def){
    node->def=NULL;
    int i=0;
    for (; def[i] ; i++){
        if (i % BLOCK == 0){
            node->def=realloc(node->def, i+BLOCK);
        }
        node->def[i]=def[i];

    }
    node->def=realloc(node->def, i+1);
    node->def[i]=0;

    node->lenDef=i;
}

List
addWordRec(List allWords, const char * word, const char * def, int * fueAgregada){
    int comp=strcmp(allWords->word,word);
    if (allWords == NULL || comp > 0){
        *fueAgregada=1;

        List aux=malloc(sizeof(node));
        aux->tail=allWords;

        size_t dimPal=strlen(word);

        aux->word=malloc(dimPal+1);
        strcpy(aux->word,word);

        copyDef(aux,def);

        return aux;
    }

    if (!comp){
        return allWords;
    }

    allWords->tail=addWordRec(allWords->tail,word,def,fueAgregada);
    return allWords;
}

void 
addWord(dictADT d, const char * word, const char * def){
    if (!isalpha(word[0])){
        return;
    }
    int posicion=tolower(word[0])-'a';
    int fueAgregada=0;

    d->words[posicion].first=addWordRec(d->words[posicion].first, word, def, &fueAgregada);
    d->words[posicion].wordsCount+=fueAgregada;
    d->count+=fueAgregada;
}

void deleteWord(dictADT d, const char * word);

char ** wordsLetter(dictADT d, char letter);

char ** words(dictADT d);

char * def(dictADT d, const char * word);

size_t wordsCount(dictADT d);
