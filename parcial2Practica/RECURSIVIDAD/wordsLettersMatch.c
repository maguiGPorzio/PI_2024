/*
funcion recursiva wordsLetterMatch que reciba unicamente una lista de letras y una palabra, y retorne cuantas coincidencias hay
entre los primeros nodos de la lista y la palabra 

ejemplo:
si la lista tiene los nodos 'H','O','L','A', y el string comienza con "HOLA" ("HOLA", "HOLA QUE TAL"), retorna 4
si la lista tiene los nodos 'H','O','L','A', y el string comienza con "OLA", retorna 0
si la lista tiene los nodos 'H','O','L','A', y el string comienza con "hola"
si la lista tiene los nodos 'H','O','L','A', y el string comienza con "HLA", retorna 1
si la lista tiene los nodos 'H','O','L','A', y el string comienza con "", retorna 0
si la lista tiene los nodos 'H','H','H','H', y el string comienza con "HH", retorna 2
*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
		char elem;
		struct node * tail;
} TNode;

typedef TNode * TList; 

TList 
LfromArray(const char v[], unsigned int dim ) {
    TList ans = NULL;
    while (dim) {
        TList aux = malloc(sizeof(TNode));
        aux->elem = v[--dim];
        aux->tail = ans;
        ans = aux;
    }
    return ans;
}

int
wordsLetterMatch(TList lista, char * s){
    if (s[0] == 0 || lista == NULL){
        return 0;
    }

    if (lista->elem == s[0]){
        return 1 + wordsLetterMatch(lista->tail,s+1);
    }

    return 0;
}

int 
main (){
    char * v="HOLA";
    TList l=LfromArray(v,5);
    assert(wordsLetterMatch(l,"HOLA")==4);
    assert(wordsLetterMatch(l,"OLA")==0);
    assert(wordsLetterMatch(l,"hola")==0);
    assert(wordsLetterMatch(l,"HLA")==1);
    assert(wordsLetterMatch(l,"")==0);
    v="HHHH";
    l=LfromArray(v,5);
    assert(wordsLetterMatch(l,"HH")==2);
    puts("OK");
    return 0;
}