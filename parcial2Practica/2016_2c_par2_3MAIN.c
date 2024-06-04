#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "/home/mgonzalezporzio/PI/parcial2Practica/2016_2c_par2_3.h"


int 
main (){
    hangmanADT h = newHangman(3);	// Los níveles válidos serán 1, 2 y 3
    size(h, 1); // -> Retorna 0
    size(h, 4); // -> Retorna -1

    char * firstWords[] = {"ingenieria", "informatica", NULL};
    addWords(h, firstWords, 1); // -> Retorna 2
    size(h, 1); // -> Retorna 2
    word(h, 1); // -> Retorna “ingenieria” o “informatica”
    words(h, 1); // -> Retorna {“ingenieria”, “informatica”, NULL}
                // También podría retornar {“informatica”, “ingenieria”,  NULL}

    addWords(h, firstWords, 1); // -> Retorna 0

    addWords(h, firstWords, 5); // -> Retorna -1
    size(h, 5); // -> Retorna -1
    word(h, 5); // -> Retorna NULL
    words(h, 5); // -> Retorna NULL;
    words(h, 2); // -> Retorna {NULL}

    char * secondWords[] = {"programacion", NULL};
    addWords(h, secondWords, 3); // -> Retorna 1
    size(h, 3); // -> Retorna 1
    word(h, 3); // -> Retorna “programacion”
    words(h, 3); // -> Retorna {“programacion”, NULL}

    // Ejemplo que muestra cómo se copian las palabras en el TAD
    char v[20] = "cazador";
    char * thirdWords[] = { v, NULL};
    addWords(h, thirdWords, 2); // -> Retorna 1

    printf("%s\n", word(h, 2)); // -> Imprime “cazador”

    strcpy(v, "venado");  // En la dirección v ahora hay otro string

    printf("%s\n", word(h, 2)); // -> Imprime “venado”

    char * lastWords[] = { "cazador", "colador", NULL};
    addWords(h, lastWords, 2); // -> Retorna 2 
    puts("OK");

    return 0;
}