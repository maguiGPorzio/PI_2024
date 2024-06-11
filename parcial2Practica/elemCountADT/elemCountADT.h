
typedef struct elemCountCDT * elemCountADT;
typedef int elemtype;
typedef unsigned long int size_t;
typedef int (*compare)(elemtype e1, elemtype e2);

 /* Crea todos los recursos para el TAD
 ** Arranca inicialmente sin elementos.
 */
 elemCountADT newElemCount(compare cmp);
 /* Registra una aparición de elem y retorna la cantidad actual de
 ** apariciones registradas.
 */
 size_t countElem(elemCountADT elemCountAdt, elemtype elem);
 /* Retorna la cantidad de elementos distintos registrados. */
 size_t distinctElems(elemCountADT elemCountAdt);
 /* Funciones de iteración para que se puedan consultar todos los elementos
 ** registrados en forma ordenada
 ** junto con la cantidad de apariciones de cada uno.
 */
 void toBegin(elemCountADT elemCountAdt);
 size_t hasNext(elemCountADT elemCountAdt);
 elemtype next(elemCountADT elemCountAdt, size_t * count);
 /* Libera los recursos utilizados por el TAD */
 void freeElemCount(elemCountADT elemCountAdt);