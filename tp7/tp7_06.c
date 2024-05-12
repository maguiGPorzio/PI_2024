//Mastermind
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 5

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


void
mezclar(int vec[]){
    randomize();
    int aleatorio, aux;
    for (int i=0 ; i<9 ; i++){
        aleatorio=randInt(0,8);
        aux=vec[i];
        vec[i]=vec[aleatorio];
        vec[aleatorio]=aux;
    }
}

void 
reescribirVec(int secretNumber[], int vec[], int cifras){
    for (int i=0 ; i<cifras ; i++){ 
        secretNumber[i]=vec[i];
    }
}

void
generarAleatorio (int secretNumber[], int cifras){

    int vec[9]; //como podria hacer esto en otra funcion?
    for (int i=0 ; i<9 ; i++){
        vec[i]=i+1;
    }

    mezclar(vec);

    reescribirVec(secretNumber,vec,cifras);

}

void
elegirNivel(int * N){
    do{
        puts("Ingresar el nivel que quiere jugar");
        scanf("%d",N);
    }
    while ((*N)<1);
}

int
valNum(int num,int cifras){
    int cifra, apariciones[9]={0};
    for (int i=0 ; i<cifras ; i++){
        cifra=num%10;
        if (cifra==0){
            return 0; 
        }
        if (apariciones[cifra-1]==1){
            return 0;
        }
        apariciones[cifra-1]=1;
        num/=10;
    }
    return (num==0);
}

void
leerNumero(int userNum[], int cifras){
    int num;
    do{
        printf("Introducir un numero de %d cifras entre 1 y 9 y ninguna repetida\n", cifras);
        scanf("%d",&num);
        while (getchar()!='\n');
    }
    while (!valNum(num,cifras));
    
    for (int i=cifras-1; i>=0 ; i--){
        userNum[i]=num%10;
        num/=10;
    }
}

int 
cantidadBien(int secretNumber[], int userNum[], int cifras){
    int bien=0;
    for (int i=0 ; i<cifras ;i++){
        if (userNum[i]==secretNumber[i]){
            bien++;
        }
    }
    return bien;
}

int 
cifraInSecretNum(int cifra, int secretNumber[], int cifras, int pos){
    for (int i=0 ; i<cifras ; i++){
        if (cifra==secretNumber[i] && i!=pos){
            return 1;
        }
    }
    return 0;
}

int
cantidadRegular (int secretNumber[], int userNum[], int cifras){
    int regular=0;
    for (int i=0 ; i<cifras ;i++){
        if (cifraInSecretNum(userNum[i],secretNumber,cifras,i)){
            regular++;
        }
    }
    return regular;
}

int 
coincideNumero(int secretNumber[], int userNum[], int cifras){
    int bien=cantidadBien(secretNumber,userNum,cifras);
    printf("La cantidad de cifras bien es %d\n",bien);
    printf("La cantidad de cifras regular es %d\n",cantidadRegular(secretNumber,userNum,cifras));

    return (bien==cifras);
}

int
main (){
    int secretNumber[X], N, userNum[X], ok=0;

    generarAleatorio(secretNumber,X);

    elegirNivel(&N);

    for (int i=0 ; i<N && !ok; i++){
        leerNumero(userNum,X);
        ok=coincideNumero(secretNumber,userNum,X);
    }

    if (ok){
        printf("ADIVINO!");
        printf("\n");
    }
    else{
        printf("El numero secreto era ");
        for (int j=0 ; j<X ; j++){
            printf("%d",secretNumber[j]);
        }
        printf("\n");
    }

    return 0;
}
