#include <assert.h>
#include <stdio.h>
#include <string.h>

// Le cambiamos el nombre para que no haya conflictos con la biblioteca estandar
char * strCat ( char *s, const char *t);

int main(void){

    char ga[10]="ga";
    char to[]="to";
    char empty[10]="";

    assert(!strcmp("", strCat(empty, empty)));
    assert(!strcmp("gato", strCat(ga, to)));
    assert(!strcmp("gato", strCat(ga, empty)));
    assert(!strcmp("gatoto", strCat(ga, to)));
    assert(!strcmp("gatoto", strCat(empty, ga)));

    puts("OK!");
    return 0;
}

// Pensar por que no puede reemplazarse el ciclo 	
//          while ( *s ) s++;   
//  por   
//          while (*s++);

char * 
strCat ( char *s, const char *t)
{
	char *aux =s;
    while ( *s )
		s++;
	while (*s++ = *t++) ; 
    
    return aux;
}