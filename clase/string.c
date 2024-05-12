/*
Utilizando aritmética de punteros, escribir la función longString que recibe como parámetro un string 
(arreglo de chars null-terminated) y retorna la cantidad de caracteres del mismo.
*/

int
longString(const char *string){
  int cantidad=0;
  while (*string){
    cantidad++;
    string++;
  }
  return cantidad;
}

int
longString2(const char *string){
  char *from=string;
  while (*string++);
  return string-from-1;
}

