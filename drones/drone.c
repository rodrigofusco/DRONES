/* drone.c */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"

#include "base.h"
#include "sistema.h"
#include "drone.h"
#include "coordenadas.h"

#define CAP 1000


struct _drone{
    char *cat; // se é coletivo ou se é basico
    int id; // inteiro que corresponde a cada drone
    int cap; // capacidade de carga
    int alc; // alcance que o drone consegue voar
    int alcD; // alacance disponivel de um drone
    int voo; // ainda falta 'N' horas de voo
    int man; // horas de manutenção que faltam(para qlq drone é sempre 3 horas)
    int num_elems;
    int elems[1000];
};

drone criaDrone(int capacidade, int alcance){ 
    drone d = (drone) malloc(sizeof(struct _drone));
    if(d == NULL)
        return NULL;

    d->cat = NULL; // Categoria não especificada
    d->id = 0; 
    d->cap = capacidade; 
    d->alc = alcance; 
    d->alcD = 0; //alcance disponivel
    d->voo = 0;
    d->man = 0; //mauntencao
    d->num_elems = 0; // Inicializando o número de elementos
    memset(d->elems, 0, sizeof(d->elems)); // Inicializando os elementos

    return d;
}

void destroiDrone(drone d){
    free(d);
}


int idDrone(drone d){
    return d->id;
}


int capacidadeCargaDrone(drone d){
    return d->cap;

}


int alcanceDrone(drone d){
    return d->alc;

}

int alcanceDisponivelDrone(drone d){
    return d->alcD;

}

int restoVooDrone(drone d){
    return d->voo;

}

int restoManutencaoDrone(drone d){
	return d->man;
   
}

void cmdBasicoDrone(char *linha, base b, int *num_drones) {
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



void cmdColetivoDrone(char *linha, base b, int *num_drones) {
    // Alcance do drone coletivo é o menor alcance entre os drones que formam o coletivo
    int nmr_ids[5];
    int cap_coletivo = 0, alc_coletivo = INT_MAX;

    // Lendo os IDs dos drones da linha de entrada
    int num_ids_lidos = sscanf(linha + 1, "%d %d %d %d %d", &nmr_ids[0], &nmr_ids[1], &nmr_ids[2], &nmr_ids[3], &nmr_ids[4]);

    sequencia _drones_ = sequenciaDrones(b);

    // Vetor para armazenar os IDs dos drones que compõem o coletivo
    int elems_coletivo[5];
    
    // Verificando o número de IDs lidos e processando-os
    for (int i = 0; i < num_ids_lidos; i++) {
        // Obtendo o drone correspondente ao ID da sequência
        drone exp = elementoPosSequencia(_drones_, nmr_ids[i] - 1);
    
        // Verificando se o drone foi encontrado
        if (exp != NULL) {
            // Adicionando a capacidade do drone coletivo
            cap_coletivo += exp->cap;
            // Armazenando o ID do drone
            elems_coletivo[i] = exp->id;
        }
    }

    // Imprimindo a capacidade coletiva
    printf("capacidade coletiva: %d\n", cap_coletivo);

    for (int i = 0; i < num_ids_lidos; i++) {
        drone exp = elementoPosSequencia(_drones_, nmr_ids[i] - 1);

        if (exp != NULL) {
            if (exp->alc < alc_coletivo) {
                alc_coletivo = exp->alc;
            }
        }
    }
    printf("alcance coletivo: %d\n", alc_coletivo);

    drone novo_drone = criaDrone(cap_coletivo, alc_coletivo);

    // Atualizar o ID do novo drone e a categoria
    novo_drone->id = ++(*num_drones);
    novo_drone->cat = "coletivo";

    // Atualizar os elementos do novo drone coletivo
    novo_drone->num_elems = num_ids_lidos;
    for (int i = 0; i < num_ids_lidos; i++) {
        novo_drone->elems[i] = elems_coletivo[i];
    }

    adicionaDroneBase(b, novo_drone);

    // Imprimindo os elementos do coletivo
    printf("Adicionado drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d, elems=(",
           novo_drone->cat, novo_drone->id, novo_drone->cap, novo_drone->alcD, novo_drone->alc,
           novo_drone->voo, novo_drone->man);

    for (int i = 0; i < num_ids_lidos; i++) {
        if (i > 0) printf(" ");
        printf("%d", elems_coletivo[i]);
    }
    printf("))\n");
}

void printDrones(base b) {
    sequencia _drones_ = sequenciaDrones(b);

    for (int i = 0; i < tamanhoSequencia(_drones_); i++) {
        drone d = elementoPosSequencia(_drones_, i);

        if (strcmp(d->cat, "basico") == 0) {
            printf("drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d)\n",
                   d->cat, d->id, d->cap, d->alcD, d->alc, d->voo, d->man);
        }
        if (strcmp(d->cat, "coletivo") == 0) {
            // Imprimindo os IDs dos elementos do coletivo
            printf("drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d, elems=(",
                   d->cat, d->id, d->cap, d->alcD, d->alc, d->voo, d->man);

            for (int j = 0; j < d->num_elems; j++) {
                if (j > 0) printf(" ");
                printf("%d", d->elems[j]);
            }
            printf("))\n");
        }
    }
}

