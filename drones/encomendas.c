/*encomendas.c*/

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

void cmdBaseEncomenda(char *linha, base b, int *num_encomendas) {

    int peso = 0,  lat=0, lon=0;

    sscanf(linha + 1, "%d %d %d", &peso, &lat, &lon);

    // Criar um nova encomenda
    encomenda nova_encomenda = criaEncomenda(peso, lat, lon);
    if (nova_encomenda == NULL) {
        printf("Erro ao criar o nova encomenda\n");
        return;
    }


    // Atualizar o ID do novo drone e a categoria
    
    nova_encomenda->id = ++(*num_encomendas);

    // Adicionar o nova encomenda à base

    adicionaEncomendaBase(b, nova_encomenda);

    // Imprimir as informações do novo drone
    printf("Adicionada encomenda(id=%d, peso=%d, coord=(%d,%d), cria=%d, saida=%d, entrega=%d)\n",
     nova_encomenda->id, nova_encomenda->pesoE, nova_encomenda->latitudeE, nova_encomenda->longitudeE, nova_encomenda->criaE, nova_encomenda->saidaE, nova_encomenda->entregaE);
}
