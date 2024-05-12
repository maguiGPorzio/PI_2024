/*Dada una matriz de chars de COLS columnas -donde COLS es una constante
previamente definida-, verificar las filas que representan un palíndromo (capicúa). En
cada celda puede haber letras, dígitos, símbolos, etc. Se debe considerar que las letras
minúsculas no son equivalentes a las letras mayúsculas, por lo que "ala" es palíndromo
pero "Ala" no lo es.
Escribir una función elimina que reciba la matriz y la cantidad de filas de la misma, y
elimine de la matriz las filas que sean capicúas. La función debe retornar cuántas filas
quedaron en la matriz.
*/

#define COLS 5
#include <stdio.h>


int palindromo ( char m[][COLS] , int fila);
int filCap (char matFil[]);
void copyFil (char m[][COLS], char fil[], int pos);


int main() {
    char matriz[][COLS] = {{'a', 'n', 'a','n','a'},    // es palíndromo
        {'c', 'i', 'v', 'i', 'c'},  // es palíndromo
        {'h', 'e', 'l', 'l', 'o'},
        {'l', 'e', 'v', 'e', 'l'}   // es palíndromo
    };

    printf("Matriz original:\n");
    for (int i = 0; i < 4; i++) {
        for( int j = 0; j < COLS; j++)
        {
            printf("%c,", matriz[i][j]);
        }
    }

    int filas_quedan = palindromo(matriz,4);
    puts("");


    printf("\nMatriz después de eliminar palíndromos:\n");
    for (int i = 0; i < filas_quedan; i++) 
    {
         for( int j = 0; j < COLS; j++)
    {
        printf("%c,", matriz[i][j]);
    }
    }

    printf("\nQuedaron %d filas en la matriz después de eliminar los palíndromos.\n", filas_quedan);

    return 0;
}

int 
palindromo (char m[][COLS] , int fila){
    int h=0, esCapicua;
    for (int i=0 ; i<fila ; i++){
        esCapicua=filCap(m[i]);
        if (!esCapicua && h!=i){
            copyFil(m,m[i],h);
            h++;
        }
        else if (!esCapicua && h==i){
            h++;
        }
    }
    return h;
}

int
filCap (char matFil[]){
    int i=0, j=COLS-1;
    while (i<j){
        if (matFil[i]!=matFil[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void 
copyFil (char m[][COLS], char fil[], int pos){
    for (int i=0 ; i<COLS ; i++){
        m[pos][i]=fil[i];
    }
}