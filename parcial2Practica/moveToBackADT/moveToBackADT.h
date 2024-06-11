
typedef struct moveToBackCDT * moveToBackADT;

typedef struct {
    int code;
    char * name;
} elemType;

/*
** Retorna 0 si los elementos son iguales,
** negativo si e1 es "menor" que e2 y
** positivo si e1 es "mayor" que e2
*/
static int compare(elemType elem1, elemType elem2) {
    return elem1.code - elem2.code;
}


/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío */
moveToBackADT newmoveToBack();

/* Libera todos los recursos del TAD */
void freemoveToBack(moveToBackADT m);

/* Inserta un elemento si no está en el conjunto. Lo inserta al
principio.
** Retorna 1 si lo agregó, 0 si no.
*/
unsigned int add(moveToBackADT m, elemType elem);

/* Retorna una copia del elemento. Si no existe retorna NULL.
** Si el elemento estaba lo intercambia con el que sigue. */
elemType * getElement(moveToBackADT m, elemType elem);

/* Retorna la cantidad de elementos que hay en el conjunto */
unsigned int size(const moveToBackADT m);

/* Retorna un vector con todos los elementos del conjunto
** y deja en *dim la dimensión del vector
** Si el conjunto es vacío retorna NULL y dim no cambia.
*/
elemType * getAll(const moveToBackADT m, size_t * dim);

/* Elimina un elemento si está en el conjunto.
** Retorna 1 si lo borró, 0 si no.
*/
unsigned int delete(moveToBackADT m, elemType elem);