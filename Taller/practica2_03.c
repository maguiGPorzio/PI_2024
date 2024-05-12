#include <stdio.h>
#include <math.h>
#include "getnum.h"
#define EPS 0.00001

int main() {
    double numero=getfloat("Escriba un numero decimal: ");
    int sumaDecimal=0;
    numero-=(int)numero;
    while (fabs(numero)>EPS){
        sumaDecimal+=(int)(numero*10);
        numero*=10;
        numero-=(int)numero;
    }
    printf("%d \n",sumaDecimal);
    return 0;
}
//cualquier numero que sea suma de potencias negativas de dos va a funcionar, el resto no 