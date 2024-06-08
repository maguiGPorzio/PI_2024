typedef struct setCDT * setADT;

typedef int elemType;

typedef int (*compare)(elemType, elemType);

/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío */
setADT newSet(...);

/* Inserta elem siempre y cuando el elemento no esté
** en el conjunto. Retorna la cantidad total de elementos luego de agregar el elemento nuevo
*/
int add(setADT set, elemType elem);

/* Retorna cuántos elementos hay en el conjunto */
int size(const setADT set);

/* Retorna una copia del mayor elemento del conjunto, NULL si no hay elementos */
elemType * max(const setADT set);

/* Retorna una copia del menor elemento del conjunto, NULL si no hay elementos */
elemType * min(const setADT set);

/* Retorna una copia del último elemento agregado en el conjunto, NULL si está vacío */
elemType * last(const setADT set);

/* Retorna un vector con todos los elementos del conjunto, ordenados en forma ascendente */
elemType * setToArray(const setADT set);
