#include <stdio.h>
#include <assert.h>

#define COLS 4


int sonAmigas(int (m1[])[COLS], unsigned int fils1,int (m2[])[COLS], unsigned int fils2);
//devuelve true si m1 es amigo de m2 no chequea lo contrario
int esAmiga(int (m1[])[COLS], unsigned int fils1,int (m2[])[COLS], unsigned int fils2);
//devuelve true si v es amigo de alguna fila de m 
int vecEnMatriz (const int v1[],unsigned int fils1,int (m2[])[COLS], unsigned int fils2);
//devuelve true si v1 esta contenido en v2
int contiene (const int v1[], const int v2[],unsigned dim);


int 
main(void)
{
  int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  assert(sonAmigas(m1,3,m2,4)==1);
  assert(sonAmigas(m1,1,m2,4)==1);
  assert(sonAmigas(m1,2,m2,4)==1);
  assert(sonAmigas(m1,2,m2,2)==0);
  assert(sonAmigas(m2,4,m1,3)==2);
  assert(sonAmigas(m1,3,m3,1)==0);
  assert(sonAmigas(m3,1,m1,3)==0);
  int res = sonAmigas(m1,3,m1,3);
  assert(res==1 || res==2);
  
  printf("OK !\n");

  return 0;
}

int 
sonAmigas(int (m1[])[COLS], unsigned int fils1,int (m2[])[COLS], unsigned int fils2){
  if (esAmiga(m1,fils1,m2,fils2)){
    return 1;
  }
  if (esAmiga(m2,fils2,m1,fils1)){
    return 2;
  }
  return 0;
}

int
esAmiga(int (m1[])[COLS], unsigned int fils1,int (m2[])[COLS], unsigned int fils2){
  for (int i=0 ; i<fils1 ; i++){
    if (!vecEnMatriz(m1[i],fils1,m2,fils2)){
      return 0;
    }
  }
  return 1;
}

int
vecEnMatriz (const int v1[],unsigned int fils1,int (m2[])[COLS], unsigned int fils2){
  for(int i=0 ; i<fils2 ; i++){
    if (contiene(v1,m2[i],COLS)){
      return 1;
    }
  }
  return 0;
}

int 
contiene (const int v1[], const int v2[],unsigned dim){
  int i,j;
  for (i=0,j=0 ; i<dim && j<dim ; ){
    if (v1[i]<v2[j]){
      return 0;
    }
    else if (v1[i]==v2[j]){
      i++;
    }
    else { //v1[i]>v2[j]
      j++;
    }
  }

  return i==dim;
}

