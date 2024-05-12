/*
Una partícula realiza un camino aleatorio dentro de un círculo de acuerdo a la siguientes reglas:
En tiempo t = 0 la partícula está en el centro ( x = 0, y = 0).
La partícula hace un paso aleatorio en una de las cuatro direcciones dada por
x = x - 1
x = x + 1
y = y - 1
y = y + 1
La caminata termina cuando se sale fuera del círculo ( x2 + y2>= r2 ).

Considerando cada punto como una estructura de componentes cartesianas y teniendo en cuenta que el 
tiempo se mide con un contador que se incrementa  en cada paso de la partícula, escribir un programa 
que para distintos tamaños de círculos determine experimentalmente la relación entre el tiempo requerido 
para terminar la caminata y el valor del radio.

Mostrar los valores hallados mediante una tabla cuyas columnas sean:
Radio
Tiempo
Relación (radio / tiempo)
*/
#define BLOCK 10
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIRECTIONS 4

// Función para generar un número aleatorio normalizado en [0,1) 
double randNormalize(){
    return rand () / ((double) RAND_MAX+1);
}

// Función para generar un número entero aleatorio en el rango [left, right]
int randInt(int left, int right){
    return ((int)(randNormalize()*(right-left+1)) + left);
}

// Función para inicializar la semilla del generador de números aleatorios
void randomize(){
    srand ((int)time(NULL));
}

typedef struct tabla{
    double radio;
    int tiempo;
    double relacion;
} tabla;

int
main(){
    double radio = 0;
    int x=0,y=0, tiempo=1, cant=0, aleatorio;
    tabla * valores=NULL;
    do {
        printf("Ingresar el radio\n");
        scanf("%lg",&radio);
    }
    while (radio<0);

    static int directionsx[]={0,0,1,-1};
    static int directionsy[]={1,-1,0,0};

    while ((x*x)+(y*y)<radio*radio){
        if (cant%BLOCK==0){
            valores=realloc(valores, (cant+BLOCK)*sizeof(valores[0]));
        }
        aleatorio=randInt(0,DIRECTIONS-1);
        x+=directionsx[aleatorio];
        y+=directionsy[aleatorio];
        valores[cant].radio=sqrt((x*x)+(y*y));
        valores[cant].tiempo=tiempo;
        valores[cant].relacion=((valores[cant].radio)/(valores[cant].tiempo));
        tiempo++;
        cant++;
    }
    valores=realloc(valores, cant);
    printf("RADIO - TIEMPO - RELACION\n");
    for (int i=0 ; i<cant ; i++){
        printf("%f - %6d - %10f\n", valores[i].radio, valores[i].tiempo, valores[i].relacion);
    }
    free(valores);
}
