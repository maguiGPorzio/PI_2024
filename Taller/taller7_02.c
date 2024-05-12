/*
Hacer un programa que cargue datos en una factura y muestre su importe total
La factura tiene hasta TOTAL_ITEMS items. Cada item tiene código, descripción y precio.

Para cargar cada item en la factura desarrollar y usar la función
tItem leerItem();
que obtiene un item ya validado.
*/
#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/getnum.h"
  
#define TOTAL_ITEMS 2
#define MAX_LONG 10
 
typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;
 
typedef tItem tFactura[TOTAL_ITEMS];
 
void cargar(tFactura fact, int cant);
float importe(tFactura fact, int cant);
 
int
main(void) {
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("%.2f\n", importe(f, TOTAL_ITEMS));
    return 0;
}

tItem
leerItem(int i){
    tItem item;

    printf("Para el articulo %d \n", i+1);
    item.codigo=getint("Ingrese el codigo: ");
    printf("Ingrese la descripcion: ");
    scanf("%s",item.desc);
    item.precio=getfloat("Ingrese el precio: ");

    return item;
}

void cargar(tFactura fact, int cant){
    for (int i=0 ; i<cant ; i++){
        fact[i]=leerItem(i);
    }
}

float importe(tFactura fact, int cant){
    float imp=0;
    for (int i=0 ; i<cant ; i++){
        imp+=fact[i].precio;
    }
    return imp;
}