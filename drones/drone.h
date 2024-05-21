#ifndef DRONE_H
#define DRONE_H

#include <stdbool.h>

typedef struct _base *base;

// Definição de um ponteiro para a estrutura _drone
typedef struct _drone *drone;

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
int numElementosDrone(drone d);
void defineElementosDoColetivoDrone(drone d, int *elems, int num_elems);


#endif // DRONE_H
