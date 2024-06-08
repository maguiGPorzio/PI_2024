/*
Se desea implementar un TAD para administrar sitios de interés sobre un camino o ruta. 
En este TAD sólo se puede registrar un sitio de interés cada 100 metros (uno entre los 0 y 99 metros, otro entre los 100 y 199, etc.). 
Pero como un sitio de interés se designa con un tipo genérico, si el usuario desea registrar varios podría usar el siguiente tipo:

No hay límite para la distancia máxima a la cual se encuentre un sitio de interés, ni tampoco para la cantidad de sitios a registrar.
Donde ¿? indica que para resolver este problema se debe indicar el o los parámetros resultantes

Se pide:
Implementar todas las estructuras necesarias, de forma tal que las funciones addLandmark, hasLandmark, landmarkCount y freeLandmark 
puedan ser implementadas de la forma más eficiente posible.
Implementar las siguientes funciones:
newLandmark
addLandmark
landmarks

Ejemplo de programa de prueba. En este caso usamos char * para landmarkType

*/
#include "/home/mgonzalezporzio/PI/landmarkADT.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define BLOCK 10
#define POS(M) (M)/100

struct landmarkCDT{
    landmarkType * landmarks;
    size_t * ocup; 
    size_t amountSites;
    size_t amountSitesReserved;
    compare cmp;
};

/**
 * Crea una nueva colección de sitios de interés. Sólo se registrará un sitio cada
 * 100 metros (uno entre los 0 y 99 metros, posiblemente otro entre los 100 y 199, etc.)
 */
landmarkADT newLandmark(compare cmp){
    landmarkADT new=calloc(1,sizeof(struct landmarkCDT));
    new->cmp=cmp;
    return new;
}

/**
 * Agrega un punto de interés #site a #meters metros del origen. Si ya había
 * un sitio, sólo queda #site (ver programa de testeo)
 */
void addLandmark(landmarkADT landmark, size_t meters, landmarkType site){
    size_t pos=POS(meters);
    if (landmark->amountSitesReserved <= pos){
        landmark->landmarks=realloc(landmark->landmarks, (pos+1) * sizeof(landmark->landmarks[0]));
        landmark->ocup=realloc(landmark->ocup, (pos+1) * sizeof(landmark->ocup[0]));
        for (int i=landmark->amountSitesReserved ; i<pos+1 ; i++){
            landmark->ocup[i]=0;
        }
        landmark->amountSitesReserved=pos+1;
    }

    if (landmark->ocup[pos] == 0){
        landmark->ocup[pos] = 1;
        landmark->amountSites++;
    }

    landmark->landmarks[pos]=site; 
}

/*
 * Retorna 1 si a esa distancia aproximada hay un sitio de interés. Ejemplo: si
 * meters es 135 retorna 1 si se registró algún sitio de interés entre los 100 y 199   
 * metros), 0 sinó
 */
int hasLandmark(const landmarkADT landmark, size_t meters){
    return landmark->ocup[POS(meters)];
}

/*
 * Retorna la distancia aproximada en la cual se encuentra el sitio de interés 
 * o -1 si no existe. Ejemplo: si el sitio de interés se indicó que está a 135
 * metros retorna 100, si se indicó a 1240 metros retorna 1200
 */
int distance(const landmarkADT landmark, landmarkType site){
    for (int i=0 ; i < landmark->amountSitesReserved ; i++){
        if (landmark->ocup[i] == 1 && !landmark->cmp(site,landmark->landmarks[i])){
            return i * 100;
        }
    }
    return -1;
}

/*
 * Retorna cuántos sitios de interés se registraron
 */
size_t landmarkCount(const landmarkADT landmark){
    return landmark->amountSites;
}

/*
 * Retorna un vector con los sitios de interés, en orden ascendente por distancia
 * al origen. Si no hubiera sitios de interés retorna NULL
 */
landmarkType * landmarks(const landmarkADT landmark){
    return landmarksBetween(landmark,0,landmark->amountSitesReserved * 100,NULL);
}

/*
 * Retorna un vector con los sitios de interés entre dos distancias, 
 * en orden ascendente por distancia al origen, dejando en *dim la cantidad
 * Si from es mayor que to o no hay sitios de interés en ese rango retorna NULL y
 * deja *dim en cero
 */
landmarkType * landmarksBetween(const landmarkADT landmark, size_t from, size_t to, size_t *dim){
    landmarkType * vec=NULL;

    int j=0, fromPos=POS(from), toPos=POS(to);

    for (int i=fromPos; i <= toPos && i < landmark->amountSitesReserved; i++){
        if (landmark->ocup[i] == 1){
            if (j % BLOCK == 0){
                vec=realloc(vec, (j+BLOCK) * sizeof(vec[0]));
            }
            vec[j++]=landmark->landmarks[i];
        }
    }

    if (j%BLOCK){
        vec=realloc(vec, j * sizeof(vec[0]));
    }

    if (dim != NULL){
        *dim=j;
    }

    return vec;
}

void freeLandmark(landmarkADT landmark){
    free(landmark->ocup);
    free(landmark->landmarks);
    free(landmark);
}