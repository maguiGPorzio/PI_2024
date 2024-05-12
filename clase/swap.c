void
swap( int *num1, int *num2) {
   int aux;

   aux = *num1;
   *num1 = *num2;
   *num2 = aux;
}

int
main(void){
   int value1 = 2, value2 = 4;

   swap(&value1, &value2);
   return 0;
}
