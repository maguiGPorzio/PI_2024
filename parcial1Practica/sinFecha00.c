/*
Ejercicio 1 ( 1,5 puntos )

Escribir una macro NO_ACENTO que recibe una expresión y, si esa expresión representa 
una vocal minúscula acentuada, retorne el ASCII de la vocal sin acento. Si no es una vocal minúscula acentuada retorna el mismo valor.
No usar funciones auxiliares

Ejemplos

int c = NO_ACENTO('ó');  // c vale 'o'
c = NO_ACENTO('ó') + 1;  // c vale 'p'
c = NO_ACENTO(1 + 'ú' - 1);  // c vale 'u'
c = NO_ACENTO('r');  // c vale 'r'
c = NO_ACENTO('%');  // c vale '%'
c = NO_ACENTO(64);  // c vale '@', cuyo ASCII es 64
c = NO_ACENTO('Ú');  // c vale 'Ú', porque no es minúscula
*/

#define NO_ACENTO(expresion) 