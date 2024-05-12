/*
Hacer una función que lea números enteros de entrada estándar (los lee con getint) y los guarde en un arreglo. 
El arreglo debe crecer a medida que se necesita. La carga en el arreglofinaliza cuando un valor se repite por 
primera vez.Tener en cuenta:
● Modularizar cuando se pueda
● Fijarse en qué puntos del código hay que reasignar memoria
*/
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#define BLOQUE 10
#define FALSE 0
#define TRUE 1
#define BORRA_BUFFER while (getchar() != '\n')

int *cargarNumeros(int *dim);
int repetido(int *arr, int dim, int num);
int getint(const char mensaje[], ... );

int main(void) {
    int dim;
    int *arr;
    arr = cargarNumeros(&dim);
    for (int i = 0; i < dim; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}


int repetido(int *arr, int dim, int num) {
    int repe = FALSE;
    for (int i = 0; i < dim && !repe; i++) {
        if (arr[i] == num)
            repe = TRUE;
    }
    return repe;
}

int *cargarNumeros(int *dim) {
    int *arr = NULL;
    int numero, counter = 0;
    int seguir = TRUE;
    do {
        if (counter % BLOQUE == 0)
            arr = realloc(arr, (counter + BLOQUE) * sizeof(int));
        numero = getint("Dame numero: ");
        if (!repetido(arr, counter, numero))
            arr[counter++] = numero;
        else
            seguir = FALSE;
    } 
    while (seguir);
    
    arr = realloc(arr, (counter) * sizeof(int));//Se pasó dim como parámetro. Debe actualizarse.
    *dim = counter;
    return arr;
}

/* lee un entero */
int 
getint(const char mensaje[], ... )
{
	int n, salir = 0;
	va_list ap;
		
	do	
	{
		va_start(ap, mensaje);
		vprintf(mensaje, ap);
		va_end(ap);

		if ( scanf("%d",&n) != 1)
		{
			printf("\nDato incorrecto\n");
			BORRA_BUFFER;
		}
		else
			salir = 1;
	} while (! salir);
	BORRA_BUFFER;
	return n;
}
