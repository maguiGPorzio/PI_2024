#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCK 10

typedef char * TAlumnos[]; 
void liberaAprobados(char ** aprobados);

char **
aprobados(TAlumnos alumnos, int promedio[]);

int main(void){

    TAlumnos alumnos = {"Juan", "Pedro", "Martin", ""};
    int notas[] = {1, 4, 10, 2, 10, 11};
    
    char ** apr = aprobados(alumnos, notas);
    if(apr == NULL){
        puts("No hay suficiente memoria!");
        return 1;
    }
    assert(!strcmp(alumnos[1], apr[0]) && !strcmp(alumnos[2], apr[1]) && !strcmp(alumnos[3], apr[2]));
    
    liberaAprobados(apr);
    
    puts("OK");
    return 0;
}

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

void 
liberaAprobados(char ** aprobados){
    free(aprobados);
}