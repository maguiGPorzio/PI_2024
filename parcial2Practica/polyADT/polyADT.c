

#include "/home/mgonzalezporzio/PI/polyADT.h"
#include <stdio.h>
#include <stdlib.h>

struct term {
    float coef;
    size_t degree;
    struct term * nextTerm;
};


struct polyCDT{
    struct term * firstTerm;
};

/*
 * Se cuenta con un TAD polinomio el cual implementa cada polinomio como una lista simplemente
 * encadenada sin header ordenada en forma descendente por el grado de la variable. El contrato para el TAD
 * poliniomio es el siguiente:
 *
 *   polinomio: (10, 5) -> (3, 6) -> (0, 1)
 *   polinomio: sum(a_i * x^i)_0^i
 *
 * Se pide:
 *  1) Definir struct polyCDT
 *  2) Implementar la funcion addPolynomial
 * */

/*
 *  Retorna un polinomio vacio ( NULL )
 * */
polyADT newPolynomial(void){
    polyADT new=malloc(sizeof(struct polyCDT));
    new->firstTerm=NULL;
    return new;
}

static struct term *
newTerm(struct term * terms, float coef, int degree){
    struct term * new=malloc(sizeof(struct term));
    new->coef=coef;
    new->degree=degree;
    new->nextTerm=terms;
    return new;
}

/*
 *  Retorna 1 si el polinomio esta vacio
 *          0 en caso contrario
 * */
int isEmpty(polyADT poly){
    return poly->firstTerm == NULL;
}

static struct term *
addTermRec(struct term * terms, float coef, int degree, int * added){
    if (terms == NULL || terms->degree < degree){
        *added=1;
        return newTerm(terms,coef,degree);
    }

    if (terms->degree == degree){
        return terms;
    }

    terms->nextTerm=addTermRec(terms->nextTerm, coef,degree,added);
    return terms;
}

/*
 *  Agrega un término al polinomio con el coeficiente y grado.
 *  Se inserta ordenado por grado, en forma decreciente.
 *  Si ya existe un termino con ese grado o no se pudo agregar retorna cero.
 *  Si no existia y se pudo agregar, retorna uno.
 * */
int addTerm(polyADT *poly, float coef, int degree){
    int added=0;
    (*poly)->firstTerm=addTermRec((*poly)->firstTerm, coef, degree, &added);
    return added;
}

static struct term *
addPolynomialRec(struct term * p1, struct term * p2){
    if (p1 == NULL && p2 == NULL){
        return NULL;
    }

    struct term * new;
    if (p2!=NULL && (p1 == NULL || p1->degree < p2->degree)){
        new=newTerm(NULL,p2->coef,p2->degree);
        new->nextTerm=addPolynomialRec(p1,p2->nextTerm);
    }
    else if (p1!=NULL && (p2 == NULL || p1->degree > p2->degree)){
        new=newTerm(NULL,p1->coef,p1->degree);
        new->nextTerm=addPolynomialRec(p1->nextTerm,p2);
    }
    else {
        new=newTerm(NULL,p1->coef + p2->coef,p1->degree);
        new->nextTerm=addPolynomialRec(p1->nextTerm,p2->nextTerm);
    }
    return new;
}

/*
 * Suma los polinomios enviados como parametro y obtiene un nuevo polinomio.
 * En caso de error retorna NULL
 * */
polyADT addPolynomial(polyADT p, polyADT q){
    polyADT new=malloc(sizeof(struct polyCDT));
    new->firstTerm=addPolynomialRec(p->firstTerm,q->firstTerm);
    return new;
}