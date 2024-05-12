/*
Se tiene en un vector los factores que se obtienen como resultado de la factorización de un número. 
Los factores pueden estar repetidos, y están ordenados de menor a mayor. El valor -1 indica el final del 
vector.
Por ejemplo, el factoreo de 12 es 2 * 2 * 3, entonces el vector es {2, 2, 3, -1}.
Escribir la función factoreo que reciba el vector con los factores y obtenga el número original y 
deje en el vector sólo los valores diferentes.
Nota: el vector de factores es válido, no contiene ceros ni negativos, salvo por la marca de final (-1).
CHECKED
*/
#include <stdio.h>
#include <assert.h>

long int factoreo (int vec[]);

int main(void) {
     int factores[] = {2, 2, 2, 3, 3, 4, 5, 5, 6, 6, 6, 6, 7, -1};
     long resultado = factoreo(factores);
     assert(resultado == 65318400);
     assert(factores[0] == 2);
     assert(factores[1] == 3);
     assert(factores[2] == 4);
     assert(factores[3] == 5);
     assert(factores[4] == 6);
     assert(factores[5] == 7);
     assert(factores[6] == -1);
     int factores2[] = {2, -1};
     resultado = factoreo(factores2);
     assert(resultado == 2);

     assert(factores2[0] == 2);
     assert(factores2[1] == -1);
     int factores3[] = {11, 11, 13, -1};
     resultado = factoreo(factores3);
     assert(resultado == 1573);  // 11 * 11 * 13
     assert(factores3[0] == 11);
     assert(factores3[1] == 13);
     assert(factores3[2] == -1);
     int factores4[] = {-1};
     resultado = factoreo(factores4);
     assert(resultado == 0);
     assert(factores4[0] == -1);
     int factores5[] = {1, -1};
     resultado = factoreo(factores5);
     assert(resultado == 1);
     assert(factores5[0] == 1);
     assert(factores5[1] == -1);
     puts("OK!");
     return 0;
}

long int 
factoreo (int vec[]){
    if (vec[0]!=-1){
        int i, j=1, num=vec[0];
        for (i=1 ; vec[i]>0 ; i++){
            num*=vec[i];
            if (vec[i]!=vec[i-1]){
                vec[j++]=vec[i];
            }
        }
        vec[j]=-1;
        return num;
    }
    return 0;
}