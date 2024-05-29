#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/tp11/tp11_ej17.h"

/*
Algunos parques (por ejemplo Central Park) contabilizan la cantidad de ardillas que hay en cada área del parque. 
El parque se divide en áreas de N x N metros, asumiendo que cada parque tiene una forma rectangular. 
Cada área se identifica por la coordenada de su esquina superior izquierda, siendo (0,0) el bloque que comprende un área de [0, N) 
metros en vertical y de [0, N) metros en horizontal (ver descripción en programa de prueba).
Se pide:
Implementar todas las estructuras necesarias, de forma tal que la función squirrelsInBlock pueda ser implementada de la 
forma más eficiente posible 
Implementar todas las funciones
*/

/**
 * Reserva los recursos para el conteo de ardillas en un parque agrupando las cantidades
 * por bloques (manzanas) de tamaño blockSizeMetres metros x blockSizeMetres metros
 * desde el extremo superior izquierdo del parque
 * Si blockSizeMetres es igual a 0 aborta
 */
squirrelCensusADT newSquirrelCensus(size_t blockSizeMetres);

/**
 * Registra una ardilla en el bloque (manzana) correspondiente al punto (yDistance, xDistance) donde
 * - yDistance es la distancia vertical en metros del extremo superior izquierdo del parque
 * - xDistance es la distancia horizontal en metros del extremo superior izquierdo del parque
 * Retorna cuántas ardillas fueron registradas en ese mismo bloque
 */
size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance);

/**
 * Retorna cuántas ardillas fueron registradas en el bloque correspondiente al punto (yDistance, xDistance)
 */
size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance);

/**
 * Libera los recursos utilizados para el conteo de ardillas en un parque
 */
void freeSquirrelCensus(squirrelCensusADT squirrelAdt);