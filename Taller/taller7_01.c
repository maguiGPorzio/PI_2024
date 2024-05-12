/*
Implementar una función que reciba un arreglo de nombres de alumnos, el
arreglo de notas y retorne la lista de aprobados.
El prototipo es:
int obtenerAprobados(char * arrNombres[], int tam,
char * aprobados[], int notas[]);
● ¿Qué retorna la función? -->cant de aprobados
● ¿Se pueden modificar los nombres en el arreglo destino?
*/
#include <stdio.h>
#define APROBADO 4

int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], int notas[]);

int
main(void) {
    char *arrNombres[] = {"anita", "pepe", "fabi", "carlos", "tere"};
    char *aprobados[5];
    int notas[] = {3, 4, 8, 10, 1};
    int tam, tamApro;
    tam = sizeof(arrNombres) / sizeof(char *);
    mostrarNombres(arrNombres, tam);
    tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
    printf("Aprobados:\n");
    mostrarNombres(aprobados, tamApro);
    return 0;
}

int 
obtenerAprobados (char * arrNombres[], int tam, char * aprobados[], int notas[]){
    int h=0;
    for (int i=0 ; i<tam ; i++){
        if (notas[i]>=APROBADO){
            aprobados[h++]=arrNombres[i];
        }
    }
    return h;
}