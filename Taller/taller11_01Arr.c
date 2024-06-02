/*
Crear un T.A.D. que maneje palabras. (palabraADT)
Funcionalidades:
- Crear instancia: crear
- Liberar recursos: destruir
- Mostrar: mostrar
- Agregar letras: agregarLetra al final
- Concatenar
- Pasar a mayúsculas
- Pasar a minúsculas
- …
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/taller11_01.h"

typedef struct palabraCDT{
    char * letras;
    int len;
}palabraCDT;


/**
* crearVacia: Retorna una palabra nueva, vacía (longitud 0)
*/
palabraADT crearVacia(){
    palabraADT new=calloc(1,sizeof(struct palabraCDT));
    return new;
}
/**
* crearDesde: Retorna una palabra nueva, a partir de un string.
*/
palabraADT 
crearDesde(char *s){
    palabraADT new=crearVacia();
    new->len=strlen(s);
    new->letras=realloc( new->letras , (new->len + 1) * sizeof(new->letras[0]));
    strcpy(new->letras[0],s);
    return new;
}
/**
* agregaLetra: Agrega una letra al final de una palabra existente.
*/
palabraADT
agregarLetra(palabraADT pal, char letra){
    pal->len+=1;
    pal->letras=realloc(pal->letras , (pal->len + 1) * sizeof(pal->letras[0]));
    pal->letras[pal->len - 1]=letra;
    pal->letras[pal->len]=0;
    return pal;
}
/**
* mostrarPalabra: Muestra la palabra en salida estándar (sólo para test)
*/
void mostrarPalabra(palabraADT pal){
    printf("%s \n",pal->letras);
}
/**
* destruirPalabra: Libera recursos.
*/
void destruirPalabra(palabraADT pal){
    free(pal->letras);
    free(pal);
}