#define DIM 50

int 
readArray(float v[]){
   int i=0, int n;
   while (i<dim && (n=getfloat("Ingrese un numero real positivo: "))>0){
      vec[i++]=n;
   }
   return i;
}

int main(void) {
   float v[DIM];

   /* invocamos a la función readArray */

   int n=readArray(v);
   printArray(v,n);

   /* Imprimimos los elementos de v */

   return 0;
}
