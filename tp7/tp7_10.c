/*
Escribir un programa interactivo para jugar al juego del ahorcado. Las palabras que almacena la
máquina deben estar guardadas en un arreglo de strings constantes y cada vez que se elija jugar, utilizar
aleatoriamente alguna de dichas palabras.
Antes de escribir el programa, realizar el diseño y la modularización, documentando cada módulo
interviniente, tal como se mostró en los ejercicios 8 y 10.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define LETRAS 26
#define CONV_LETRA(M) (M)-'a'
#define MAX_PALABRAS 50
#define OPORTUNIDADES 9

// Función para generar un número aleatorio normalizado en [0,1) 
double randNormalize(){
    return rand () / ((double) RAND_MAX+1);
}

// Función para generar un número entero aleatorio en el rango [left, right]
int randInt(int left, int right){
    return ((int)(randNormalize()*(right-left+1)) + left);
}

// Función para inicializar la semilla del generador de números aleatorios
void randomize(){
    srand ((int)time(NULL));
}

char *
elegirPalabra(char * palabras[]){
    int indice=randInt(0, MAX_PALABRAS-1);

    return palabras[indice];
}

void
preguntarLetra(int letras[], char *letraUsuario){
    do {
        printf("Ingrese una letra que no haya ingresado antes: \n");
        scanf("%1c", letraUsuario);
        while (getchar()!='\n');
        *letraUsuario=tolower(*letraUsuario);
    }
    while (*letraUsuario>'z' || *letraUsuario<'a' || letras[(unsigned char)CONV_LETRA(*letraUsuario)]!=0);
    
    letras[CONV_LETRA(*letraUsuario)]=1;
}

void
imprimirLetra(int acerto, char letra){
    printf("La letra %c esta en la a la palabra %d veces\n",letra, acerto);
}

int
letraEnPalabra(char * palabraSecreta, char letraUsuario, int letras[]){
    int acerto=0;
    for (int i=0 ; palabraSecreta[i] ; i++){
        if (letraUsuario==palabraSecreta[i]){
            letras[CONV_LETRA(letraUsuario)]=2;
            acerto+=1;
        }
    }
    imprimirLetra(acerto,letraUsuario);
    return acerto;
}

void
imprimirLongPalabra(int longPalabra){
    printf("La longitud de la palabra es %d\n",longPalabra);
}

void
imprimirOportunidades(int oportunidades){
    printf("Le quedan %d oportunidades\n", oportunidades);
}

void 
imprimirPalabra(int letras[],char * palabraSecreta){
    printf("La palabra va quedando asi: ");
    for (int i=0 ; palabraSecreta[i] ; i++){
        if (letras[CONV_LETRA(palabraSecreta[i])]==2){
            printf("%2c",palabraSecreta[i]);
        }
        else{
            printf("%2c",'-');
        }
    }
    printf("\n");
}

int
jugar(char * palabraSecreta){
    int letras[LETRAS]={0}, aciertos=0, longPalabraSecreta=strlen(palabraSecreta), oportunidades=0, acierto;
    char letraUsuario;

    imprimirLongPalabra(longPalabraSecreta);
    
    while (aciertos!=longPalabraSecreta && oportunidades<OPORTUNIDADES){
        preguntarLetra(letras,&letraUsuario);
        acierto=letraEnPalabra(palabraSecreta,letraUsuario,letras);
        aciertos+=acierto;
        if (!acierto){
            oportunidades+=1;
            imprimirOportunidades(OPORTUNIDADES-oportunidades);
        }
        imprimirPalabra(letras,palabraSecreta);
    }

    return (aciertos==longPalabraSecreta);
}

int
main (){
    randomize();

    char * palabras[MAX_PALABRAS] = {"calefon", "suerte", "amigos", "persona", "ahorcado", "hipopotamo", "avion", "legumbres", "problemas", "programacion", "biblioteca", "algoritmo", "murcielago", "tiempo", "trabajo", "computadora", "inteligencia", "pelicula", "libro", "escritorio", "naranja", "banana", "telefono", "colegio", "facultad", "estudiante", "profesor", "ciudad", "campo", "rascacielos", "caramelo", "chocolate", "reloj", "guitarra", "piano", "automovil", "bicicleta", "avestruz", "elefante", "jirafa", "leopardo", "cocodrilo", "peligroso", "asombroso", "fantastico", "maravilloso", "excepcional", "increible", "extraordinario", "sillon"};

    char * palabraElegida=elegirPalabra(palabras);

    int gano=jugar(palabraElegida);

    printf("El jugador %s gano\n", (gano) ? "si":"no");
    printf("La palabra era %s \n", palabraElegida);

    return 0;

}