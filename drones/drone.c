#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "drone.h"

struct _drone {
    char *cat;
    int id;
    int cap;
    int alc;
    int alcD;
    int voo;
    int man;
    int num_elems;
    int elems[1000];
    int elementos[6];
    int numElementos;
};

drone criaDrone(int capacidade, int alcance) {
    drone d = (drone) malloc(sizeof(struct _drone));
    if(d == NULL) return NULL;
    d->cat = NULL;
    d->id = 0;
    d->cap = capacidade;
    d->alc = alcance;
    d->alcD = alcance;
    d->voo = 0;
    d->man = 0;
    d->num_elems = 0;
    memset(d->elems, 0, sizeof(d->elems));
    return d;
}

void destroiDrone(drone d) {
    if (d->cat != NULL) free(d->cat);
    free(d);
}

void defineCategoriaDrone(drone d, const char *categoria) {
    if (d->cat != NULL) free(d->cat);
    d->cat = strdup(categoria);
}

void defineIdDrone(drone d, int id) {
    d->id = id;
}

char *categoriaDrone(drone d) {
    return d->cat;
}

int idDrone(drone d) {
    return d->id;
}

int capacidadeCargaDrone(drone d) {
    return d->cap;
}

int alcanceDrone(drone d) {
    return d->alc;
}

int alcanceDisponivelDrone(drone d) {
    return d->alcD;
}

int restoVooDrone(drone d) {
    return d->voo;
}

int restoManutencaoDrone(drone d) {
    return d->man;
}

int *elementosDroneColetivo(drone d){
    return d->elementos;
}


int tamanhoElementosDroneColetivo(drone d) {
    return d->numElementos;
}

int numElementosDrone(drone d){
    return d->numElementos;
}

void defineElementosDoColetivoDrone(drone d, int *elems, int num_elems){
    for (int i = 0; i < num_elems; i++) {
        d->elementos[i] = elems[i];
    }
    d->numElementos = num_elems;
}
