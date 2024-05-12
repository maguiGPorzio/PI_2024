#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <stdlib.h>

#define COLS 7
#define FILS 6
#define BLOCK 10
#define DIRECTIONS 8
#define IS_IN_GRID(i,j,alto,ancho) ((i)>=0 && (i)<(alto) && (j)>=0 && (j)<(ancho))


typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
};

// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra se busca en la sopa de 
//       letras.
//.      Si en vez de hacerlo así recorren la matriz y por cada letra buscan si hay una palabra en el diccionario
//       que empiece con esa letra, tienen que cambiar el testeo para que coincida con el orden en que se encuentran.

struct posicion * //retorna un vector con las palabras encontradas y su la fila columna y direccion donde fueron encontradas 
resolverSopa(char * diccionario[],char sopa[FILS][COLS]);
int //va a retornar 1 si copio o 0 si no copio
buscarPalabra(char * palabra, char sopa[FILS][COLS],struct posicion * palabrasEncontradas);
int 
palabraEnDirec(int direccion, char * palabra, char sopa[FILS][COLS], int i, int j);


int main(void) {
  char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
   
  char sopa[FILS][COLS] =
     {{'X','X','X','O','X','X','X'},
      {'A','P','A','C','Y','Y','O'},
      {'Z','E','Z','R','Z','C','X'},
      {'E','R','R','O','R','X','X'},
      {'X','R','I','O','I','E','X'},
      {'X','O','X','X','O','X','X'}};
  
  struct posicion * res = resolverSopa(diccionario, sopa);
  // La cantidad de palabras encontradas debe ser 9
  int expected = 9;
  int count = 0;
  while ( res[count].palabra != NULL){ 
    //printf("%ld\n", res[count].fila);
    //printf("%ld\n", res[count].columna);
    //printf("%d\n", res[count].direccion);
    printf("%s\n", res[count++].palabra);
  }
  assert(count == expected);

  assert(strcmp(res[0].palabra,"ARRE")==0);
  assert(res[0].fila==1);
  assert(res[0].columna==2);
  assert(res[0].direccion==D_AB);

  assert(strcmp(res[3].palabra,"ORCO")==0);
  assert(res[3].fila==3);
  assert(res[3].columna==3);
  printf("%d\n", res[3].direccion);
  assert(res[3].direccion==ARR);
  
  assert(strcmp(res[4].palabra,"ORCO")==0);
  assert(res[4].fila==4);
  assert(res[4].columna==3);
  assert(res[4].direccion==D_AR);

  assert(strcmp(res[6].palabra,"REA")==0);
  assert(res[6].fila==3);
  assert(res[6].columna==2);
  assert(res[6].direccion==I_AR);

  puts("OK");
  return 0;
}

struct posicion * //retorna un vector con las palabras encontradas y su la fila columna y direccion donde fueron encontradas 
resolverSopa(char * diccionario[],char sopa[FILS][COLS]){
  struct posicion * palabrasEncontradas=NULL; //creo el vector donde voy a poner las palabra con sus datos 
  int cantPalEnc=0;
  for (int i=0 ; diccionario[i][0] ; i++){ //le voy pasando palabra por palabra 
    if (cantPalEnc%BLOCK==0){
      palabrasEncontradas=realloc(palabrasEncontradas,(cantPalEnc+BLOCK)*sizeof(palabrasEncontradas[0]));
    }
    //le paso directamente la direccion de memoria donde quiero que guarde los datos
    //si buscarPalabra retorna 0 es porque no guardo ningun dato porque no encontro la palabra
    cantPalEnc+=buscarPalabra(diccionario[i],sopa,palabrasEncontradas+cantPalEnc); 

  }
  palabrasEncontradas=realloc(palabrasEncontradas,(cantPalEnc)*sizeof(palabrasEncontradas[0]));

  return palabrasEncontradas;
}

int //va a retornar 1 si copio o 0 si no copio
buscarPalabra(char * palabra, char sopa[FILS][COLS],struct posicion * palabrasEncontradas){
  printf("%s\n",palabra);
  int esta=0,i,j,h,aparecio=0;
  for (i=0 ; i<FILS; i++){ //recorre la sopa de letras letra por letra 
    for (j=0 ; j<COLS; j++){
      for (h=0 ; h<DIRECTIONS ; h++){
        aparecio=palabraEnDirec(h,palabra,sopa,i,j); //recorre todas las direcciones de la letra de la matriz sopa y retorna 1 si encontro la palabra
        esta+=aparecio;
        if (aparecio){//si la encontro en alguna direccion guardo en palabras encontradas los datos de donde la encontro 
          palabrasEncontradas+=esta-1;
          palabrasEncontradas->columna=j;
          palabrasEncontradas->fila=i;
          palabrasEncontradas->direccion=h;
          palabrasEncontradas->palabra=palabra;
          aparecio=0;
        }
      }
    }
  }
  return esta;
}

int 
palabraEnDirec(int direccion, char * palabra, char sopa[FILS][COLS], int i, int j){
  static int di[]={0,0,1,-1,-1,1,-1,1};
  static int dj[]={1,-1,0,0,-1,-1,1,1};

  int h;

  for (h=0 ; palabra[h] && IS_IN_GRID(i,j,FILS,COLS); h++){
    if (palabra[h]!=sopa[i][j]){
      return 0;
    }
    i+=di[direccion];
    j+=dj[direccion];
  }

  if (!palabra[h]){
    return 1;
  }
  return 0;
}