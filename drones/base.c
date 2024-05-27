/*base.c*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"
#include "coordenadas.h"
#include "base.h"
#include "drone.h"
#include "encomendas.h"

#define CAP 150


struct _base {
    char *nome;
    coordenadas localizacao;
    int tempo;
    sequencia drones;
    sequencia encomendas;
};

base criaBase(char *nome, coordenadas localizacao) {
    base b = malloc(sizeof(struct _base));
    if (b == NULL) return NULL;

    b->nome = strcpy(malloc(strlen(nome) + 1), nome);
    b->localizacao = localizacao;
    b->tempo = 0;
    b->drones = criaSequencia(CAP, (destroiFun)destroiDrone);
   
    b->encomendas = criaSequencia(CAP, (destroiFun)destroiEncomenda);
    
    return b;
}

void destroiBase(base b) {
    destroiSequencia(b->drones); 
    
    destroiCoordenadas(b->localizacao);
    free(b->nome);
    free(b);
}

/*n sei se e necessaria*/
void destroiBaseEDrones(base b) {
    destroiSeqEElems(b->drones); 
    
    destroiCoordenadas(b->localizacao);
    free(b->nome);
    free(b);
}

char *nomeBase(base b) {
    return b->nome;
}

coordenadas localizacaoBase(base b) {
    return b->localizacao;
}

void avancaUmaHoraBase(base b, int tempo) {
    
    b->tempo += tempo;
    // Fazer
}

void adicionaDroneBasicoBase(base b, drone d) {
    
    adicionaPosSequencia(b->drones, d, tamanhoSequencia(b->drones));
}

void adicionaDroneColetivoBase(base b, drone d) {

    adicionaPosSequencia(b->drones, d, tamanhoSequencia(b->drones));
}

void adicionaEncomendaBase(base b, encomenda e) {

    adicionaPosSequencia(b->encomendas, e, tamanhoSequencia(b->encomendas));
}

int daLotacaoBase(base b){
    return tamanhoSequencia(b->drones) + tamanhoSequencia(b->encomendas)
        + tamanhoSequencia(b->drones);
}

drone daDroneBase(base b, int i){
    return (drone)elementoPosSequencia(b->drones, i);
}

encomenda daEncomendasBase(base b, int i){
    return (encomenda)elementoPosSequencia(b->encomendas, i);
}

sequencia sequenciaDronesBase(base b){
    return b->drones;
}

sequencia sequenciaEncomendasBase(base b){
    return b->encomendas;
}

bool droneExisteNaBase(base b, int id){
    for (int i = 0; i < tamanhoSequencia(b->drones); i++) {
        drone d = (drone)elementoPosSequencia(b->drones, i);
        if (idDrone(d) == id) return true;
    }
    for (int i = 0; i < tamanhoSequencia(b->drones); i++) {
        drone d = (drone)elementoPosSequencia(b->drones, i);
        if (idDrone(d) == id) return true;
    }
    return false;
}

bool EncomendaExisteNaBase(base b, int id){
    for (int i = 0; i < tamanhoSequencia(b->encomendas); i++) {
        encomenda e = (encomenda)elementoPosSequencia(b->encomendas, i);
        if (idEncomenda(e) == id) return true;
    }
    return false;
}

bool idDuplicadoNaBase(base b, int id){
    sequencia dronesDaBase = sequenciaDronesBase(b);
    for (int i = 0; i < tamanhoSequencia(dronesDaBase); i++) {
        drone d = elementoPosSequencia(dronesDaBase, i);
        if (idDrone(d) == id && strcmp(categoriaDrone(d), "coletivo") == 0) {
            return true;
        }
    }
    return false;
}

void removeDroneBase(base b, int id) {
    int i, n = tamanhoSequencia(b->drones);
    for (i = 0; i < n; i++) {
        drone d = (drone)elementoPosSequencia(b->drones, i);
        if (id == idDrone(d)) {
            removePosSequencia(b->drones, i);
            destroiDrone(d); 
            break;
        }
    }
}

bool droneBasicoEmColetivo(base b, int id){
    int n = tamanhoSequencia(b->drones);
    for (int i = 0; i < n; i++){
        drone d = elementoPosSequencia(b->drones, i);//corre seq
        if(strcmp(categoriaDrone(d), "coletivo") == 0){//ve se e coletivo
            int *elems = elementosDroneColetivo(d);
            int num_elems = tamanhoElementosDroneColetivo(d);//ids do coletivo
            for (int j = 0; j < num_elems; j++){
                if (elems[j] == id){
                    return true;    //pertence ao coletivo
                }
            }
        }
    }
    return false;
}
