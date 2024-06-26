#include <assert.h>
#include <stdio.h>
#include <string.h>
#define MAX_ALUMNOS 10

// Cambiar de acuerdo al tipo elegido 
// Si usan "matriz" de chars debe quedar
// typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];   

// Si usan vector de punteros a char debe quedar
// typedef char * TAlumnos[MAX_ALUMNOS];

typedef char * TAlumnos[MAX_ALUMNOS];
typedef char * TCurso[MAX_ALUMNOS];

void
separaCursos(char * alumnos[MAX_ALUMNOS],char * curso[MAX_ALUMNOS],char * cursoG[MAX_ALUMNOS],char * cursoH[MAX_ALUMNOS]);

int main(void){

    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso={'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

    alumnos[0]=""; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}

/*
Sean Nombre y Curso dos arreglos que contienen el nombre y el curso( ‘G’ o ‘H’) de cada uno de los
alumnos de una materia. Escribir una función que reciba dichos arreglos como parámetros de entrada y
retorne en parámetros de salida otros dos arreglos CursoG y CursoH con el nombre de los alumnos separados
por curso. El string vacío en el nombre indica fin del arreglo.
*/
void
separaCursos(char * alumnos[MAX_ALUMNOS],char * curso[MAX_ALUMNOS],char * cursoG[MAX_ALUMNOS],char * cursoH[MAX_ALUMNOS]){
    int i, j=0, h=0;
    for (i=0 ; alumnos[i][0] ; i++){
        if (curso[i]=='G')
            cursoG[j++]=alumnos[i];
        else
            cursoH[h++]=alumnos[i];
    }
    cursoG[j]="";
    cursoH[h]="";
}