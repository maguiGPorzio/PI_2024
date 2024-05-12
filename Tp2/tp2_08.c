#include <stdio.h>
#include "getnum.h"


int main() {
    float velocidad=getfloat("Ingrese una velocidad en m/s:");
    printf("La velocidad en km sobre horas es %f \n",(velocidad*3600)/1000);
    return 0;
}