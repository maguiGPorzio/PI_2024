//algoritmo de euclides

#include <stdio.h>
#include "getnum.h"

int 
mcd (int a, int b)
{
    if (a<0) {
        a*=-1;
    }
    if (b<0) {
        b*=-1;
    }

    int auxi=a%b;

	while (auxi>0)
	{	
		a = b;
        b = auxi;
        auxi = a % b ;
    }
	return b;
}

int 
main () {
    int a=getint("Ingrese a: "), b=getint("Ingrese b: ");
    printf("El mcd entre %d y %d es %d \n",a,b,mcd(a,b));

}
