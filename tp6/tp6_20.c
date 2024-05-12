#include <stdio.h>
#include <assert.h>
#define DIM 9

int chequearFil(const char m[]){
      char v[DIM] = {0};  // vector auxiliar para marcar si un dígito ya estaba
      int aux, ok = 1;
      for(int i = 0; i < DIM && ok; i++){
            aux = m[i]-1;
            if(v[aux] == 0){
                  v[aux]++;
            }else{
                  ok = 0; 
            }
      }
      return ok;
}

int chequearCol(char m[][DIM], int col){
   char v[DIM] = {0};
   for(int i = 0; i < DIM; i++){
       aux = m[i][col]-1;
       if(v[aux] == 1){
           return 0;
       v[aux]++;
   }
   return 1;
}

int chequearSubcuadrado(char m[][DIM], int fil, int col){
   char v[9] = {0};
   for(int i = fil; i < fil + 3; i++){
       for(int j = col; j < col + 3 && ok; j++){
           aux = m[i][j];
           if(aux > = 1 && aux < = 9 && v[aux-1] == 0){
                v[aux-1]++;
            }else{
                 return 0;
            }
       }
   }
   return 1;
}

int sudokuSolver(char m[][DIM]){
      int ok=1;
      for(int i = 0; i < DIM && ok; i += 3){
            for(int j = 0; j < DIM && ok; j+= 3){
                  ok = chequearSubcuadrado(m, i, j);
            }
      }  
      // Al verificar los cuadrados verificamos que estén entre 1 y 9
      if(ok){
            for(int k = 0; k < DIM && ok; k++){
                  ok = chequearFil(m[k]);
            }
      if(ok){
            for(int n = 0; n < DIM && ok; n++){
                  ok = chequearCol(m, n);
            }
      }
   }
   return ok;
}
