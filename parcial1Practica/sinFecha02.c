/*

Escribir la función comprime que recibe un string s, 
un carácter c y un vector de enteros v. La función debe reemplazar en el 
string s cada secuencia del carácter c por un sólo carácter c, y dejar en cada posición del 
vector cuántos caracteres de la secuencia se eliminaron. Además debe retornar la dimensión del vector v. 
Si el carácter es una letra, tiene que compactar sin distinguir entre mayúsculas y minúsculas, 
esto es, se considerará que 'A' y 'a' son el mismo carácter

Ejemplo de uso

int 
main(void) {
   int reps[100];
   char s[] = "AAA aaaabbaa a b aaaa capital federal";
   int dim;
   dim = comprime(s, 'a', reps);
   assert(strcmp(s, "A abba a b a capital federal")==0);
   assert(dim == 8);
   assert(reps[0] == 2); // se eliminan 2 de "AAA"
   assert(reps[1] == 3); // se eliminan 3 de "aaaa"
   assert(reps[2] == 1); 
   assert(reps[3] == 0); 
   assert(reps[4] == 3); 
   assert(reps[5] == 0); 
   assert(reps[6] == 0); 
   assert(reps[7] == 0); 

   dim = comprime(s, 'x', reps);
   assert(strcmp(s, "AAA abba a b a capital federal")==0);
   assert(dim == 0);

   char t[] = "AAAaaaa aAaA";
   dim = comprime(t, 'a', reps);
   assert(strcmp(s, "A a")==0);    // Se deja la primer aparición
   assert(dim == 2);
   assert(reps[0] == 6); 
   assert(reps[1] == 3); 

   return 0;
}
*/

int 
main(void) {
   int reps[100];
   char s[] = "AAA aaaabbaa a b aaaa capital federal";
   int dim;
   dim = comprime(s, 'a', reps);
   assert(strcmp(s, "A abba a b a capital federal")==0);
   assert(dim == 8);
   assert(reps[0] == 2); // se eliminan 2 de "AAA"
   assert(reps[1] == 3); // se eliminan 3 de "aaaa"
   assert(reps[2] == 1); 
   assert(reps[3] == 0); 
   assert(reps[4] == 3); 
   assert(reps[5] == 0); 
   assert(reps[6] == 0); 
   assert(reps[7] == 0); 

   dim = comprime(s, 'x', reps);
   assert(strcmp(s, "AAA abba a b a capital federal")==0);
   assert(dim == 0);

   char t[] = "AAAaaaa aAaA";
   dim = comprime(t, 'a', reps);
   assert(strcmp(s, "A a")==0);    // Se deja la primer aparición
   assert(dim == 2);
   assert(reps[0] == 6); 
   assert(reps[1] == 3); 

   return 0;
}