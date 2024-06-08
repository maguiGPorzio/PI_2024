/*
Se desea escribir un TAD que de soporte a un juego del ahorcado. Para ello se cuenta con el siguiente contrato, 
que permite almacenar y seleccionar palabras, donde cada palabra tiene asociado un nivel de dificultad, que es un valor entero entre 1 y 
un nivel máximo determinado por el usuario.
ASUMIR QUE TODAS LAS PALABRAS CONTIENEN SOLO LETRAS EN MINUSCULAS.
*/
#include "/home/mgonzalezporzio/PI/parcial2Practica/2016_2c_par2_3.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define IN_RANGE(L,M) (((L)>(M) || (L)<1) ? 0:1)

struct level{
    char ** words;
    int amountWords;
};

struct hangmanCDT{
    struct level * levels;
    int maxLevel;
};

/* Crea la estructura que dará soporte al almacenamiento y selección de palabras
** maxLevel: la cantidad máxima de niveles de dificultad que soportará (como mínimo 1)
** Los niveles válidos serán de 1 a maxLevel inclusive
*/
hangmanADT newHangman(unsigned int maxLevel){
    hangmanADT new=malloc(sizeof(struct hangmanCDT));
    new->levels=calloc(maxLevel , sizeof(new->levels[0]));
    new->maxLevel=maxLevel;
    return new;
}

void
addWordAux(hangmanADT h, char * word, unsigned int level, int * added){
    int i=0;
    for (; i < h->levels[level-1].amountWords ; i++){
        if (!strcmp(h->levels[level-1].words[i],word)){
            return;
        }
    }
    *added+=1;
    h->levels[level-1].amountWords++;
    h->levels[level-1].words=realloc(h->levels[level-1].words, h->levels[level-1].amountWords * sizeof(h->levels[level-1].words[0]));
    h->levels[level-1].words[h->levels[level-1].amountWords - 1]=word;

    
}

/* Agrega un conjunto de palabras asociadas a un nivel de dificultad.
** El arreglo words[] está finalizado en NULL
** Si alguna de las palabras de words[] ya existe en el hangmanADT para ese nivel de dificultad
** se ignora.
** No se realiza una copia local de cada palabra sino únicamente los punteros recibidos
** Si el nivel supera la cantidad máxima definida en newHangman, se ignora y retorna -1
** Retorna cuántas palabras se agregaron al nivel
*/
int addWords(hangmanADT h, char * words[], unsigned int level){
    if (!IN_RANGE(level,h->maxLevel)){
        return -1;
    }
    int added=0;
    for (int i=0 ; words[i] != NULL ; i++){
        addWordAux(h,words[i],level,&added);
    }
    return added;
}


/* Retorna cuántas palabras hay en un nivel, -1 si el nivel es inválido */
int size(const hangmanADT h, unsigned int level){
    if (!IN_RANGE(level,h->maxLevel)){
        return -1;
    }
    return h->levels[level -1].amountWords;
}

// Función para generar un número aleatorio normalizado en [0,1) 
double randNormalize(){
    return rand () / ((double) RAND_MAX+1);
}

// Función para generar un número entero aleatorio en el rango [left, right]
int randInt(int left, int right){
    return ((int)(randNormalize()*(right-left+1)) + left);
}

// Función para inicializar la semilla del generador de números aleatorios
//semilla para que los numeros aleatorios que gneramos sean siempre distintos
//srand funcion de c para inicializar semilla
void 
randomize(){
    srand((int)time(NULL));
}

char *
wordAux(const hangmanADT h, unsigned int level, int pos){
    char * randomWord=h->levels[level-1].words[pos];
    char * word=malloc(strlen(randomWord) + 1);
    strcpy(word,randomWord);
    return word;
}


/* Retorna una palabra al azar de un nivel determinado, NULL si no hay palabras de ese nivel
** o si el nivel es inválido. 
*/
char * word(const hangmanADT h, unsigned int level){
     if (!IN_RANGE(level,h->maxLevel) || h->levels[level -1].amountWords == 0 ){
        return 0;
    }

    int pos=randInt(0,h->levels[level-1].amountWords - 1);
    return wordAux(h,level,pos);
}


/* Retorna todas las palabras de un nivel, o NULL si el nivel es inválido
** El último elemento del vector es el puntero NULL
*/
char ** words(const hangmanADT h, unsigned int level){
    if (!IN_RANGE(level,h->maxLevel)){
        return NULL;
    }

    char ** words=malloc((h->levels[level-1].amountWords + 1) * sizeof(words[0]));
    int i=0;
    for (; i<h->levels[level-1].amountWords ; i++){
        words[i]=wordAux(h,level,i);
    }
    words[i]=NULL;
    return words;
}