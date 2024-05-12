#include <stdio.h>


enum compara {IGUAL=1,MAYOR,MENOR};

void 
interseccion(int vec1[],int vec2[], int vec3[]);
int
compara (int elem1, int elem2);

int
main (){
    int v1[] = {9, 9, 8, 6, 5, 5, 3, 3, -1};
    int v2[] = {10, 9, 9, 5, 3, 1, -1};
    int v1yv2[10];
    interseccion(v1, v2, v1yv2);
    for(int i = 0; v1yv2[i] != -1; i++) {
        printf("%d ", v1yv2[i]); // Imprime 9 5 3
        }
    int v3[] = {-1};
    int v4[] = {9, 8, -1};
    int v3yv4[10];
    interseccion(v3, v4, v3yv4);
    for(int i = 0; v3yv4[i] != -1; i++) { // No imprime nada
        printf("%d ", v3yv4[i]);
        return 0;
    }
}

void 
interseccion(int vec1[],int vec2[], int vec3[]){
    int i=0, j=0, h=0;
    while (vec1[i]!=-1 && vec2[j]!=-1){
        while (vec1[i]==vec1[i+1]){
            i++;
        }
        while (vec2[j]==vec2[j+1]){
            j++;
        }

        switch (compara(vec1[i],vec2[j])){
            case IGUAL:
                vec3[h++]=vec1[i++];
                j++;
                break;

            case MAYOR:
                i++;
                break;

            case MENOR:
                j++;
                break;
        }
    }
    vec3[h]=-1;
}

int
compara (int elem1, int elem2){
    if (elem1==-1){
        return MENOR;
    }
    if (elem2==-1){
        return MAYOR;
    }
    if (elem1==elem2){
        return IGUAL;
    }
    if (elem1>elem2){
        return MAYOR;
    }
    return MENOR;
}