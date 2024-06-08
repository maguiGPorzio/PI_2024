/*
Escribir la función recursiva contarGrupos que reciba como únicos parámetros un string (cadena de chars null terminated)  y un carácter. 
La función debe retornar la cantidad de grupos de caracteres consecutivos iguales al carácter pasado por parámetro. Un grupo está formado 
por uno o más caracteres iguales de manera consecutiva. 

Si el string es "abbbccaadaaaa" y el carácter es 'a', la función debe devolver 3, ya que hay 3 grupos de caracteres 'a' formados por 
1, 2 y 4 caracteres consecutivos respectivamente.

Si el string es "34abcaa33 30 0" y el carácter es '3', la función debe devolver 3, ya que hay 3 grupos de caracteres '3' formados por 
1, 2 y 1 caracteres consecutivos respectivamente.

Si el string es "abbbccaadaaaa" y el carácter es 'x', la función debe retornar cero.
*/
#include <assert.h>
#include <stdio.h>

int
contarGrupos(char * s, char c){
    if (*s == 0 || *(s+1) == 0){
        return *s == c;
    }

    if (*s != *(s+1) && *s == c){
        return 1 + contarGrupos(s+2,c);
    }

    return contarGrupos(s+1,c);
}

int 
main (){
    char * s="abbbccaadaaaa";
    assert(contarGrupos(s,'a')==3);
    s="34abcaa33 30 0";
    assert(contarGrupos(s,'3')==3);
    s="abbbccaadaaaa";
    assert(contarGrupos(s,'x')==0);
    puts ("OK");
    return 0;
}