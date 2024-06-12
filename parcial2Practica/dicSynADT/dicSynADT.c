#include "/home/mgonzalezporzio/PI/dicSynADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#define BLOCK 10

/*
 Se desea implementar un TAD que permita mantener y consultar un diccionario de sinónimos.
 El TAD permitirá indicar para una palabra uno o más sinónimos.
 La relación entre una palabra y sus sinónimos no es simétrica.
 No se eliminarán palabras ni sinónimos del TAD.
 Se asume que todas las palabras a insertar no serán extensas..
 Completar en el archivo dicSynADT.c que aparece debajo las funciones pedidas. En caso de ser
 necesario se pueden definir funciones auxiliares.
 No se pueden modificar ni el .h ni los structs definidos.
*/

typedef struct node {
    char * synonym;
    struct node * tail;
} node;

typedef struct wordWithSyns{
    char * word;
    node * syns;
    struct wordWithSyns * tail;
} wordWithSyns;


struct dicSynCDT {
    size_t size;
    // cantidad de palabras
    wordWithSyns * first;
};


dicSynADT newDicSyn() {
    dicSynADT new=calloc(1,sizeof(struct dicSynCDT));
    return new;
}

size_t size(const dicSynADT dict) {
    return dict->size;
}

 /*
 ** Busca el nodo con la palabra word. Si no estaba lo agrega en forma ascendente
 ** y hace que node apunte al nuevo nodo.
 ** Si ya estaba entonces node apunta al nodo que contiene word
 */
static wordWithSyns * 
addWord(wordWithSyns * first, const char * word, wordWithSyns ** node, int * flag) {
    int c;
    if (first == NULL || (c=strcasecmp(first->word, word)) > 0){
        wordWithSyns * new=calloc(1,sizeof(wordWithSyns));
        new->tail=first;
        new->word=realloc(new->word, strlen(word) + 1);
        strcpy(new->word, word);
        *flag=1;
        *node=new;
        return new;
    }

    if (!c){
        *node=first;
        *flag=0;
        return first;
    }

    first->tail=addWord(first->tail, word, node, flag);
    return first;
}


static node *
addSyn(node * s, const char * synonymous){
    int c;
    if (s==NULL || (c=strcasecmp(s->synonym, synonymous))>0){
        node * new=malloc(sizeof(node));
        new->tail=s;
        new->synonym=malloc(strlen(synonymous)+1);
        strcpy(new->synonym, synonymous);
        return new;
    }

    if (!c){
        return s;
    }

    s->tail=addSyn(s->tail,synonymous);
    return s;
}

void add(dicSynADT dict, const char * word, const char * synonymous) {
    // Primero veo si hay que agregar word. Me retorna en un parámetro
    // de salida una referencia al nodo, y en un flag retorna 0 si estaba o 1
    // si lo agregó
    wordWithSyns * theWord;
    int flag = 0;
    dict->first = addWord(dict->first, word, &theWord, &flag);
    dict->size += flag;

    // En theWord tenemos el puntero al nodo con la palabra word

    theWord->syns=addSyn(theWord->syns, synonymous);

    dict->first = addWord(dict->first, synonymous, &theWord, &flag);
    dict->size += flag;
}

static wordWithSyns *
searchWord(wordWithSyns * words, const char * word){
    int c;
    if (words==NULL || (c=strcasecmp(words->word, word)) > 0){
        return NULL;
    }

    if (!c){
        return words;
    }

    return searchWord (words->tail, word);
}

char *
copyWord(const char * word){
    char * new=malloc(strlen(word) + 1);
    strcpy(new, word);
    return new;
}

char ** 
synonyms(dicSynADT dict, const char * word) {
    wordWithSyns * w=searchWord(dict->first, word);
    char ** v=NULL;

    if (w == NULL){
        v=realloc(v,sizeof(v[0]));
        v[0]=NULL;
        return v;
    }

    node * s=w->syns;
    int i=0;
    for (; s!=NULL ; i++){
        if (i%BLOCK == 0){
            v=realloc(v,(i+BLOCK)*sizeof(v[0]));
        }
        v[i]=copyWord(s->synonym);
        s=s->tail;
    }
    v=realloc(v,(i+1)*sizeof(v[0]));
    v[i]=NULL;
    return v;
}


char ** 
words(const dicSynADT dict) {
    char ** v=NULL;
    wordWithSyns * w=dict->first;
    int i=0; 
    for (; w!=NULL ; i++){
        if (i%BLOCK == 0){
            v=realloc(v,(i+BLOCK)*sizeof(v[0]));
        }
        v[i]=copyWord(w->word);
        w=w->tail;
    }
    v=realloc(v,(i+1)*sizeof(v[0]));
    v[i]=NULL;
    return v;
}

void
freeSynRec(node * syn){
    if (syn == NULL){
        return;
    }

    node * n=syn->tail;
    free(syn->synonym);
    free(syn);
    freeSynRec(n);
}

void 
freeDict(dicSynADT dict) {
    wordWithSyns * w=dict->first;
    wordWithSyns * aux;

    while (w!=NULL){
        aux=w->tail;
        freeSynRec(w->syns);
        free(w->word);
        free(w);
        w=aux;
    }

    free(dict);
}