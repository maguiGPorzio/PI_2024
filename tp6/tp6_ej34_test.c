#include <stdio.h>
#include <assert.h>
#define FILS 4
#define COLS 4

//LISTO

int nextStep(char cells[FILS][COLS]);
int 
celMuerta (char cells[FILS][COLS], int fil, int col,char aux[FILS][COLS]);
int 
checkDirections(char cells[FILS][COLS], int fil, int col);
int 
celViva (char cells[FILS][COLS], int fil, int col,char aux[FILS][COLS]);


int main(void) {
    char cells[FILS][COLS] =
        { {0,1,0,0},
          {1,1,1,1},
          {0,1,1,0},
          {1,0,0,1} };
        
    assert(nextStep(cells)==1);
    
    char expected[FILS][COLS] =
        { {1,1,0,0},
          {1,0,0,1},
          {0,0,0,0},
          {0,1,1,0} };
    for (int i=0; i < 4; i++)
        for(int j=0; j < 4; j++)
            assert(cells[i][j] == expected[i][j]);
    
    char cells2[FILS][COLS] =
        {{0,1,1,0},
         {0,1,1,0},
         {0,0,0,0},
         {0,0,0,0} };
    assert(nextStep(cells2)==0);
    
    char expected2[FILS][COLS] =
        { {0,1,1,0},
          {0,1,1,0},
          {0,0,0,0},
          {0,0,0,0} };
    
    for (int i=0; i < 4; i++)
        for(int j=0; j < 4; j++)
            assert(cells2[i][j] == expected2[i][j]);
    
    puts("OK!");

    return 0;
}
/*
El Juego de la Vida de Conway (https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)  
se desarrolla sobre un tablero rectangular, donde cada casilla puede tener una célula muerta 
(representada con un 0) o una célula viva (representada por un uno). En cada turno una célula 
puede seguir en su mismo estado, puede morir o puede revivir.
Las reglas para determinar cómo va cambiando el tablero (la matriz) son las siguientes
Si una célula está muerta  y rodeada por exactamente 3 células vivas (entre sus 8 celdas vecinas 
exactamente 3 tienen el valor 1) entonces la célula revive
Una célula viva con 2 ó 3 células vecinas vivas sigue viva, si hay menos muere por soledad, si hay 
más muere por sobrepoblación.

El juego continúa hasta que todas las células mueren o se llega a un estado estable (no hay cambios). 
Para este ejercicio se pide escribir la función nextStep que reciba una matriz de chars de FILS filas por 
COLS columnas que representa el estado actual del juego y deje en esa misma matriz el estado siguiente. 
Además la función debe retornar 1 (uno) si hubo cambios y 0 (cero) si no hubo cambios.
Se considera que por fuera de la matriz no puede haber vida
*/
int nextStep(char cells[FILS][COLS]){
    int cambio=0;
    char aux[FILS][COLS];
    for (int i=0 ; i<FILS ; i++){
        for (int j=0 ; j<COLS ;j++){
            if (cells[i][j]==0){
                if (celMuerta(cells,i,j,aux)){
                    cambio=1;
                }
            }
            else {
                if (celViva(cells,i,j,aux)){
                    cambio=1;
                }
            }
        }
    }

    for (int i=0 ; i<FILS ; i++){
        for (int j=0 ; j<COLS ;j++){
            cells[i][j]=aux[i][j];
        }
    }
    return cambio;
}

int 
celMuerta (char cells[FILS][COLS], int fil, int col, char aux[FILS][COLS]){
    int ok=checkDirections(cells, fil, col);
    if (ok==3){
        aux[fil][col]=1;
    }
    else{
        aux[fil][col]=0;
    }
    return (ok==3);
}
int 
celViva (char cells[FILS][COLS], int fil, int col,char aux[FILS][COLS]){
    int ok=checkDirections(cells, fil, col);
    if (ok!=2 && ok!=3){
        aux[fil][col]=0;
    }
    else{
        aux[fil][col]=1;
    }
    return (ok!=2 && ok!=3);
}

int 
checkDirections(char cells[FILS][COLS], int fil, int col){
    static int di[]={0,-1,-1,-1,0,1,1,1};
    static int dj[]={1,1,0,-1,-1,-1,0,1};
    int cont=0;

    for (int h=0 ; h<8 ; h++){ 
    
        int i=fil+di[h];
        int j=col+dj[h];

        if (i>=0 && i<FILS && j>=0 && j<COLS){
            if (cells[i][j]==1){
                cont++;
            }
        }
    }
    
    return cont;
}