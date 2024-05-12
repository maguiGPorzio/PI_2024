/*
Se tiene un tablero de chars con FIL filas y COL columnas. 
Un '0' representa unespacio vacío, un valor '1' representa un jugador contrario y una 'X' representaun 
obstáculo.Dada la posición de un jugador (fila,columna) deberá calcularse la dirección 
( 0(E), 45 (NE), 90 (N), 135 (NO), 180 (O), 225 (SO), 270 (S), 315 (SE)) en la quepuede moverse de tal 
forma de llegar lo más lejos posible sin encontrarse con unenemigo o un obstáculo. La función se invoca 
con el tablero, el tamaño real y laposición del jugador. Retorna la dirección posible o -1 en caso de no 
poderefectuarse ningún movimiento o de haber error en los parámetros.
*/


#include <stdio.h>
#include <assert.h>
 
#define FILAS 7
#define COLS 6
#define DIRECTIONS 8
 
#define ERROR (-1)
#define IS_IN_GRID(i,j,alto,ancho) ((i)>=0 && (i)<(alto) && (j)>=0 && (j)<(ancho))
 
int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y);
 
int
main(void) {
    char tablero[][COLS] = {
            {'0', '0', '0', '0', '1', '0'},
            {'X', 'X', '0', '0', '0', '0'},
            {'0', '0', '0', '0', 'X', 'X'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', 'X', '0', '0'},
            {'1', '0', '0', 'X', 'X', 'X'}
    };
    int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
    assert(res == 0 || res == 45);
 
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 0) == 0);
    assert(calculaDireccion(tablero, FILAS, COLS, 6, 2) == 90);
    assert(calculaDireccion(tablero, FILAS, COLS, 5, 4) == 135);
    assert(calculaDireccion(tablero, FILAS, COLS, 3, 5) == 180);
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 5) == 225);
 
    res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
    assert(res == 0 || res == 45 || res == 90 || res == 270);
 
    // Jugador fuera del tablero
    assert(calculaDireccion(tablero, FILAS, COLS, FILAS, COLS) == ERROR);
 
    printf("OK!\n");
    return 0;
}

int enum{E=0,NE,N,NO,O,SO,S,SE};

char dir[2][8]={{0,-1,-1,-1,0,1,1,1},{1,1,0,-1,-1,-1,0,1}};

int 
traverse_in_direction (int direction, char mat[][COLS], int alto, int ancho, int i, int j){
    static int di[]={0,-1,-1,-1,0,1,1,1};
    static int dj[]={1,1,0,-1,-1,-1,0,1};
    int steps=0;
    while (IS_IN_GRID(i,j,alto,ancho) && mat[i][j]==0){
        i+=di[direction];
        j+=dj[direction];
        steps++;
    }
    return steps;
}

int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y){
    if (!IS_IN_GRID(x,y,alto,ancho)){
        return ERROR;
    }

    static int angles[]={0,45,90,135,180,225,270,315};

    int max_steps=0, max_steps_direction=0;
    for (int direction=0 ; direction<DIRECTIONS ; direction++){
        int steps=traverse_in_direction(direction,mat,alto,ancho,x,y);
        if (steps>=max_steps){
            max_steps=steps;
            max_steps_direction=direction;
        }
    }

    return angles[max_steps_direction];
}


