#include <stdio.h>
#include <assert.h>
#include "/home/mgonzalezporzio/PI/museumTicketADT.h"
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#define DAY_OUT_RANGE(M)  ((M) == 0 || (M)>366) ? 1 : 0

/*
Se desea implementar un TAD para la venta de tickets para un museo, que permita saber cuántos tickets hay por día y por año, 
como así también obtener los nombres de las personas que reservaron tickets para un día determinado. Cada día se identifica por el 
orden  dentro del año, al primero de enero le corresponde 1, al 2 de enero 2, al 1 de febrero 32, etc.

Se pide:
Implementar todas las estructuras necesarias, de forma tal que todas las funciones puedan ser implementadas de la forma más eficiente 
posible (no sólo las que les pedimos implementar)
Implementar las siguientes funciones:
newMuseumTicket
addTicket
dayTickets
toBeginByDay

USAR STRCASECMP
*/

struct ticket{
    char * visitor;
    struct ticket * nextVisitor;
};

struct day{
    struct ticket * firstVisitor;
    size_t tickSold; //cantidad de tickets vendidos para ese dia 
    struct ticket * nextVis;
};

struct museumTicketCDT{
    struct day * days;
    size_t totalTicketsSold;
};

/**
 * Reserva los recursos para administrar las ventas de tickets para visitar un museo en
 * un año determinado
 * Nota: Como no se indica el año para el que se lo utilizará se asume que el
 * año será siempre bisiesto
 */
museumTicketADT newMuseumTicket(void){
    museumTicketADT new=calloc(1,sizeof(struct museumTicketCDT));
    new->days=calloc(366,sizeof(struct day));
    return new;
}

struct ticket *
addTicketRec(struct ticket * tick, const char * visitor, int * added){
    int c;
    if (tick == NULL || (c=strcasecmp(tick->visitor,visitor)) > 0){
        struct ticket * newVisitor=malloc(sizeof(struct ticket));

        newVisitor->visitor=malloc(strlen(visitor) + 1);
        strcpy(newVisitor->visitor,visitor);

        newVisitor->nextVisitor=tick;

        *added=1;

        return newVisitor;
    }

    if (!c){
        return tick;
    }

    tick->nextVisitor=addTicketRec(tick->nextVisitor,visitor,added);
    return tick;

}

/**
 * Se registra un ticket para que #visitor visite el museo el día #dayOfYear del año 
 * Retorna la cantidad actual de tickets registrados para visitar el museo ese día
 * Retorna 0 si #dayOfYear es igual a 0 o mayor a 366
 * Retorna 0 si ya se había registrado un ticket para ese #visitor y ese #dayOfYear
 */
int addTicket(museumTicketADT museumTicketADT, size_t dayOfYear, const char * visitor){
    if (DAY_OUT_RANGE(dayOfYear)){
        return 0;
    }

    int added=0;
    
    museumTicketADT->days[dayOfYear - 1].firstVisitor=addTicketRec(museumTicketADT->days[dayOfYear - 1].firstVisitor, visitor, &added);

    if (!added){
        return 0;
    }

    museumTicketADT->totalTicketsSold++;
    
    return ++museumTicketADT->days[dayOfYear - 1].tickSold;
}

/**
 * Retorna la cantidad de tickets registrados para visitar el museo el día #dayOfYear
 * del año
 * Retorna -1 si #dayOfYear es igual a 0 o mayor a 366
 */
int dayTickets(const museumTicketADT museumTicketADT, size_t dayOfYear){
    if (DAY_OUT_RANGE(dayOfYear)){
        return -1;
    }
    return museumTicketADT->days[dayOfYear - 1].tickSold;
}

/**
 * Retorna la cantidad total de tickets registrados para visitar el museo (todos los
 * días del año)
 */
int yearTickets(const museumTicketADT museumTicketADT){
    return museumTicketADT->totalTicketsSold;
}

/**
 * Funciones de iteración para poder consultar, para un día #dayOfYear del año,
 * los nombres de los visitantes de los tickets registrados para visitar el museo
 * ese día en orden alfabético por nombre de visitante.
 * IMPORTANTE: Permitir utilizar estas funciones para distintos días del año 
 * EN SIMULTANEO (ver ejemplo en programa de prueba)
 * Abortar si cualquiera de las funciones es invocada con un #dayOfYear igual a 0 
 * o mayor a 366
 */
void toBeginByDay(museumTicketADT museumTicketADT, size_t dayOfYear){
    if (DAY_OUT_RANGE(dayOfYear)){
        exit(1);
    }
    museumTicketADT->days[dayOfYear - 1].nextVis=museumTicketADT->days[dayOfYear - 1].firstVisitor;
}

size_t hasNextByDay(museumTicketADT museumTicketADT, size_t dayOfYear){
    if (DAY_OUT_RANGE(dayOfYear)){
        exit(1);
    }
    return museumTicketADT->days[dayOfYear - 1].nextVis != NULL;
}

char * nextByDay(museumTicketADT museumTicketADT, size_t dayOfYear){
    if (DAY_OUT_RANGE(dayOfYear)){
        exit(1);
    }

    if (!hasNextByDay(museumTicketADT,dayOfYear)){
        exit(1);
    }
    
    char * aux=museumTicketADT->days[dayOfYear - 1].nextVis->visitor;
    museumTicketADT->days[dayOfYear - 1].nextVis=museumTicketADT->days[dayOfYear - 1].nextVis->nextVisitor;
    return aux;
}


void 
freeTickets(struct ticket * tickets){
    if (tickets == NULL){
        return; 
    }

    struct ticket * aux=tickets->nextVisitor;
    free(tickets->visitor);
    free(tickets);
    freeTickets(aux);
}

/**
 * Libera los recursos utilizados para administrar las ventas de tickets para visitar
 * un museo en un año determinado
 */
void freeMuseumTicket(museumTicketADT museumTicketADT){
    for (int i=0 ; i<366 ; i++){
        freeTickets(museumTicketADT->days[i].firstVisitor);
    }
    free(museumTicketADT->days);
    free(museumTicketADT);
}
