#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef unsigned int uInt ;


/* Recibe un string con el formato dd/mm/yyyy y retorna por parámetro el día, mes
** y año de la misma. En caso de que el formato sea inválido
** o la fecha incorrecta, retorna FALSE y no altera los parámetros
*/
int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio);
static int bisiesto(int anio);
int validarFormato (const char * fecha);
int extraerFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio);


int main(void) {
  unsigned int d=100, m=200, a=300;
  int res;
  res = valorFecha("", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("29/02/1999", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("30/14/2020", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("12/12/", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("1/1/2000", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("12/01/2000", &d, &m, &a);
  assert(res==1);
  assert(d==12);
  assert(m==1);
  assert(a==2000);

  res = valorFecha("29/02/1900", &d, &m, &a);
  assert(res==0);
  assert(d==12);
  assert(m==1);
  assert(a==2000);

  res = valorFecha("29/02/2000", &d, &m, &a);
  assert(res==1);
  assert(d==29);
  assert(m==2);
  assert(a==2000);

  printf("OK");
  return 0;
}

/*
Escribir una función que reciba un string con el formato 'dd/mm/yyyy' que representa una fecha y 
devuelva en tres parámetros de salida el número de día, el número del mes y el año. En caso de que la 
fecha no sea correcta retorna el valor cero y no altera los parámetros recibidos, caso contrario retorna 1. 
(Ninguna función debe superar las 8 líneas).
*/

int 
validarFormato (const char * fecha){
  int ok=(fecha[2] == '/' && fecha[5] == '/' && strlen(fecha)==10 );
  if (ok){ 
		for (int i = 0 ; fecha[i] && ok; i++){ 
			if (i!= 2 && i!=5 && !isdigit(fecha[i])){ 
				ok= 0;
      }
    }
  }
	return ok;
}

static int
bisiesto(int anio) {
    int esb=0;
    if((anio%4 == 0 && anio%100!= 0) || anio%400 == 0)
        esb=1;
    return esb;
}

int 
extraerFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio){
  static int diasMes[2][12] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                              { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};
  int fechaOK=0;

	*dia = atoi(fecha);
	*mes = atoi(fecha + 3);
	*anio = atoi(fecha + 6);

	if ( *dia > 0 && *mes >= 1 && *mes <= 12)
		fechaOK = *dia <= diasMes[bisiesto(*anio)][*mes-1] ;

	return fechaOK;

}

int
valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio) {
	int fechaOK;
	uInt lDia, lMes, lAnio;

  fechaOK = validarFormato(fecha) && extraerFecha(fecha,&lDia,&lMes,&lAnio);
	
  /* Si la fecha es valida, actualizar los parametros de salida. Caso contrario
  ** quedan con los valores al momento de la invocación
  */
	if ( fechaOK) {
		*dia  = lDia;
		*mes  = lMes;
		*anio = lAnio;
	}

	return fechaOK;	
}
