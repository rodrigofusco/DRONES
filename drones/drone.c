#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "drone.h"  
    
struct _drone{
    char *cat; //"basico" : "coletivo";
	int id; // indentidade do drone é unico 
	int cap; // capacidade do drone me kg
	int alc; // alacance do drone em KM
	int alcD; // alcance que o drone ainda tem em KM
	int voo; // horas de viagem
	int man; // horas que ainda falta de manutenção 
};


_drone criadrone() {
    _drone d = (_drone)malloc(sizeof(struct _drone));

    if (d == NULL) {
        printf("Erro ao alocar memória para o drone\n");			
        return NULL; // Return NULL if memory allocation fails
    }

    // Initialize members of the drone object
    d->cat = NULL; // Initialize cat to NULL or assign it a value
    d->id = 0; // Initialize id to 0 or assign it a value
    d->cap = 0; // Initialize cap to 0 or assign it a value
    d->alc = 0; // Initialize alc to 0 or assign it a value
    d->alcD = 0; // Initialize alcD to 0 or assign it a value
    d->voo = 0; // Initialize voo to 0 or assign it a value
    d->man = 0; // Initialize man to 0 or assign it a value

    return d; // Return the created drone object
}
bool basicoDrone(_drone d){

	return false;
}

int idDrone(_drone d){


	return d->id;
}

int capacidadeCargaDrone(_drone d){

	return d->cap;
}

int alcanceDrone(_drone d){

	return 0;
}

int alcanceDisponivelDrone(_drone d){

	return 0;
}

int restoVooDrone(_drone d){

	return 0;
}

int restoManutencaoDrone(_drone d){

	return 0;
}

/*void drone_Base(void){
    int _cap, _alc;
    
    // Ler os valores da linha ignorando o primeiro caractere (o comando)
    sscanf(linha + 1, "%d %d", &_cap, &_alc);
    d->id++;
    d->cap = _cap;
    d->alc = _alc;

    // Imprimir os valores para verificar se foram lidos corretamente
    printf("ID: %d, Capacidade: %d, Alcance: %d\n\n", d->id, d->cap, d->alc);
}*/
