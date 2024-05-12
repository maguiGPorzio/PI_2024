#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCK 10

typedef char * TAlumnos[]; 

char **
aprobados(TAlumnos alumnos, int promedio[]);

int main(void){

    TAlumnos alumnos = {"Juan", "Pedro", "Martin", ""};
    int notas[] = {1, 4, 10, 2, 10, 11};
    
    char ** apr = aprobados(alumnos, notas);
    if(apr == NULL){
        printf("No hay suficiente memoria!\n");
        return 1;
    }
    assert(!strcmp(alumnos[1], apr[0]) && !strcmp(alumnos[2], apr[1]) && !strcmp(alumnos[3], apr[2]));

    puts("OK!");
    // En este programa no liberamos la memoria que utilizamos. Que ocurre si compilamos con "-fsanitize=address"?
    return 0;
}

/*
Escribir la función aprobados que reciba dos vectores, uno con los nombres y apellidos de los
alumnos de un curso y un vector de enteros donde se almacene el promedio de cada alumno en el curso. La
función debe retornar en su nombre un nuevo vector con los alumnos que hayan aprobado el curso, esto es,
que tengan un promedio mayor o igual a 4.
Como indicador de final del arreglo de alumnos se tiene el string vacío.
El código de la función debe ser tal que funcione tanto para vectores de punteros a char como para
"matriz" de caracteres.
*/

char **
aprobados(TAlumnos alumnos, int promedio[]){
    char ** aprobados=NULL;

    int cantAlumnos, cantAprobados=0;
    for (cantAlumnos=0 ; alumnos[cantAlumnos][0]!='\0' ; cantAlumnos++){
        if (promedio[cantAlumnos]>=4){
            if (cantAprobados%BLOCK==0){
                aprobados=realloc(aprobados,(cantAprobados+BLOCK)*sizeof(aprobados[0]));
            }
            aprobados[cantAprobados++]=alumnos[cantAlumnos];
        }
    }
    aprobados=realloc(aprobados,(cantAprobados+1)*sizeof(aprobados[0]));
    aprobados[cantAprobados]="";
    return aprobados;
}