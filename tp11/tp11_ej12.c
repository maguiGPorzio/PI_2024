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
`
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
    freeAlleg(all->proxAl);
    free(all);
}

static void
freePer (personas per){
    if (per == NULL){
        return;
    }

    freePer(per->proxPers);
    freeAlleg(per->alleg);
    free(per);
    
}
 
/* Libera todos los recursos reservados por el TAD */
void freeSocial(socialADT soc){
    freePer(soc->per);
    free(soc);
}

static personas
addPersonRec(personas per, const char * name, int * esta){
    if ( per==NULL || strcmp(per->nombre, name) > 0 ){
        *esta=1;
        personas nuevaPersona=calloc(1, sizeof(persona));
        nuevaPersona->nombre=malloc(21*sizeof(nuevaPersona->nombre[0]));
        strncpy(nuevaPersona->nombre, name, 21);
        nuevaPersona->proxPers=per;
        return nuevaPersona;
    }

    if (!strcmp(per->nombre, name)){
        return per;
    }
    per->proxPers=addPersonRec(per->proxPers,name,esta);
    return per;
}
 
/* Almacena una nueva persona. Si la persona existe, no hace nada
** Guarda una copia del nombre, no simplemente el puntero
*/
void addPerson(socialADT soc, const char * name){
    int esta=0;
    soc->per=addPersonRec(soc->per, name, &esta);
    soc->cantPer+=esta;
}

static allegados
addRelatedRec(allegados all, const char * related){
    if (all==NULL || !strcmp(all->nombre, related) || strcmp(all->nombre, related) > 0 ){
        allegados nuevoAll=calloc(1, sizeof(struct socialCDT));
        nuevoAll->nombre=malloc(20*sizeof(nuevoAll->nombre[0]));
        strncpy(nuevoAll->nombre, related, 20);
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

static void 
relatedAux(personas per, char ** relat){
    allegados aux=per->alleg;
    int i=0;

    while (aux != NULL){
        relat[i]=malloc(20 * sizeof(char));
        strcpy(relat[i],aux->nombre);
        aux=aux->proxAl;
    }
    relat[i]=NULL;
}

/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como 
** elemento
 */
char ** related(const socialADT soc, const char * person){
    char ** nombresAllegados=NULL;
    personas aux=soc->per;

    while (aux != NULL && strcmp(aux->nombre,person) > 0){
        if (!strcmp(aux->nombre,person)){
            nombresAllegados=malloc((aux->cantAll+1) * sizeof(char *));
            relatedAux(aux,nombresAllegados);
            nombresAllegados[aux->cantAll]=NULL;
            return nombresAllegados;
        }
    }


    nombresAllegados=malloc(sizeof(char *));
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
    if (soc->per == 0){
        pers=malloc(sizeof(char *));
        pers[0]=NULL;
        return pers;
    }

    pers=malloc((soc->cantPer + 1) * sizeof(pers[0]));
    personas aux=soc->per;
    int i=0;

    while (aux != NULL){
        pers[i]=malloc(20 * sizeof(char));
        strcpy(pers[i],aux->nombre);
        aux=aux->proxPers;
    }
    pers[i]=NULL;
    return pers;
}