#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/taller11_01.h"

typedef struct node {
    unsigned char letra;
    struct node * tail;
} node;

typedef node * TList;

struct palabraCDT {
    TList first;// puntero al primer nodo
    size_t len;// cantidad de letras de la palabra
    TList last;
};

/**
* crearVacia: Retorna una palabra nueva, vacía (longitud 0)
*/
palabraADT crearVacia(){
    palabraADT aux=calloc(sizeof(struct palabraCDT));
    return aux;
}
/**
* crearDesde: Retorna una palabra nueva, a partir de un string.
*/
palabraADT crearDesde(char *s);
/**
* agregaLetra: Agrega una letra al final de una palabra existente.
*/
palabraADT agregarLetra(palabraADT pal, char letra);
/**
* mostrarPalabra: Muestra la palabra en salida estándar (sólo para test)
*/
void mostrarPalabra(palabraADT pal);
/**
* destruirPalabra: Libera recursos.
*/
void destruirPalabra(palabraADT pal);