
/*
Algunos parques (por ejemplo Central Park) contabilizan la cantidad de ardillas que hay en cada área del parque. 
El parque se divide en áreas de N x N metros, asumiendo que cada parque tiene una forma rectangular. 
Cada área se identifica por la coordenada de su esquina superior izquierda, siendo (0,0) el bloque que comprende un área de [0, N) 
metros en vertical y de [0, N) metros en horizontal (ver descripción en programa de prueba).
Se pide:
Implementar todas las estructuras necesarias, de forma tal que la función squirrelsInBlock pueda ser implementada de la 
forma más eficiente posible 
Implementar todas las funciones

Implementar todas las estructuras necesarias, de forma tal que la función squirrelsInBlock pueda ser implementada de la forma más eficiente posible 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/tp11/tp11_ej17.h"
#define BLOCK(M,N) (M) / (N)


struct block{
    size_t * squirrelsInBlock; //con este puntero accedo a la x
    size_t horizBlocksRes; //estas son las blocks horizontales que tengo para poner las ardillas 
};

struct squirrelCensusCDT{
    struct block * verBlocks; //con este puntero accedo a la y
    size_t verBlocksRes; //estas son las blocks verticales que ya tengo espacio para poner ardillas
    size_t blockSizeMetres;
};

/**
 * Reserva los recursos para el conteo de ardillas en un parque agrupando las cantidades
 * por bloques (manzanas) de tamaño blockSizeMetres metros x blockSizeMetres metros
 * desde el extremo superior izquierdo del parque
 * Si blockSizeMetres es igual a 0 aborta
 */
squirrelCensusADT newSquirrelCensus(size_t blockSizeMetres){
    squirrelCensusADT new=calloc(1,sizeof(struct squirrelCensusCDT));
    new->blockSizeMetres=blockSizeMetres;
    return new;
}

/**
 * Registra una ardilla en el bloque (manzana) correspondiente al punto (yDistance, xDistance) donde
 * - yDistance es la distancia vertical en metros del extremo superior izquierdo del parque
 * - xDistance es la distancia horizontal en metros del extremo superior izquierdo del parque
 * Retorna cuántas ardillas fueron registradas en ese mismo bloque
 */
size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance){
    int blocky= BLOCK(yDistance,squirrelAdt->blockSizeMetres);
    int blockx= BLOCK(xDistance,squirrelAdt->blockSizeMetres);

    if (blocky >= squirrelAdt->verBlocksRes){
        squirrelAdt->verBlocks=realloc(squirrelAdt->verBlocks, (blocky+1) * sizeof(struct block));
        for (int i=squirrelAdt->verBlocksRes ; i < blocky+1 ; i++){
            squirrelAdt->verBlocks[i].horizBlocksRes=0;
            squirrelAdt->verBlocks[i].squirrelsInBlock=NULL;
        }
        squirrelAdt->verBlocksRes=blocky+1;
    }

    if (blockx >= squirrelAdt->verBlocks[blocky].horizBlocksRes){
        squirrelAdt->verBlocks[blocky].squirrelsInBlock=realloc(squirrelAdt->verBlocks[blocky].squirrelsInBlock, (blockx + 1) * sizeof(size_t));
        for (int i=squirrelAdt->verBlocks[blocky].horizBlocksRes ; i < blockx + 1 ; i++){
            squirrelAdt->verBlocks[blocky].squirrelsInBlock[i]=0;
        }
        squirrelAdt->verBlocks[blocky].horizBlocksRes=blockx+1;
    }

    return ++squirrelAdt->verBlocks[blocky].squirrelsInBlock[blockx];
}

/**
 * Retorna cuántas ardillas fueron registradas en el bloque correspondiente al punto (yDistance, xDistance)
 * ESTA TIENE QUE SER LA MAS EFICIENTE
 */
size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance){
    int blocky= BLOCK(yDistance,squirrelAdt->blockSizeMetres);
    int blockx= BLOCK(xDistance,squirrelAdt->blockSizeMetres);

    if (squirrelAdt->verBlocksRes <= blocky || squirrelAdt->verBlocks[blocky].horizBlocksRes <= blockx){
        return 0;
    }

    return squirrelAdt->verBlocks[blocky].squirrelsInBlock[blockx];
}


/**
 * Libera los recursos utilizados para el conteo de ardillas en un parque
 */
void freeSquirrelCensus(squirrelCensusADT squirrelAdt){
    for (int i=0 ; i < squirrelAdt->verBlocksRes ; i++){
        if (squirrelAdt->verBlocks[i].squirrelsInBlock != NULL){
            free(squirrelAdt->verBlocks[i].squirrelsInBlock);
        }
    }
    free(squirrelAdt->verBlocks);
    free(squirrelAdt);
}