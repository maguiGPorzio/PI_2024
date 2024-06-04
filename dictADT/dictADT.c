//
// Created on 29/05/2024.
//
#include "dictADT.h"
#include <strings.h>   // para usar strcasecmp
#include <ctype.h>
#include <string.h>

#define LETTERS ('Z'-'A'+1)
#define BLOCK 20

typedef struct node {
    char * word;
    char * def;    // longitud incluyendo el cero
    size_t lenDef; // longitud de def (cantidad de caracteres)
    struct node * tail;
} node;

typedef struct node * List;

struct letter {
    size_t wordsCount;  // Cantidad de palabras que empiezan con esta letra
    List first;   // La vieja y conocida lista
};

struct dictCDT {
    size_t count;  // Cantidad de palabras en el diccionario
    struct letter words[LETTERS];
};

dictADT newDict() {
    return calloc(1, sizeof(struct dictCDT));
}

static void freeRec(List l) {
    if ( l==NULL) {
        return;
    }
    freeRec(l->tail);
    free(l->def);
    free(l->word);
    free(l);
}

static void freeIter(List l) {
    while ( l!= NULL) {
        List aux = l->tail;
        free(l->def);
        free(l->word);
        free(l);
        l = aux;
    }
}

void freeDict(dictADT d) {
    // NO hace falta if ( d==NULL)
    for(int i=0; i<LETTERS; i++) {
        freeRec(d->words[i].first);
    }
    free(d);
}

static char * copyStr(const char * s) {
    return strcpy(malloc(strlen(s)+1), s);
}

static char * copyBlock(const char * s, size_t * len) {
    char * ans = NULL;
    int i;
    for(i = 0; s[i]; i++) {
        if ( i % BLOCK == 0) {
            ans = realloc(ans, (i + BLOCK) * sizeof(ans[0]) );
        }
        ans[i] = s[i];
    }
    ans = realloc(ans, i+1);
    ans[i]=0;
    *len = i+1;
    return ans;
}

static List addRec(List l, char * word, char * def, int *flag) {
    int c;
    if ( l==NULL || (c=strcasecmp(l->word, word)) > 0) {
        List aux = malloc(sizeof(struct node));
        aux->word = copyStr(word);
        aux->def = copyBlock(def, &aux->lenDef);
        aux->tail = l;
        *flag=1;
        return aux;
    }
    if ( c < 0) {
        l->tail = addRec(l->tail, word, def, flag);
    }
    return l;
}

void addWord(dictADT d, const char * word, const char * def) {
    if (!isalpha(word[0])) {
        return;
    }
    int idx = tolower(word[0]) - 'a';
    int flag = 0;
    d->words[idx].first = addRec(d->words[idx].first, word, def, &flag);
    d->words[idx].wordsCount += flag;
    d->count += flag;
}

static List deleteRec(List l, const char * word, int *flag) {
    int c;
    if ( l==NULL || ( c = strcasecmp(l->word, word)) > 0) {
        return l;
    }
    if ( c ==0) {
        List aux = l->tail;
        free(l->word);
        free(l->def);
        free(l);
        *flag = 1;
        return aux;
    }
    l->tail = deleteRec(l->tail, word, flag);
    return l;
}

void deleteWord(dictADT d, const char * word) {
    if (!isalpha(word[0])) {
        return ;
    }
    int idx = tolower(word[0])- 'a';
    int flag=0;
    d->words[idx].first = deleteRec(d->words[idx].first, word, &flag);
    d->words[idx].wordsCount -= flag;
    d->count -= flag;
}

static void copyWords(char ** v, List l) {
    int i=0;
    while ( l != NULL) {
        v[i++] = copyStr(l->word);
        l = l->tail;
    }
}

char ** wordsLetter(dictADT d, char letter) {
    if (!isalpha(letter)) {
        return NULL;
    }
    int idx = tolower(letter)- 'a';
    char ** ans = malloc((d->words[idx].wordsCount + 1) * sizeof(char*));
    copyWords(ans, d->words[idx].first);
    ans[d->words[idx].wordsCount] = NULL;
    return ans;
}

char ** words(dictADT d) {
    char ** ans = malloc(d->count * sizeof(char *));
    int j=0; // Indice de ans
    for(int i=0; i< LETTERS; i++) {
        // Agregamos las que empiezan con la letra i + 'a'
        copyWords(ans + j, d->words[i].first);
        j += d->words[i].wordsCount;
    }
    return ans;
}

char * defAux(List l, const char * word) {
    int c;
    if ( l==NULL || (c=strcasecmp(l->word, word)) > 0) {
        return NULL;
    }
    if ( c == 0) {
        char * s = malloc(l->lenDef);
        strcpy(s, l->def);
        return s;
    }
    return defAux(l->tail, word);
}

char * def(dictADT d, const char * word) {
    if (!isalpha(word[0])) {
        return NULL;
    }
    int idx = tolower(word[0])- 'a';
    return defAux(d->words[idx].first, words);
}

size_t wordsCount(dictADT d) {
    return d->count;
}
