/*encomendas.c*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "TADs/iterador/iterador.h"
#include "TADs/ponto/ponto.h"
#include "TADs/sequencia/sequencia.h"
#include "encomendas.h"
#include "coordenadas.h"

#define CAP 150


struct _encomenda {
    int id;
    int pesoE;
    int latitudeE;
    int longitudeE;
    int criaE;
    int saidaE;
    int entregaE;
};

encomenda criaEncomenda(int peso, int lat, int lon) {
    encomenda e = malloc(sizeof(struct _encomenda));
    if (e == NULL) {
        return NULL;
    }
    


    e->id = 0;
    e->pesoE = peso;
    e->latitudeE = lat;
    e->longitudeE = lon;
    e->criaE = 0;
    e->saidaE = 0;
    e->entregaE = 0;

    return e;
}

void destroiEncomenda(encomenda e) {
    if (e == NULL)
        return;
    free(e);
}

int idEncomenda(encomenda e){
    return e->id;
}

int pesoEncomenda(encomenda e){
    return e->pesoE;
}


int latitudeEncomenda(encomenda e){
    return e->latitudeE;
}

int longitudeEncomenda(encomenda e){
    return e->longitudeE;
}

int criacaoEncomenda(encomenda e){
    return e->criaE;
}

int saidaEncomenda(encomenda e){
	return e->saidaE;
}

int entregaEncomenda(encomenda e){
	return e->entregaE;
}

void defineIdEncomenda(encomenda e, int id){
    e->id = id;
}
