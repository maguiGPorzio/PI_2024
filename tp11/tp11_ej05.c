#include <stdio.h>
#include "/home/mgonzalezporzio/PI/tp11/tp11_ej05.h" 

struct complejoCDT{
    int real;
    int imag;
};

complejoADT
nuevoComp (int parteReal, int parteImag){
    complejoADT complejo=malloc(sizeof(struct complejoCDT));
    complejo->real=parteReal;
    complejo->imag=parteImag;
    return complejo;
}

int
parteRealComp(complejoADT complejo){
    return complejo->real;
}

int 
parteImagComp(complejoADT complejo){
    return complejo->imag;
}

complejoADT
sumaComp(complejoADT comp1,complejoADT comp2){
    complejoADT nuevoComplejo=malloc(sizeof(struct complejoCDT));
    nuevoComplejo->imag=comp1->imag + comp2->imag;
    nuevoComplejo->real=comp1->real + comp2->real;
    return nuevoComplejo;
}

complejoADT
restaComp(complejoADT comp1,complejoADT comp2){
    complejoADT nuevoComplejo=malloc(sizeof(struct complejoCDT));
    nuevoComplejo->imag=comp1->imag - comp2->imag;
    nuevoComplejo->real=comp1->real - comp2->real;
    return nuevoComplejo;
}

complejoADT
multiplicaComp(complejoADT comp1,complejoADT comp2){
    complejoADT nuevoComplejo=malloc(sizeof(struct complejoCDT));
    nuevoComplejo->imag=(comp1->real * comp2->imag) + (comp1->imag * comp2->real);
    nuevoComplejo->real=(comp1->real * comp2->real) - (comp1->imag * comp2->imag);
    return nuevoComplejo;
}

complejoADT
divideComp(complejoADT comp1,complejoADT comp2){
    complejoADT nuevoComplejo=malloc(sizeof(struct complejoCDT));
    complejoADT num=multiplicaComp(comp1,comp2);
    double div= (comp2->real * comp2->real) - (comp2->imag * comp2->imag);
    nuevoComplejo->real=(num->real)/div;
    nuevoComplejo->imag=(num->imag)/div;
    liberaComp(num);
    return nuevoComplejo;
}

complejoADT
conjugadoComp(complejoADT complejo){
    complejoADT nuevoComplejo=malloc(sizeof(struct complejoCDT));
    nuevoComplejo->real=complejo->real;
    nuevoComplejo->imag=(-1) * complejo->imag;
    return nuevoComplejo;
}

void
liberaComp(complejoADT complejo){
    free(complejo);
}
