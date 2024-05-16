#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "base.h"
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
    e->momentoCriacao = 0;
    e->momentoSaida = 0;
    e->momentoE = 0;

    return e;
}

void destroiEncomenda(encomenda e) {
    if (e == NULL)
        return NULL;
    destroiCoordenadas(e->destino);
    free(e);
}

void cmdBaseEncomenda(char *linha, encomenda e, int *num_encomendas) {

    //ISTO TUDO POR ALTERAR
    //
    //

    
    int cap = 0, alc = 0;

    sscanf(linha + 1, "%d %d", &cap, &alc);

    // Criar um novo drone
    drone novo_drone = criaDrone(cap, alc);
    if (novo_drone == NULL) {
        printf("Erro ao criar o novo drone\n");
        return;
    }

    // Atualizar o ID do novo drone e a categoria
    novo_drone->id = ++(*num_drones);
    novo_drone->cat = "basico";

    // Adicionar o novo drone à base de drones
    adicionaDroneBase(b, novo_drone);

    // Imprimir as informações do novo drone
    printf("Adicionado drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d)\n", novo_drone->cat, novo_drone->id, novo_drone->cap, novo_drone->alcD, novo_drone->alc, novo_drone->voo, novo_drone->man);
}
