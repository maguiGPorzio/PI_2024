 #include <assert.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "/home/mgonzalezporzio/PI/airportADT.h"
 #define RUNAWAY_EXISTS(M) ((M)>=1)
 #define RUNAWAY_IN_RANGE(M,N) ((M)<=(N))
 #define NOT_OCC 0
 #define OCC 1

  /*
 Se desea implementar un TAD para administrar las pistas y los despegues de
 aviones de un aeropuerto.Cada pista se identifica con un número entero positivo,siendo
 la primera pista el número1, la segunda el número2,etc.

  Se pide:
    ● Implementar todas las estructuras necesarias, de forma tal que las funciones
    addRunway, addPlaneToRunway y takeOff puedan ser implementadas de la
    forma más eficiente posible.
    ● Implementar las siguientes funciones:
        ○ newAirport
        ○ takeOff
        ○ pendingFlights
 */

typedef struct airplane{
    char * reg;
    size_t longReg;
    struct airplane * next;
} airplane;

typedef struct runaway{
    airplane * first;
    airplane * last;
    size_t amount;
}runaway;

struct airportCDT{
    runaway * runWays;
    char * occRunw;
    size_t realAmount;
    size_t resAmount;
};
 
 
 /* Crea un sistema de administración de pistas y despegues de aviones
 ** de un aeropuerto.
 ** El sistema inicia sin pistas.
 */
 airportADT newAirport(void){
    airportADT new=calloc(1, sizeof(struct airportCDT));
    return new;
 }

 /* Agrega una pista de despegue con el identificador runwayId.
 ** La pista inicia sin aviones.
 ** Retorna la cantidad actual de pistas en el sistema o-1 si falla.
 ** Falla si existe una pista con el identificador runwayId.
 */
 int addRunway(airportADT airportAdt, size_t runwayId){
    if (!RUNAWAY_EXISTS(runwayId)){
        return -1;
    }

    if (!RUNAWAY_IN_RANGE(runwayId, airportAdt->resAmount)){
        airportAdt->runWays=malloc(runwayId * sizeof(runaway));
        airportAdt->occRunw=malloc(runwayId);
        size_t i=airportAdt->resAmount;
        for (; i<runwayId ; i++){
            airportAdt->occRunw[i]=NOT_OCC;
        }
        airportAdt->resAmount=runwayId;
    }

    if (airportAdt->occRunw[runwayId - 1] == OCC){
        return -1;
    }

    airportAdt->occRunw[runwayId - 1]=OCC;

    runaway * r=&airportAdt->runWays[runwayId - 1];
    r->amount=0;
    r->first=NULL;
    r->last=NULL;

    return ++airportAdt->realAmount;
 }

static airplane *
newPlane(const char * registration){
    airplane * new=malloc(sizeof(airplane));
    new->longReg=strlen(registration);
    new->reg=malloc(new->longReg + 1);
    strcpy(new->reg,registration);
    new->next=NULL;
    return new;
 }

 /* Agrega al final de la pista de despegue con el identificador
 ** runwayId al avión de matrícula registration
 ** y retorna la cantidad actual de aviones en la pista o-1 si falla.
 ** Falla si la pista no existe.
 */
int addPlaneToRunway(airportADT airportAdt, size_t runwayId, const char * registration){
    if (!RUNAWAY_EXISTS(runwayId) || !RUNAWAY_IN_RANGE(runwayId, airportAdt->resAmount) || airportAdt->occRunw[runwayId - 1] == NOT_OCC){
        return -1;
    }

    runaway * r=&airportAdt->runWays[runwayId - 1];
    airplane * new=newPlane(registration);

    if (r->amount == 0){
        r->first=new;
        r->last=new;
    }
    else{
        r->last->next=new;
        r->last=new;
    }

    return ++r->amount;
}

/* Elimina al avión que se encuentra al principio de la pista de
** despegue con el identificador runwayId
** y retorna la matrícula del avión eliminado o NULL si falla.
** Falla si la pista no existe.
** Falla si no hay aviones en la pista.
*/
char * takeOff(airportADT airportAdt, size_t runwayId){
    if (!RUNAWAY_EXISTS(runwayId) || !RUNAWAY_IN_RANGE(runwayId, airportAdt->resAmount) || airportAdt->occRunw[runwayId - 1] == NOT_OCC){
        return NULL;
    }

    runaway * r=&airportAdt->runWays[runwayId - 1];

    if (r->amount == 0){
        return NULL;
    }

    char * deleted=r->first->reg;

    airplane * newFirst=r->first->next;
    free(r->first);
    r->first=newFirst;

    if (newFirst == NULL){
        r->last=NULL;
    }

    r->amount--;

    return deleted;
}
 
/* Retorna un arreglo con las matrículas de los aviones que se
 ** encuentran en la pista de despegue con el identificador
 ** runwayId en orden inverso al orden de despegue (el último elemento
 ** del arreglo debe coincidir con el valor de retorno de una
 ** invocación a la función takeOff sobre esa pista).
 ** El arreglo debe ** contar con una cadena vacía "" como marca de fin.
 ** Si la pista no existe retorna NULL.
 */
char ** pendingFlights(airportADT airportAdt, size_t runwayId){
    if (!RUNAWAY_EXISTS(runwayId) || !RUNAWAY_IN_RANGE(runwayId, airportAdt->resAmount) || airportAdt->occRunw[runwayId - 1] == NOT_OCC ){
        return NULL;
    }

    runaway * r=&airportAdt->runWays[runwayId -1];

    if (r->amount == 0){
        return NULL;
    }

    char ** flights=malloc(sizeof(flights[0]) * (r->amount+1));

    airplane * actAirplane=r->first;

    int i=r->amount;

    flights[i--]="";

    for (; i>=0 ; i--){
        flights[i]=actAirplane->reg;
        actAirplane=actAirplane->next;
    }

    return flights;
}

//  /* Libera los recursos utilizados por el sistema de administración de
//  ** pistas y despegues de aviones de un aeropuerto.
//  */
//  void freeAirport(airportADT airportAdt);