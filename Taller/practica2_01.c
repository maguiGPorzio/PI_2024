#include <stdio.h>
#include <math.h>
#include "getnum.h"

int main() {
    double a,b,c,disc,x1,x2; 
    a=getdouble("Ingrese el coficiente a:");
    b=getdouble("Ingrese el coficiente b:");
    c=getdouble("Ingrese el coficiente c:");
    if (a==0){
        printf("No es cuadratica\n");
    }
    else { 
        disc=b*b-4*a*c;
        if (disc<0){
          printf("Las raíces son complejas\n");  
        }
        else {
            x1 = (-b-sqrt(disc))/(2*a);
            x2 = (-b+sqrt(disc))/(2*a);
            printf("Las raíces son %f y %f.", x1, x2);
        }
    }
    return 0;
    }
