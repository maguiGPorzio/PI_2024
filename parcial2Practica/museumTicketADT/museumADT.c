/*
 Se desea implementar un TAD para laventadeticketsparaunmuseo,quepermita
 sabercuántos ticketshay por día y por año,como así tambiénobtener losnombresdelas
 personasquereservaronticketsparaundíadeterminado.Cadadíaseidentificaporelorden
 dentrodelaño,alprimerodeenerolecorresponde1,al2deenero2,al1defebrero32,etc
*/
#include <stdio.h>
#include <assert.h>
#include "/home/mgonzalezporzio/PI/museumADT.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#define AMOUNT_DAYS 366
#define DAY_IN_RANGE(M) ((M)>0 && (M)<=AMOUNT_DAYS)


typedef struct personList{
    char * p;
    struct personList * nextP;
}personList;

typedef struct infoDay{
    personList * firstPerson;
    int dayTickets;
    personList * next; //iterador
} infoDay;

struct museumTicketCDT{
    infoDay days[366];
    size_t totalTickets;
};

/**
 * Reserva los recursos para administrar las ventas de tickets para visitar un museo en
 * un año determinado
 * Nota: Como no se indica el año para el que se lo utilizará se asume que el
 * año será siempre bisiesto
 * 366 dias
 */
museumTicketADT newMuseumTicket(void){
    museumTicketADT new=calloc(1,sizeof(struct museumTicketCDT));
    return new;
}

char *
copyString(const char * visitor){
    char * new=malloc(strlen(visitor) + 1);
    strcpy(new,visitor);
    return new;
}

static personList *
addPerson(personList * list, const char * visitor, size_t * registered){
    int c;
    if (list == NULL || (c=strcasecmp(list->p, visitor)) > 0){
        personList * newPerson=malloc(sizeof(personList));
        newPerson->p=copyString(visitor);
        newPerson->nextP=list;
        *registered=1;
        return newPerson;
    }

    if (!c){
        return list;
    }

    list->nextP=addPerson(list->nextP,visitor,registered);
    return list;
}

/**
 * Se registra un ticket para que #visitor visite el museo el día #dayOfYear del año 
 * Retorna la cantidad actual de tickets registrados para visitar el museo ese día
 * Retorna 0 si #dayOfYear es igual a 0 o mayor a 366
 * Retorna 0 si ya se había registrado un ticket para ese #visitor y ese #dayOfYear
 */
int addTicket(museumTicketADT museumTicketADT, size_t dayOfYear, const char * visitor){
    if (!DAY_IN_RANGE(dayOfYear)){
        return 0;
    }

    size_t registered=0;
    museumTicketADT->days[dayOfYear - 1].firstPerson=addPerson(museumTicketADT->days[dayOfYear - 1].firstPerson, visitor, &registered);

    if (!registered){
        return 0;
    }

    museumTicketADT->totalTickets++;

    return ++museumTicketADT->days[dayOfYear - 1].dayTickets;
}

/**
 * Retorna la cantidad de tickets registrados para visitar el museo el día #dayOfYear
 * del año
 * Retorna -1 si #dayOfYear es igual a 0 o mayor a 366
 */
int dayTickets(const museumTicketADT museumTicketADT, size_t dayOfYear){
    if (!DAY_IN_RANGE(dayOfYear)){
        return -1;
    }

    return museumTicketADT->days[dayOfYear - 1].dayTickets;
}

/**
 * Retorna la cantidad total de tickets registrados para visitar el museo (todos los
 * días del año)
 */
int yearTickets(const museumTicketADT museumTicketADT){
    return museumTicketADT->totalTickets;
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
    if (!DAY_IN_RANGE(dayOfYear)){
        exit(1);
    }

    museumTicketADT->days[dayOfYear - 1].next=museumTicketADT->days[dayOfYear - 1].firstPerson;
}

size_t hasNextByDay(museumTicketADT museumTicketADT, size_t dayOfYear){
    if (!DAY_IN_RANGE(dayOfYear)){
        exit(1);
    }

    return museumTicketADT->days[dayOfYear - 1].next != NULL;
}

char * nextByDay(museumTicketADT museumTicketADT, size_t dayOfYear){
    if (!DAY_IN_RANGE(dayOfYear) || !hasNextByDay(museumTicketADT, dayOfYear)){
        exit(1);
    }

    char * aux=museumTicketADT->days[dayOfYear - 1].next->p;
    museumTicketADT->days[dayOfYear - 1].next=museumTicketADT->days[dayOfYear - 1].next->nextP;
    return aux;
}

void
freePersons(personList * l){
    if (l == NULL){
        return;
    }

    personList * aux=l->nextP;
    free(l->p);
    free(l);
    freePersons(aux);
}

/**
 * Libera los recursos utilizados para administrar las ventas de tickets para visitar
 * un museo en un año determinado
 */
void freeMuseumTicket(museumTicketADT museumTicketADT){
    for (int i=0 ; i<AMOUNT_DAYS ; i++){
        freePersons(museumTicketADT->days[i].firstPerson);
    }
    free(museumTicketADT);
}