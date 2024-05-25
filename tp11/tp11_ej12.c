#include <stdio.h>
#include "/home/mgonzalezporzio/PI/tp11/tp11_ej12.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct allegado{
    char * nombre;
    struct allegado * proxAl;
} allegado;

typedef allegado * allegados;

typedef struct persona{
    char * nombre;
    allegados alleg; //alleg es la direccion de memoria de el primer allegado correspondiente a ese nombre
    size_t cantAll;
    struct persona * proxPers;
}persona;

typedef persona * personas; 

struct socialCDT{
    personas per; //per es la direccion de memoria a la info del primer nombre 
    size_t cantPer;
};

char * strncpyAux(char * t, const char * s, unsigned int n) {
    // Siempre se copian n caracteres, ya sean de s o 0 para rellenar
    int i;
    for(i=0; i<n-1; i++) {
        if (*s) {
            t[i] = *s++;
        } else {
            t[i] = 0;
        }
    }
    t[i]=0;
    return t;
}

/* Crea un nuevo TAD vacío */
socialADT newSocial(){
    socialADT aux=calloc(1,sizeof(struct socialCDT));
    return aux;
}

static void
freeAlleg(allegados all){
    if (all == NULL){
        return;
    }
    
    allegados aux=all->proxAl;
    free(all->nombre);
    free(all);
    freeAlleg(aux);
}

static void
freePer (personas per){
    if (per==NULL){
        return;
    }

    personas aux=per->proxPers;
    freeAlleg(per->alleg);
    free(per->nombre);
    free(per);
    freePer(aux);
    
}
 
/* Libera todos los recursos reservados por el TAD */
void freeSocial(socialADT soc){
    freePer(soc->per);
    free(soc);
}

static personas
addPersonRec(personas per, const char * name, int * noRepetida){
    if (per==NULL || strcmp(per->nombre, name) > 0 ){
        *noRepetida=1;
        personas nuevaPersona=calloc(1, sizeof(persona));
        nuevaPersona->nombre=malloc(21*sizeof(nuevaPersona->nombre[0]));
        strncpyAux(nuevaPersona->nombre, name, 21);
        nuevaPersona->proxPers=per;
        return nuevaPersona;
    }

    if (!strcmp(per->nombre, name)){
        return per;
    }

    per->proxPers=addPersonRec(per->proxPers,name,noRepetida);
    return per;
}

/* Almacena una nueva persona. Si la persona existe, no hace nada
** Guarda una copia del nombre, no simplemente el puntero
*/
void addPerson(socialADT soc, const char * name){
    int noRepetida=0;
    soc->per=addPersonRec(soc->per, name, &noRepetida);
    soc->cantPer+=noRepetida;
}

static allegados
addRelatedRec(allegados all, const char * related){
    if (all==NULL || !strcmp(all->nombre, related) || strcmp(all->nombre, related) > 0 ){
        allegados nuevoAll=calloc(1, sizeof(allegado));
        nuevoAll->nombre=malloc(21*sizeof(nuevoAll->nombre[0]));
        strncpyAux(nuevoAll->nombre, related, 21); 
        nuevoAll->proxAl=all;
        return nuevoAll;
    }

    all->proxAl=addRelatedRec(all->proxAl,related);
    return all;
}

/* Si existe una persona con ese nombre, agrega la nueva relación
** Si la persona no existe, no hace nada
** Si related ya estaba relacionado, lo agrega repetido
** Almacena una copia de related, no simplemente el puntero
**
 */
void addRelated(socialADT soc, const char * name, const char * related){
    personas aux=soc->per;
    while (aux != NULL){
        if (!(strcmp(aux->nombre,name))){
            aux->alleg=addRelatedRec(aux->alleg,related);
            aux->cantAll+=1;
            return;
        }
        aux=aux->proxPers;
    }
}

char ** 
relatedAux(personas per){
    char ** nombresRelac=malloc((per->cantAll+1) * sizeof(nombresRelac[0]));
    allegados aux=per->alleg;
    int i=0;

    while (aux != NULL){
        nombresRelac[i]=malloc(21 * sizeof(nombresRelac[0][0]));
        strcpy(nombresRelac[i++],aux->nombre);
        aux=aux->proxAl;
    }

    nombresRelac[i]=NULL;
    return nombresRelac;
}

/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como 
** elemento
 */
char ** 
related(const socialADT soc, const char * person){
    personas aux=soc->per;

    while (aux != NULL && strcmp(aux->nombre,person)<=0){
        if (!strcmp(aux->nombre,person)){
            return relatedAux(aux);
        }
        aux=aux->proxPers;
    }

    char ** nombresAllegados=malloc(sizeof(nombresAllegados[0]));
    nombresAllegados[0]=NULL;
    return nombresAllegados;
}

/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como 
** elemento
 */
char ** 
persons(const socialADT soc){
    char ** pers;
    if (soc->cantPer == 0){
        pers=malloc(sizeof(pers[0]));
        pers[0]=NULL;
        return pers;
    }

    pers=malloc((soc->cantPer + 1) * sizeof(pers[0]));
    personas aux=soc->per;
    int i=0;

    while (aux != NULL){
        pers[i]=malloc(21 * sizeof(char));
        strcpy(pers[i],aux->nombre);
        aux=aux->proxPers;
        i++;
    }
    pers[i]=NULL;
    return pers;
}