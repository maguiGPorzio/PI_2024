#include <stdio.h>
#include <math.h>

#define EPSILON 0.0000001

int 
main(void)
{
    float a = 0.1;
	printf("%f\n",a);

    float resta = a - 0.1;
    if (fabs(resta) < EPSILON)
        printf("SON iguales\n");
    else
        printf("NO SON iguales: a vale %.25f que no es igual a 0.1\n",a);

    return 0;
}
