/*
Una imagen en formato BMP a color de n x m píxeles se representa como una matriz de númerosenteros entre 0 y 255.
Cada píxel se representa por 3 números (RGB). El primero representa latonalidad de rojo, el segundo la 
tonalidad de verde y el tercero la tonalidad de azul.
Al usar una impresora láser monocromática (B&N), se convierte el color RGB a un tono degris ponderando un 0.2989 
de rojo, el 0.5870 del verde y 0.1140 del azul, que es el efecto de cada coloren el brillo de la imagen.
Entonces, el pixel RGB [100,200,100] se convierte al pixel Gris 158 pues 
100 * 0.2989 + 200 *0.5870 + 100 * 0.1140 = 158.69Escribir una función rgbToGray que 
reciba una imagen BMP a color de NxM pixeles (N y M son constantessimbólicas) y una matriz donde debe 
dejar la imagen equivalente en escala de grises.
*/

#define R 0.2989
#define G 0.5870
#define B 0.1140
 
#define N 3
#define M 5
#define RGB_M (3 * M)
 
#include <stdio.h>
#include <assert.h>

 
void rgbToGray(const unsigned char (rgb[])[RGB_M], unsigned char grayscale[][M]);
unsigned char grey (const unsigned char vec[]);
 
// Solo para testing
static void 
assertMatrixEquals(const unsigned char (expected[])[M], const unsigned char (actual[])[M], size_t fils, size_t cols);
 
int
main(void) {
    unsigned char rgbMatrix[][RGB_M] = {
            {100,200,100,100,180,100,200,100,120,110,123,122,100,120,122},
            {101,200,105,99,200,100,201,102,118,110,120,120,100,121,122},
            {100,200,100,100,210,105,200,100,100,120,120,100,100,122,121}
    };
    unsigned char grayscaleMatrix[N][M];
    rgbToGray(rgbMatrix, grayscaleMatrix);
    unsigned char expectedGrayscaleMatrix[][M] = {
            {158,146,132,118,114},
            {159,158,133,116,114},
            {158,165,129,117,115}
    };
    assertMatrixEquals(expectedGrayscaleMatrix, grayscaleMatrix, N, M);
 
    puts("OK!\n");
    return 0;
}
 
/**
 * Tester
 */
static void
assertMatrixEquals(const unsigned char (expected[])[M], const unsigned char (actual[])[M], size_t fils, size_t cols) {
    for (int i = 0; i < fils; i++) {
        for (int j = 0; j < cols; j++) {
            assert(expected[i][j] == actual[i][j]);
        }
    }
}


void 
rgbToGray(const unsigned char (rgb[])[RGB_M], unsigned char grayscale[][M]){
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<M ; j++){
            grayscale[i][j]=grey(rgb[i]+j*3);
        }
    }
}

unsigned char
grey (const unsigned char vec[]){
    int h=0;
    double sum=0;
    sum+=vec[h++]*R;
    sum+=vec[h++]*G;
    sum+=vec[h]*B;
    return (unsigned char)sum;
}

