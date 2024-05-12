#include <stdio.h>
#define ENT_HORA 18
#define ENT_MINUTOS 30

int 
llegaTemprano (const int hora, const int minutos)
{
	if (hora < ENT_HORA){
		return 1;
	}
	else if (hora==ENT_HORA){
		if (minutos<=ENT_MINUTOS){
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int llegaTemprano (const int hora, const int minutos);
	
int
main(void)
{
	int hora=18, minutos=20;
	printf("El empleado %s llego a tiempo \n",((llegaTemprano (hora,minutos)) ? "si":"no" ));
}