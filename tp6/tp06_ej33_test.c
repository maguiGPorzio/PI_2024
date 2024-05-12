#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define CANT_ALFABETO 26
#define MAX 100
#define NUM(M) (M) -'A'
#define LETRA(M) (M) +'A'

//LISTO

void crearAlfabeto(char alfa[]);
void
desordenaArreglo(char arreglo[], int dim);

void 
codificar (char * mensaje , char alfabeto[], char * mensCod);
void
decodificar (char *mensaje, char alfabeto[], char * mensDecod);
int 
posicion (char car, char alfabeto[]);
int randInt(int izq, int der);

int main(void) {
  char msg[MAX];
  char dest[MAX];
  // Debemos probar con mayusculas, porque siempre decodifica a mayuscuas
  char *s = "MENSAJE A CODIFICAR";
  char *s2 = "Mensaje a codificar";
  char alpha[MAX];
  crearAlfabeto(alpha);
  codificar(s, alpha, msg);
  assert(strlen(s)==strlen(msg));
  assert(strcmp(s, msg) != 0);
  decodificar(msg, alpha, dest);
  assert(strcmp(dest, s) == 0);

  codificar(s2, alpha, msg);
  assert(strlen(s2)==strlen(msg));
  assert(strcmp(s2, msg) != 0);
  decodificar(msg, alpha, dest);
  assert(strcmp(dest, s) == 0);
  
  puts("OK");
  return 0;
}

void crearAlfabeto(char alfa[])
{
    int i;
    for (i = 0; i < CANT_ALFABETO; i++)
        alfa[i] = 'A' + i;
    desordenaArreglo(alfa, CANT_ALFABETO);
    return;
}

void
desordenaArreglo(char arreglo[], int dim)
{
    int i, j, aux;
    srand((int)time(NULL));
  
    for (i = 0; i < dim; i++)
    {
        j = randInt(i, dim-1);
        aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;
    }
    return;
}

void 
codificar (char * mensaje , char alfabeto[], char * mensCod){
  char car;
  int i;
  for (i=0 ; mensaje[i] ; i++){
    car=toupper(mensaje[i]);
    if (car>='A' && car<='Z'){
      mensCod[i]=alfabeto[NUM(car)];
    }
    else{
      mensCod[i]=car;
    }
  }
  mensCod[i]=0;
}

void
decodificar (char *mensaje, char alfabeto[], char * mensDecod){
  char car;
  int i;
  for (i=0 ; mensaje[i] ; i++){
    car=toupper(mensaje[i]);
    if (car>='A' && car<='Z'){
      mensDecod[i]=LETRA(posicion(car,alfabeto));
    }
    else{
      mensDecod[i]=car;
    }
  }
  mensDecod[i]=0;
}

int 
posicion (char car, char alfabeto[]){
  for (int i=0 ; i<CANT_ALFABETO ; i++){
    if (car==alfabeto[i]){
      return i;
    }
  }
}