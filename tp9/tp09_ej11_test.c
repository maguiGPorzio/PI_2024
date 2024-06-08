#include <stdio.h>
#include <assert.h>

#define MAX 10
#define IS_IN_GRID(i,j,alto,ancho) ((i)>=0 && (i)<(alto) && (j)>=0 && (j)<(ancho))
#define DIRECTIONS 4

void reemplazo(int matriz[][MAX], int dim, int fil, int col);

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};

  reemplazo(m, 5, 1, 2);
  
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}

void
dirMat(int direc, int matriz[][MAX], int dim, int fil, int col){
   static int di[]={1,1,-1,-1};
   static int dj[]={-1,1,-1,1};

   fil+=di[direc];
   col+=dj[direc];

   if (!IS_IN_GRID(fil,col,dim,dim)){
      return;
   }

   matriz[fil][col]=!matriz[fil][col];

   dirMat(direc,matriz,dim,fil,col);
}

void 
reemplazo(int matriz[][MAX], int dim, int fil, int col){

   for (int i=0 ; i<DIRECTIONS ; i++){
      dirMat(i,matriz,dim,fil,col);
   }

   matriz[fil][col]=!matriz[fil][col];
}