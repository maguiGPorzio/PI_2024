
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/getnum.h"

#define FUNCTION(x) ( (2*x*x) - (4*x) )

#define EPSILON 0.00001

#define CHUNK 20

typedef struct result{
    double (*roots)[2];
    int count;
} result;


typedef struct intervalo_t{
  double a;
  double b;
} intervalo_t;

double interval(intervalo_t * inter);

result rootsFinder(intervalo_t inter, double step);

void printResult(result rootFound);


int main(){
  
  intervalo_t inter;
  double step = interval(&inter);

  result rootFound = rootsFinder(inter, step);

  printResult(rootFound);


}

void printResult(result rootFound){

  int i;

  for (i=0; i<rootFound.count; i++){
    printf("Raiz en [%f, %f]\n", rootFound.roots[i][0], rootFound.roots[i][1]);
  }

}

result rootsFinder(intervalo_t inter, double step){

  int i, t;

  int signActual, signNext;
  double actualF, nextF;

  result rootFound;
  
  rootFound.roots = NULL;
  
  double next = (inter.a) + step;
  double actual = inter.a;


  for (i=t=0; actual <= inter.b; i++){

    if (!(t%CHUNK)){
      rootFound.roots = realloc(rootFound.roots, (t+CHUNK) * 2 * sizeof(double[2]));
    }

    actualF = FUNCTION(actual);
    nextF = FUNCTION(next);
  
    signActual = actualF < 0 ? -1 : 1;
    signNext = nextF < 0 ? -1 : 1;


    if ( ( actualF <=EPSILON && nextF >= -EPSILON) || (signActual * signNext < 0) ){
    
      rootFound.roots[t][0] = actual;
      rootFound.roots[t++][1] = next;

    }

    actual += step;
    next += step;

  }

  rootFound.count = t;

  return rootFound;

}

double interval(intervalo_t * inter){

  double step;  

  inter->a = getdouble("Ingrese el extremo izquierdo del intervalo: ");
  
  do{
  inter->b = getdouble("Ingrese el extremo derecho del intervalo: ");
  }while(inter->b <= inter->a);
  
  step = (inter->b - inter->a)/100000.0;

  return step;
}