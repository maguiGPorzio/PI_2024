#include <assert.h>
#include <stdio.h>

/* 
** Versión de test para vectores ordenados
** Tener en cuenta que el test evalúa resultado final, no eficiencia
*/

int
eliminaRepOrden( const int original[], int dimOrig, int resultado[]);

int main(void) {
  int v[] = { -3, -3, -1, 0, 1, 2, 2, 2, 3, 3, 3};
  int res[20];
  int dimRes;

  dimRes = eliminaRepOrden(v, 0, res);
  assert(dimRes==0);

  dimRes = eliminaRepOrden(v, 1, res);
  assert(dimRes==1);
  assert(res[0]==-3);

  dimRes = eliminaRepOrden(v, 2, res);
  assert(dimRes==1);
  assert(res[0]==-3);

  dimRes = eliminaRepOrden(v, 11, res);
  assert(dimRes==6);
  assert(res[0]==-3);
  assert(res[1]==-1);
  assert(res[2]==0);
  assert(res[3]==1);
  assert(res[4]==2);
  assert(res[5]==3);


  int n=80000;
  int v2[n];
  int res2[n];
  for (int i=0; i < n; i++)
     v2[i] = 100;
  dimRes = eliminaRepOrden(v2, n, res2);
  assert(dimRes==1);
  assert(res2[0]==100);

  for (int i=0; i < n; i++)
     v2[i] =i;
  dimRes = eliminaRepOrden(v2, n, res2);
  assert(dimRes==n);
  for (int i=0; i < n; i++)
    assert(res2[i]==i);

  puts("OK!");
  return 0;
}

int //hecha por mi
eliminaRepOrden(const int original[], int dimOrig, int resultado[]){
    int dimNuevo=0;
    if (dimOrig>0){
        int posicion=0;
        resultado[dimNuevo++]=original[posicion];
        for ( ; posicion<dimOrig-1 ; posicion++){
            if (original[posicion]!=original[posicion+1]){
                resultado[dimNuevo++]=original[posicion+1];
            }
        }
    }
    return dimNuevo;
}