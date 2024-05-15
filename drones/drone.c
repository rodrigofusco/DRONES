/* drone.c */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "drone.h"
#include "base.h"

struct _drone{
    char *cat; // se é coletivo ou se é basico
    int id; // inteiro que corresponde a cada drone
    int cap; // capacidade de carga
    int alc; // alcance que o drone consegue voar
    int alcD; // alacance disponivel de um drone
    int voo; // ainda falta 'N' horas de voo
    int man; // horas de manutenção que faltam(para qlq drone é sempre 3 horas)
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

void cmdBasedrone(char *linha, drone **base_drone, int *num_drones) {
    int cap, alc;
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
    base_drone[*num_drones - 1] = &novo_drone;

    // Imprimir as informações do novo drone
    printf("Adicionado drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d)\n", novo_drone->cat, novo_drone->id, novo_drone->cap, novo_drone->alcD, novo_drone->alc, novo_drone->voo, novo_drone->man);
}



/*
void criaDroneColetivo(char *linha, drone d){
    //alcance do drone coletivo é o menor do alcance entre os drones que formam o coletivo
    int nrmdrones[5];
    int id_coletivo = 0, cap_coletivo = 0, alc_coletivo = 0;
    char categoria_coletivo[12] = "coletivo";

    drone d1 = criaDrone(cap_coletivo, alc_coletivo);
    int a = idDrone(d);
    a++;
    
	sscanf(linha + 1, "%d %d %d %d %d %d", &nrmdrones[0], &nrmdrones[1], &nrmdrones[2], &nrmdrones[3], &nrmdrones[4], &nrmdrones[5]);

    for(int i = 0; i < 6; i++){
        if(nrmdrones[i] == 0){
            
        }
        
    }
    printf("Adicionado drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d, elems(%d, %d))\n", categoria_coletivo, id_coletivo, d->cap, d->alcD, d->alc, d->voo, d->man, d->id, d->id);

}

void Saber_merdas(drone d){
    printf("Id: %d", idDrone(d));
    printf("Cpacidade: %d", capacidadeCargaDrone(d));
}
*/

