#include <stdio.h>
#include <stdlib.h>

typedef struct complejoCDT * complejoADT;

complejoADT 
nuevoComp (int real, int imag);

int
parteRealComp(complejoADT complejo);

int 
parteImagComp(complejoADT complejo);

complejoADT
sumaComp(complejoADT comp1,complejoADT comp2);

complejoADT
restaComp(complejoADT comp1,complejoADT comp2);

complejoADT
multiplicaComp(complejoADT comp1,complejoADT comp2);

complejoADT
divideComp(complejoADT comp1,complejoADT comp2);

complejoADT
conjugadoComp(complejoADT complejo);

void
liberaComp(complejoADT complejo);
