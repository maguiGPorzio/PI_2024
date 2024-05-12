#define MAXIMO 20
#define V_FINAL -1

enum { IGUAL, MENOR, MAYOR };

void unirArreglos ( const int ar1[], const int ar2[], int resultado[]);

/* Dados dos elementos, devuelve si el primero es menor, igual o mayor al 
** segundo, considerando que V_FINAL indica fin de datos, y por lo tanto es el "máximo" 
*/
int compara ( int clave1, int clave2);

void
unirArreglos ( const int ar1[], const int ar2[], int resultado[]) {
	int i = 0, j = 0;	/* índices del primer y segundo arreglo */
	int k = 0;  		/* índice de la unión ( arreglo resultado ) */
	
	// Otra posibilidad seria realizar la copia del V_FINAL dentro del ciclo
	// (cuando ambos vectores llegaron al final), y usar un do while, o sea
	// do {
	//    Si ambos son iguales (incluido el V_FINAL) , copio
	//    Si no, copiar el que corresponda
	// } while (resultado[k] != V_FINAL);

	while (( ar1[i] != V_FINAL || ar2[j] != V_FINAL ) && k < MAXIMO -1) {
		switch ( compara(ar1[i], ar2[j] )) {
		case IGUAL: 
			resultado[k] = ar1[i++];
			j++;
			break;
		case MENOR:
			resultado[k] = ar1[i++];
			break;
		case MAYOR:
			resultado[k] = ar2[j++];
		}
		k++;
	}
	resultado[k] = V_FINAL;
}

int
compara ( int clave1, int clave2) {
	if ( clave1 == clave2 )
		return IGUAL;
	if ( clave1 == V_FINAL )
		return MAYOR;
	if ( clave2 == V_FINAL )
		return MENOR;
	if ( clave1 > clave2 )
		return MAYOR ;
	return MENOR;
}