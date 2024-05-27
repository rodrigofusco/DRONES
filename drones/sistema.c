/*sistema.c*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"

#include "coordenadas.h"
#include "base.h"
#include "sistema.h"
#include "drone.h"
#include "encomendas.h"

#define TEMPO_ORIGEM	0
#define CAP 150
#define MAX_ELEMS_COLETIVO 6
#define INT_MAX 1500000


struct _sistema{
	base base;
	int tempoCorrente;
};


sistema criaSistema(){
	sistema s = malloc(sizeof(struct _sistema));
	if (s == NULL) return NULL;
   
	s->base = criaBase("FCT", criaCoordenadas(0,0));
	if (s->base == NULL) { free(s); return NULL;}
	
	s->tempoCorrente = TEMPO_ORIGEM;
	return s;
}

void destroiSistema(sistema s){
	destroiBase(s->base);
	free(s);
}

base daBaseSistema(sistema s){
    return s->base;
}

char *nomeBaseSistema(sistema s){
	return nomeBase(s->base);
}

int tempoAvancaSistema(sistema s, int n){

	for (int i = 0; i < n; i++){
		avancaUmaHoraBase(s->base, ++s->tempoCorrente);
	}
	return s->tempoCorrente;
}

int tempoSistema(sistema s){
    return s->tempoCorrente;
}

void BasicoDroneSistema(sistema s, int capacidade, int alcance, int *num_drones){
    drone novo_drone = criaDrone(capacidade, alcance);
    if (novo_drone == NULL) {
        return;
    }

    defineCategoriaDrone(novo_drone, "basico");
    defineIdDrone(novo_drone, ++(*num_drones));
    adicionaDroneBasicoBase(s->base, novo_drone);
}

void EncomendasSistema(sistema s, int peso, int lat, int lon, int cria, int *num_encomendas){
    encomenda novaEncomenda = criaEncomenda(peso, lat, lon, cria);
    if (novaEncomenda == NULL) {
        return;
    }
    
    defineIdEncomenda(novaEncomenda, (*num_encomendas)++);
    adicionaEncomendaBase(s->base, novaEncomenda);
}

drone ColetivoDroneSistema(sistema s, int *ids, int num_ids, int *num_drones) {
    int capacidade_total = 0;
    int menor_alcance = INT_MAX;
    int elems_coletivo[MAX_ELEMS_COLETIVO];
    base b = daBaseSistema(s);
    sequencia dronesDaBase = sequenciaDronesBase(b);
    int num_elems = 0;

    for (int i = 0; i < num_ids; i++) {
        drone d = NULL;
        for (int j = 0; j < tamanhoSequencia(dronesDaBase); j++) {
            d = elementoPosSequencia(dronesDaBase, j);
            if (idDrone(d) == ids[i]) {
                elems_coletivo[num_elems++] = idDrone(d);
                capacidade_total += capacidadeCargaDrone(d);
                if (alcanceDrone(d) < menor_alcance) {
                    menor_alcance = alcanceDrone(d);
                }
            }
        }
    }
    if (menor_alcance == INT_MAX) {
        menor_alcance = 0; 
    }
    drone novo_drone = criaDrone(capacidade_total, menor_alcance);
    if (novo_drone == NULL) {
        return NULL;
    }
    defineCategoriaDrone(novo_drone, "coletivo");
    defineIdDrone(novo_drone, ++(*num_drones));
    defineElementosDoColetivoDrone(novo_drone, elems_coletivo, num_elems);
    adicionaDroneColetivoBase(s->base, novo_drone);

    return novo_drone;
}

int distanciaEncomendaSistema(sistema s, int id){
    base b = daBaseSistema(s);
    coordenadas cBase = localizacaoBase(b);
    sequencia encomendas = sequenciaEncomendasBase(b);

    encomenda e = NULL;
    for (int i = 0; i < tamanhoSequencia(encomendas); i++) {
        encomenda temp = elementoPosSequencia(encomendas, i);
        if (idEncomenda(temp) == id) {
            e = temp;
            break;
        }
    }
    coordenadas cEncomenda = criaCoordenadas(latitudeEncomenda(e), longitudeEncomenda(e));
    int distancia = distanciaCoordenadas(cBase, cEncomenda, 10);
    return distancia;
}

void tempoSaidaEncomenda(sistema s, int id, int tempoSaida){
    base b = daBaseSistema(s);
    sequencia encomendas = sequenciaEncomendasBase(b);
    tempoSaida = tempoSistema(s); 
    encomenda e = NULL;
    for (int i = 0; i < tamanhoSequencia(encomendas); i++) {
        encomenda temp = elementoPosSequencia(encomendas, i);
        if (idEncomenda(temp) == id) {
            e = temp;
            defineSaidaEncomenda(e, tempoSaida);
            break;
        }
    }
}

