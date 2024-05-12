#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Renombramos las funciones para poder usar el resto de string.h */
char * my_strncpy(char *target, const char *source, unsigned int n);
char * my_strncat(char *target, const char *source, unsigned int n);
int my_strncmp(char *s, char *t, unsigned int n);


int main(void) {
  char s[100];
  for(int i=0;i<100;i++)
    s[i]='x';
  assert(my_strncpy(s,"prueba copiar",100)==s);
  assert(strcmp(s,"prueba copiar")==0);
  for(int i=strlen(s); i < 100;i++)
    assert(s[i]=='\0');

  my_strncpy(s,"",100);
  for(int i=0; i < 100;i++)
    assert(s[i]=='\0');

  my_strncpy(s,"123456",4);
  assert(strcmp(s,"1234")==0);
  
  my_strncpy(s,"777777777",2);
  assert(strcmp(s,"7734")==0);

  assert(my_strncat(s, " end",10)==s);
  assert(strcmp(s,"7734 end")==0);

  assert(my_strncat(s, "abcde",2)==s);
  assert(strcmp(s,"7734 endab")==0);

  assert(my_strncmp(s,"7734 endab",10)==0);
  assert(my_strncmp(s,"7734 endab",12)==0);
  assert(my_strncmp(s,"7734",4)==0);
  assert(my_strncmp(s,"7735",4)<0);
  assert(my_strncmp(s,"7732",4)>0);
  assert(my_strncmp(s,"7734",0)==0);
  assert(my_strncmp(s,"",4)>0);
  assert(my_strncmp(s,"",0)==0);
  
  printf("OK\n");
  return 0;
}


char * 
my_strncpy(char * target, const char * source, unsigned int n){
  int i;
  for (i=0 ; i<n && source[i]; i++){
    target[i]=source[i];
  }
  while (i<n){
    target[i++]=0;
  }
  return target;
}

char * my_strncat(char *target, const char *source, unsigned int n){
  int i;
  for (i=0 ; target[i] ; i++);

  for (int j=0; source[j] && j<n ;j++){
    target[i++]=source[j];
  }
  target[i]=0;
  return target;
}

int my_strncmp(char *s, char *t, unsigned int n){
  int i;
  for (i=0 ; s[i] && t[i] && i<n; i++){
    if (s[i]<t[i]){
      return s[i]-t[i];
    }
    if (s[i]>t[i]){
      return s[i]-t[i];
    }
  }
  if (i==n)
    return 0;

  return s[i]-t[i];
}


/* 
Copia n caracteres desde el string t hacia s 
** Esta funcion no es similar a strcpy, ya que si
** t tiene mas de n caracteres, no copia el cero final
** y si tiene menos rellena con ceros.
char * my_strncpy(char *target, const char *source, unsigned int n)
{
    char * p = target;
    while (*source && n > 0){
        *target++ = *source++;
        n--;
    }
    while (n-- > 0)
        *target++ = 0;
    return p;
}
*/
/* Concatena n caracteres desde el string t al final del string s */
/*
char * my_strncat(char *target, const char *source, unsigned int n)
{   
    // No podemos hacer lo siguiente, ya que strncat no rellena con ceros y siempre
    // deja el string s null-terminated
    // strncpy(target + strlen(target), source, n);
    char* p = target + strlen(target);

	// Agregamos al final
	while (*source != '\0' && n--)
		*p++ = *source++;

	// El cero final
	*p = '\0';

	return target;
}


// Compara en base a valor ASCII los primeros n caracteres de dos strings
// Devuelve :
//< 0 si s < t		 0   si s==t	 		> 0 si s > t 
int my_strncmp(char *s, char *t, unsigned int n)
{
    for (; n && *s == *t && *s; s++, t++, n--);
    if (n == 0 )
       return 0;
    
    return *s - *t;
}
*/