#include <stdio.h>
#include <ctype.h>
#define TOPE	5

void 
encripta( char letra )
{
   /* Esta tabla indica el ASCII a devolver para cada letra mayuscula  */
   static char transforma[26] =  { '#', '!', '?', '&', '.', '/', '{', ']', 
			'(', '=', '[', '}', ')', 'c', 'e', 'w', 'j', 'x', 'a', 
			'i', 'm', 'o', 'y', 'h', '\\', '<'  };
   letra = toupper(letra);
   if ( isalpha(letra) )
      letra= transforma[letra - 'A' ];
   putchar(letra);
}

int
main( void )
{
   char mensaje[TOPE];
   int dimension = 0;
   int leido, rec;

   while ( dimension < TOPE && ( leido = getchar() ) != EOF )
      mensaje[dimension++]= leido;

   /* ... */

   for ( rec=0 ; rec<dimension ; rec++) //hasta dimension porque yo nose cuanto va a querer que mida la matriz el usuario 
      encripta( mensaje[ rec ] ); //la funcion encripta le manda una copia (no es que se odifica lo que hay en mensaje[])

   /* etc */
   
   return 0;
}
