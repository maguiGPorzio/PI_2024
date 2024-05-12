#include <stdio.h>

#define MAXIMO 20
#define V_FINAL -1
enum { IGUAL, MENOR, MAYOR};

void unirArreglos ( const int arreglo1[], const int arreglo2[], int resultado[]);

/* La misma función de comparación del ejercicio anterior */
int compara ( int clave1, int clave2);

void
unirArreglos ( const int arreglo1[], const int arreglo2[], int resultado[]) {
	int i = 0, j = 0; 	    /* índices del primer y segundo arreglo */
	int k = 0;			    /* índice de la unión ( arreglo resultado ) */

	while (( arreglo1[i] != V_FINAL || arreglo2[j] != V_FINAL ) && k < MAXIMO -1) {
		/* Saltear elementos repetidos en arreglo1 */
		if ( arreglo1[i] != V_FINAL )
			while ( arreglo1[i]==arreglo1[i+1] )
				i++;
		
		/* Saltear elementos repetidos en arreglo2 */
		if ( arreglo2[j] != V_FINAL )
			while ( arreglo2[j] == arreglo2[j+1] )
				j++;
		
		switch ( compara(arreglo1[i], arreglo2[j] )) {
		case IGUAL: 
			resultado[k] = arreglo1[i++];
			j++;
			break;
		case MENOR:
			resultado[k] = arreglo1[i++];
			break;
		case MAYOR:
			resultado[k] = arreglo2[j++];
		}
		k++;
	}
	
	resultado[k] = V_FINAL;
}