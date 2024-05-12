/*
Ejercicio 2 

Escribir una función palEnMat que reciba:
una matriz cuadrada de chars de dimensión N (con N constante simbólica previamente definida)
un entero que indica una fila
un entero que indica una columna 
un string
y retorne 1 si el string se encuentra dentro de la matriz, ya sea en sentido horizontal, 
vertical o diagonal y en cualquier dirección, donde el primer carácter del string se encuentra en la fila 
y columna indicada.
*/
#include <stdio.h>
#define N 6
#define DIRECTIONS 8

int palEnMat(char m[][N], int posX, int posY, char *s);
int palabraEnDirecc(int direction, char mat[][N], int i, int j, char *s);

int
main(void){
    char m[N][N] = {
        {'L', 'O', 'B', 'R', 'A', 'Z'},
        {'F', 'j', 'R', 'G', 'O', 'R'},
        {'C', 'O', 'S', 'A', 'D', 'A'},
        {'R', 'P', 'A', 'H', 'N', 'N'},
        {'W', 'A', 'O', 'Y', 'U', 'T'},
        {'Q', 'S', 'G', 'S', 'M', 'A'}
    };
    char s[] = "SAPO";
    printf("%d\n", palEnMat(m, 5, 1, s));
    return 0;
}

int 
palEnMat(char mat[][N], int posX, int posY,char * s){
    int presencia=0;
    for (int direction=0 ; direction<DIRECTIONS && !presencia; direction++){
        presencia=palabraEnDirecc(direction,mat,posX,posY,s);
    }
    return presencia;
}

int 
palabraEnDirecc(int direction, char mat[][N], int i, int j,char *s){
    static int di[]={0,-1,-1,-1,0,1,1,1};
    static int dj[]={1,1,0,-1,-1,-1,0,1};
    int h=0;
    while (s[h]){
        if (mat[i][j]!=s[h]){
            return 0;
        }
        i+=di[direction];
        j+=dj[direction];
        h++;
    }
    return 1;
}




