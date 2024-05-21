#ifndef DRONE_H
#define DRONE_H

#include <stdbool.h>

// Definição da estrutura _drone
typedef struct _drone {
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
} drone_struct;

// Definição de um ponteiro para a estrutura _drone
typedef drone_struct* drone;

// Protótipos das funções
drone criaDrone(int capacidade, int alcance);
void destroiDrone(drone d);
void defineCategoriaDrone(drone d, const char *categoria);
void defineIdDrone(drone d, int id);
char *categoriaDrone(drone d);
int idDrone(drone d);
int capacidadeCargaDrone(drone d);
int alcanceDrone(drone d);
int alcanceDisponivelDrone(drone d);    
int restoVooDrone(drone d);
int restoManutencaoDrone(drone d);

int *elementosDroneColetivo(drone d);
int tamanhoElementosDroneColetivo(drone d);
#endif // DRONE_H
