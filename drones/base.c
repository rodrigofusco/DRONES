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

void adicionaDroneBase(base b, drone d) {

    adicionaPosSequencia(b->drones, d, tamanhoSequencia(b->drones));
    // (acho que nao usei a seq certa)
}

void adicionaEncomendaBase(base b, encomenda e) {

    adicionaPosSequencia(b->encomendas, e, tamanhoSequencia(b->encomendas));
    // (acho que nao usei a seq certa)
}


/*n sei se e preciso*/
iterador iteradorDaDroneBase(base b){
    return iteradorSequencia(b->drones);
}

iterador iteradorDaEncomendasBase(base b){
    return iteradorSequencia(b->encomendas);
}

//cenas para a lista

int daLotacaoBase(base b){
    return tamanhoSequencia(b->drones) + tamanhoSequencia(b->encomendas);
}

drone daDroneBase(base b, int i){
    return (drone)elementoPosSequencia(b->drones, i);
}

encomenda daEncomendasBase(base b, int i){
    return (encomenda)elementoPosSequencia(b->encomendas, i);
}

sequencia sequenciaDrones(base b){
    return b->drones;
}

void cmdListagemBase(char *linha, base b){
    int i;
    encomenda e;

    int numDrones = tamanhoSequencia(b->drones);
    int numEncomendas = tamanhoSequencia(b->encomendas);

    if (numDrones == 0 && numEncomendas == 0) {
        printf("Base Vazia.\n");
    } else {
        // Listando drones
        printDrones(b);
        // Listando encomendas
        for (i = 0; i < numEncomendas; i++) {
            e = daEncomendasBase(b, i);
            printf("encomenda(id=%d, peso=%d, coord=(%d,%d), cria=%d, saida=%d, entrega=%d)\n", 
                idEncomenda(e), pesoEncomenda(e), latitudeEncomenda(e), 
                longitudeEncomenda(e), criacaoEncomenda(e), saidaEncomenda(e), 
                entregaEncomenda(e));
        }
    }
}
