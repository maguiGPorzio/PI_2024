/*
Ejercicio: escribir una función que reciba un vector de enteros y un número y devuelva si 
el número aparece en el vector. Implementarla usando notación de vectores y notación de punteros.
*/

int 
belongsVec (const int v[], int n, unsigned dim){
    int esta=0;
    for (int i=0 ; i<dim && !esta; i++){
        if (v[i]==n){
            esta=!esta;
        }
    }
    return esta;
}

int 
belongsVec2 (const int v[], int n, unsigned dim){
    int esta=0;
    for (int i=0 ; i<dim && !esta; i++){
        esta=v[i]==n;
    }
    return esta;
}

int 
belongsPunt (const int v[], int n, unsigned dim){
    int esta=0, *tope=v+dim;
    while (v<tope && !esta){
        esta=(*(v++)==n);
    }
    return esta;
}