/*
Hacer la función unDiaMas que reciba una fecha (día, mes, año) y le agregue un día. 
Debe distinguirse el front-end del back-end. Si hay error, los datos quedan intactos.
Asumir que existe una función llamada esBisiesto que acepta unparámetro entero con el número del año y 
devuelve 0 si el año ingresado no es bisiesto y distinto de 0 en caso contrario.
*/

#include <stdio.h>
#include <assert.h>
 
#define OK 1
#define ERROR !OK
 
int unDiaMas(int *dia, int *mes, int *anio);
void sumDia(int *dia, int *mes, int *anio, int bisiesto);
static int bisiesto(int);
 
int
main(void) {
    int dia, mes, anio;
 
    dia = 9, mes = 4, anio = 2021;
    printf("Fecha actual: %d/%d/%d\n", dia, mes, anio);
    if (unDiaMas(&dia, &mes, &anio))
        printf("Fecha con un dia mas: %d/%d/%d\n", dia, mes, anio);
    else
        printf("Error en los datos\n");
 
    dia = 1, mes = 1, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 2 && mes == 1 && anio == 2021);
 
    dia = 31, mes = 3, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 4 && anio == 2021);
 
    dia = 31, mes = 12, anio = 2020;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 1 && anio == 2021);
 
    printf("OK!\n");
    return 0;
}

static int
bisiesto(int anio) {
    int esb=0;
    if((anio%4 == 0 && anio%100!= 0) || anio%400 == 0)
        esb=1;
    return esb;
}

int daytab[2][12] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};

int
unDiaMas(int *dia, int * mes, int *anio){
    int bis=bisiesto(*anio);
    if (*dia<1 || *mes<1 || *mes>12 || *dia>daytab[bis][(*mes)-1] || *anio<0){
        return 0;
    }
    else{
        sumDia(dia, mes, anio, bis);
        return 1;
    }
}

void
sumDia(int *dia, int *mes, int *anio, int bisiesto){
    if (*dia==daytab[bisiesto][(*mes)-1]){
        *dia=1;
        if (*mes!=12){
            *mes+=1;
        }
        else{
            *mes=1;
            *anio+=1;
        }
    }
    else{
        *dia+=1;
    }
}