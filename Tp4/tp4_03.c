#include <stdio.h>
#include "getnum.h"
#define PI 3.1415
#define VOLUMEN_ESFERA(r) ((4/3)*(PI)*(r)*(r)*(r))
	

int
main(void)
{
    int radio;
	do {
        radio=getint("Ingrese el radio entre 1 y 10 cm de la esfera: \n");
    }
    while (radio>10 || radio<1);
	
    printf("El volumen de la esfera de radio %d es %f \n",radio,VOLUMEN_ESFERA(radio));
    
    return 0;
}
	