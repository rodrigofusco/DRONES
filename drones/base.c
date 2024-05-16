#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"

#include "base.h"
#include "sistema.h"
#include "drone.h"
#include "coordenadas.h"

#define CAP 150


struct _base {
    char *nome;
    coordenadas localizacao;
    int tempo;
    sequencia drones; 
};

base criaBase(char *nome, coordenadas localizacao) {
    base b = malloc(sizeof(struct _base));
    if (b == NULL) return NULL;

    b->nome = strcpy(malloc(strlen(nome) + 1), nome);
    b->localizacao = localizacao;
    b->tempo = 0;
    b->drones = criaSequencia(CAP, (destroiFun)destroiDrone); 
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

}



iterador iteradorDaDroneBase(base b){
    return iteradorSequencia(b->drones);
}

sequencia sequenciaDrones(base b){
    return b->drones;
}

/*sequenciaDronesBase(b) ----> na base.c
sequencia sequenciaDronesBase(base b){
return b->drones;
}*/

