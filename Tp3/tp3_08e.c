#include <stdio.h>
#include "getnum.h"

// El enunciado de este ejercicio también podría ser:
// "Reemplazar la condicion del ciclo para que funcione en un lenguaje no lazy"

int main(void) {
   int lim = getint("Ingrese cota:"), c;


   // Opción 1: reemplazando los && por condicionales anidados
   for(int i=0; (i<lim-1) ? ((c=getchar()) != '\n') ? c != EOF : 0 : 0; ++i) {
      putchar(c);
   }
  
 
   // Opción 2: usando break para cortar el ciclo
   for(int i=0; i<lim-1 ; ++i) {
      if ( (c=getchar())=='\n') {
         break;
      }
      if ( c == EOF) {
         break;
      }
      putchar(c);
   }
   
   return 0;
}