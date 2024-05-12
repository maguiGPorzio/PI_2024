#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#define DIM 30



void shuffle(int vecDes[], unsigned int dim);
double randNormalize();
int randInt(int left, int right);
void randomize();

int main(void) {
  int v[DIM];
  randomize();

  for(int i=0; i<DIM; i++) {
	  v[i] = -10 + i*2;
  }
  shuffle(v,DIM);

  puts("Vamos a imprimir el vector, debería estar desordenado");
  for(int i=0; i<DIM; i++) {
	  printf("%03d\t", v[i]);
  }
  putchar('\n');

  int aux=v[0];
  puts("A continuación desordeamos un vector vacío, no debería fallar");
  shuffle(v,0);
  assert(v[0]==aux);

  return 0;
}

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

void
shuffle(int vecDes[],unsigned int dim){
    srand ((int)time(NULL));
    int valorActual;
    int posicion;
    for (int i=0 ; i<dim ; i++){
        valorActual=vecDes[i];
        posicion=randInt(0,dim-1);
        vecDes[i]=vecDes[posicion];
        vecDes[posicion]=valorActual;
    }
    return; 
}
