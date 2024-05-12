/*
Dados dos conjuntos A y B, su diferencia simétrica, A Δ B, es un conjunto que contiene los elementos de A y los de B, 
excepto los que son comunes a ambos:

Se define: A Δ B = {x/x ∈ (A ∪ B) ∧ x ∉ (A ∩ B)}

Ejemplo: Sean A = {1, 2, 3, 4} y B = {3, 4, 5, 6, 7} entonces 
A Δ B = {1, 2, 5, 6, 7}

Para este ejercicio se debe asumir que los conjuntos contienen únicamente números positivos sin repetir y ordenados 
ascendentemente, con el valor -1 como marca de final.
Como trabajaremos con varios conjuntos, los mismos se almacenan en una "matriz".

Se pide: escribir la función difSim que reciba:
tres matrices enteras m1, m2 y m3 de COLS columnas (COLS es una constante simbólica previamente definida). Cada fila i de m1 y 
m2 contendrá un conjunto de enteros mayor o igual a cero, ordenados ascendentemente y sin repetir, con el valor -1 como marca de 
final
un valor entero filas que representa la cantidad de conjuntos en cada matriz

La función deberá dejar en cada fila i de m3 la diferencia simétrica entre las filas i de m1 y de m2, con i ∈ [0, filas)
*/

#include <stdio.h>
#define COLS 5

enum condicion{IGUAL=1,MAYOR,MENOR};

void difSim (int m1[][COLS], int m2[][COLS],int m3[][COLS],int fila);
void difSimFil(const int vec1[],const int vec2[], int vec3[]);
int compara(int elem1, int elem2);


int 
main (){
    int v1[][COLS]={{1,2,3,4,-1},{3,4,5,-1,0},{10,15,20,-1,0},{-1,0,0,0,0},{-1,0,0,0,0,},{5,6,7,-1,0}};
    int v2[][COLS]={{3,4,5,6,-1},{3,4,5,-1,0},{10,20,-1,0,0},{1,2,3,4,-1},{-1,0,0,0,0},{1,2,7,-1,0}};
    int v3[6][COLS];
    difSim(v1,v2,v3,6);
    for (int i=0 ; i<6 ; i++){
        for (int j=0 ; j<COLS ; j++){
            printf("%4d",v3[i][j]);
        }
        printf("\n");
    }
    return 0;
}


void 
difSim (int m1[][COLS], int m2[][COLS],int m3[][COLS], int fila){
    for (int i=0 ; i<fila ; i++){
        difSimFil(m1[i],m2[i],m3[i]);
    }
}

void
difSimFil(const int vec1[],const int vec2[], int vec3[]){
    int h=0,i=0,j=0;
    while (vec1[i]>-1 || vec2[j]>-1){
        switch (compara(vec1[i],vec2[j])){
            case IGUAL:
                i++;
                j++;
                break;

            case MAYOR:
                vec3[h++]=vec2[j++];
                break;

            case MENOR:
                vec3[h++]=vec1[i++];
                break;
        }
    }
    vec3[h]=-1;
}

int 
compara(int elem1, int elem2){
    if (elem1==-1){
        return MAYOR;
    }
    if (elem2==-1){
        return MENOR;
    }
    if (elem1==elem2){
        return IGUAL;
    }
    if (elem1<elem2){
        return MENOR;
    }
    return MAYOR;
}
