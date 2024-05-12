#include <stdio.h>


int
main(void)
{
 	int i, j, max;
 	i = j = 2;
 	max = (i>j? i : j );
    printf("El max entre i y j es: %d\n", max);
	return 0;
}
