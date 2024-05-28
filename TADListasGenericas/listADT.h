//
// Created on 22/05/2024.
// TAD para listas genéricas, ordenadas y sin repetidos

#ifndef UNTITLED6_LISTADT_H
#define UNTITLED6_LISTADT_H

typedef struct listCDT * listADT;

typedef char * elemType; // char * porque son strings

// función para poder comparar dos elementos
// retorna
//     negativo si e1 es "menor" que e2 (e1 debe estar antes que e2)
//     cero si son "iguales" (representan lo mismo)
//     positivo si e1 es "mayor" que e2 (e1 debe estar después que e2)
typedef int (*compare) (elemType e1, elemType e2);

listADT newList(compare cmp);

//listADT newList(int (*cmp) (elemType, elemType));

void freeList(listADT list);

int isEmptyList(const listADT list);

int belongsList(const listADT list, elemType elem);

/**
 *
 * @param list
 * @param elem
 * @return 1 si lo agregó, cero si ya estaba
 */
int insertList(listADT list, elemType elem);

int deleteList(listADT list, elemType elem);

int sizeList(const listADT list);

elemType buscar (const listADT list, int indice);

void map(const listADT list, elemType (*funcion) (elemType));

//////////////////////////////
// Implementamos un iterador para recorrer la lista en forma eficiente

/** El usuario avisa que va a recorrer la lista */
void toBegin(listADT list);

/* Le devuelve al usuario el siguiente.
 * La primer llamada posterior a toBegin retorna el primer elemento
 * Si no hay uno isguiente, aborta
 */
elemType next(listADT list);

/* retorna 1 si hay un elemento siguiente (nse puede llamar a next)
 * 0 si no hay elemento siguiente (si el usuario llama a next, aborta
 */
int hasNext(listADT list);

#endif //UNTITLED6_LISTADT_H
