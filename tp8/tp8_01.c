#include <stdio.h>
#include <string.h>


typedef struct {
   int code;
   char *description;
} itemType;

itemType newItem(int code, char *description) {
   itemType aux;
   aux.code = code;
   aux.description = malloc(strlen(description) + 1);
   strcpy(aux.description, description);
   return aux;
}

int main(void) {
   itemType art;
   art = newItem(2, "Zapatilla");
   printf("%d - %s \n", art.code, art.description);
   free(art.description);
   return 0;
}