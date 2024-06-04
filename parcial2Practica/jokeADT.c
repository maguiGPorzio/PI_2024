#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "/home/mgonzalezporzio/PI/parcial2Practica/jokeADT.h"
#define BLOCK 10

/*
Se desea crear un TAD para almacenar y consultar chistes. Cada chiste puede tener miles de caracteres. 
Además cada chiste debe pertenecer a una categoría. La categoría estará dada por un nombre corto y que contendrá 
únicamente letras minúsculas del alfabeto inglés ( "tonto", "racista", "suegra", "rubias", "humornegro", "verde", etc.).

Implementar el TAD completo, excepto las funciones freeJokes y deleteCategory.
*/

struct joke{
    size_t longJoke; //cantidad de caracteres del chiste
    char * joke; //chiste 
};

typedef struct joke * Tjoke;

typedef struct category{
    char * categor; //nombre categoria
    size_t longCateg; //cantidad de caracteres categoria 

    struct joke * jokes; //lista de los chistes y la longitud de los chistes
    size_t amountJokes; //cantidad de chistes totales
    size_t amountJokesReserved; //cantidad de espacio reservado para chistes

    struct category * nextCateg; //proxima categoria
} category;

typedef category * TCategory;

struct jokesCDT{
    struct category * categ; //puntero a la primer categoria
    size_t amountCategories; //cantidad de categorias
};

// Devuelve un nuevo TAD para almacenar y recuperar chistes
jokesADT
newJokes(){
    jokesADT new=calloc(1,sizeof(struct jokesCDT));
    return new;
}

void 
freeJokesRec(TCategory categories){
    if (categories == NULL){
        return; 
    }

    for (int i=0 ; i<categories->amountJokes ; i++){
        free(categories->jokes[i].joke);
    }

    TCategory aux=categories->nextCateg;
    free(categories->categor);
    free(categories->jokes);
    free(categories);
    freeJokesRec(aux);
}

/* Libera toda la memoria reservada por el ADT */
void freeJokes(jokesADT jokes){
    freeJokesRec(jokes->categ);
    free(jokes);
}

static TCategory
addcategoryRec(TCategory categories, const char * category, int * added){
    if (categories == NULL || strcmp(categories->categor, category) > 0){
        TCategory newCat=calloc(1,sizeof(struct category));

        newCat->longCateg=strlen(category);

        newCat->categor=realloc(newCat->categor, newCat->longCateg + 1);//no pongo el sizeof porq estoy pidiendo lugar para chars
        strcpy(newCat->categor,category);

        newCat->nextCateg=categories;

        *added=1;

        return newCat;
    }

    if (!strcmp(categories->categor, category)){
        return categories;
    }

    categories->nextCateg=addcategoryRec(categories->nextCateg, category, added);
    return categories;
}


/* Agrega una categoría si es que no estaba 
* Se asume que la categoría sólo contiene minúsculas, no
* es necesario validarlo
*/
void addCategory(jokesADT jokes, const char * category){
    int added=0;
    jokes->categ=addcategoryRec(jokes->categ,category,&added);
    jokes->amountCategories+=added;
}

static void 
addJokeAux(TCategory category, const char * joke){
    if (category->amountJokesReserved == category->amountJokes){
        category->amountJokesReserved+=BLOCK;
        category->jokes=realloc(category->jokes, (category->amountJokesReserved) * sizeof(category->jokes[0]));
    }
    category->amountJokes++;

    category->jokes[category->amountJokes-1].joke=NULL;
    int i=0;
    for (; joke[i] ; i++){
        if (i % BLOCK == 0){
            category->jokes[category->amountJokes-1].joke=realloc(category->jokes[category->amountJokes-1].joke,i + BLOCK);
        }
        category->jokes[category->amountJokes-1].joke[i]=joke[i];
    }
    category->jokes[category->amountJokes-1].joke=realloc(category->jokes[category->amountJokes-1].joke,i+1);
    category->jokes[category->amountJokes-1].joke[i]=0;
    category->jokes[category->amountJokes-1].longJoke=i;
}

/**
* Agrega un nuevo chiste a una categoría. Si la categoría no existe
* entonces no agrega el chiste. No verifica si el chiste está repetido, 
* ya sea en la categoría dada o en otra
*/
void addJoke(jokesADT jokes, const char * category, const char * joke){
    TCategory aux=jokes->categ;
    while (aux != NULL){
        if (!strcmp(aux->categor,category)){
            addJokeAux(aux,joke);
            return;
        }
        aux=aux->nextCateg;
    }
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

/*
* Retorna la copia de un chiste para una categoría. Debe elegir al azar
* entre los chistes de la categoría. Si la categoría no existe
* o no tiene chistes retorna NULL
*/
char * joke(jokesADT jokes, const char * category){ 
    TCategory aux=jokes->categ;
    char * joke=NULL;
    int pos;
    while (aux != NULL){
        if (!strcmp(aux->categor,category)){
            pos=randInt(0,aux->amountJokes - 1);
            joke=realloc(joke, aux->jokes[pos].longJoke + 1);
            strcpy(joke,aux->jokes[pos].joke);
            return joke;
        }
        aux=aux->nextCateg;
    }
    return joke;
}

/*
* Elimina una categoría y todos los chistes de esa categoría
*/
//void deleteCategory(jokesADT jokes, const char * category);

/* Retorna la cantidad de categorías */
size_t categoriesCount(const jokesADT jokes){
    return jokes->amountCategories;
}

/*
* Retorna un vector con una copia de todas las categorías, ordenado
* alfabéticamente. La cantidad de elementos estará dada por la función
* categoriesCount. Si no hay categorías retorna NULL
*/
char ** categories(const jokesADT jokes){
    char ** categor=NULL;

    if (jokes->amountCategories == 0){
        return categor;
    }

    categor=realloc(categor, jokes->amountCategories * sizeof(categor[0]));
    TCategory aux=jokes->categ;
    for (int i=0 ; i < jokes->amountCategories ; i++){
        categor[i]=malloc(aux->longCateg + 1);
        strcpy(categor[i],aux->categor);
        aux=aux->nextCateg;
    }
    return categor;
}