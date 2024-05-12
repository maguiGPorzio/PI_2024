/*
Hacer un programa que genere aleatoriamente el movimiento de una partícula en el
plano 2D y registre en un arreglo cada una de las posiciones que fue tomando hasta volver
al origen de coordenadas.
Ejemplo: Siempre comienza su movimiento saliendo de la posición (0,0). Luego, puede
aleatoriamente moverse a (-2,3) (si dx=-2 y dy=3). Luego, a (-3,-2) (con dx=-1 y dy=-5) y por
último a (0,0) (con dx=3 y dy=2).

¿Cómo se define el arreglo para guardar las posiciones (tPosiciones)?
*/

#include <stdio.h>
#define BLOQUE 10
#define RANGO 2

typedef struct {
    int x;
    int y;
} tPunto2D;

typedef tPunto2D *tPosiciones;


int
main(void) {
    randomize();
    tPunto2D actual = {0, 0};
    tPosiciones puntos = NULL;
    int dim = 0;
    do {
        if (dim % BLOQUE == 0) {
            puntos = realloc(puntos, (dim + BLOQUE) * sizeof(tPunto2D));
        }
        puntos[dim++] = actual;
        int dx = randInt(-RANGO, RANGO);
        int dy = randInt(-RANGO, RANGO);
        actual.x += dx;
        actual.y += dy;
    } while (actual.x != 0 || actual.y != 0);

    for (int i = 0; i < dim; i++) {
        printf("{%d,%d} ", puntos[i].x, puntos[i].y);
    }
    free(puntos);
    return 0;
}