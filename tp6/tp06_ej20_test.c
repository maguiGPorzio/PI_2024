#include <stdio.h>
#include <assert.h>

#define DIM 9
#define DIM_CUADRANTE 3

int sudokuSolver(char m[][DIM]);
int valSub (char m[][DIM], unsigned cuadrante);
int valFila (const char v[]);
int valColumna (char m[][DIM],int columna);
int valRango(char m[][DIM]);

int main(void) {
  // Una matriz vacía no es solución
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku)==0);

  char sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku2)==1);
  
  char sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  char sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };

  assert(sudokuSolver(sudoku4)==0);

  char sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku5)==0);

  return 0;
}


int 
sudokuSolver(char m[][DIM]){
    if (!valRango(m)){
        return 0;
    }
    for (int i=0 ; i<DIM ; i++){
        if ((!valFila(m[i])) || (!valColumna(m,i)) || (!valSub(m,i)) ){
            return 0;
        }
    }
    return 1;
}

int
valRango(char m[][DIM]){
      for (int i=0 ; i<DIM ; i++){
            for (int j=0 ; j<DIM ; j++){
                  if (m[i][j]<1 || m[i][j]>9){
                        return 0;
                  }
            }
      }
      return 1;
}

int
valSub (char m[][DIM], unsigned cuadrante){
      int fila=(cuadrante/3)*3;
      int columna=(cuadrante%3)*3;
      int aux[DIM]={0};
      for (int i=fila ; i<(DIM_CUADRANTE+fila) ; i++){
            for (int j=columna ; j<(DIM_CUADRANTE+columna) ; j++){
                  if (aux[m[i][j]-1]==0){
                        aux[m[i][j]-1]=1;
                  }
                  else{
                        return 0;
                  }
            }
      }
      return 1;
}

int
valFila (const char v[]){
      int aux[DIM]={0};
      for (int i=0 ; i<DIM ; i++){
            if (aux[v[i]-1]==0){
                  aux[v[i]-1]=1;
            }
            else{
                  return 0; 
            }
      }
      return 1;
}

int
valColumna (char m[][DIM],int columna){
      int aux[DIM]={0};
      for (int i=0 ; i<DIM ; i++){
            if (aux[m[i][columna]-1]==0){
                  aux[m[i][columna]-1]=1;
            }
            else {
                  return 0; 
            }
      }
      return 1;
}
