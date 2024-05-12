#include <stdio.h>
#define isdigit(c) (((c)<='9' && (c)>='0'))
	

int
main(void)
{
    int letra;
	letra = getchar();
	if ( isdigit(letra) )
		printf("Es un dígito\n");
}