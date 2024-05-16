/*drone.h*/

#ifndef DRONE_H_
#define DRONE_H_

/* Tipo de dados: drone */
typedef struct _drone* drone;
typedef struct _base* base;
/***********************************************
criaDrone - Criação de uma instância da estrutura associada ao tipo drone.
Parametros: matricula - matrícula do drone
            hora - hora de entrada em operação do drone
            minuto - minuto de entrada em operação do drone
Retorno: apontador para a instância criada
Pre-condições:
***********************************************/
drone criaDrone(int capacidade, int alcance); 

/*falta comentar*/
void destroiDrone(drone d);

/***********************************************
idDrone - Consulta o ID do drone.
Parametros: d - drone do qual se quer consultar o ID
Retorno: ID do drone
Pre-condições: d != NULL
***********************************************/
int idDrone(drone d);

/***********************************************
capacidadeCargaDrone - Consulta a capacidade de carga do drone.
Parametros: d - drone do qual se quer consultar a capacidade de carga
Retorno: capacidade de carga do drone
Pre-condições: d != NULL
***********************************************/
int capacidadeCargaDrone(drone d);

/***********************************************
alcanceDrone - Consulta o alcance máximo do drone.
Parametros: d - drone do qual se quer consultar o alcance máximo
Retorno: alcance máximo do drone
Pre-condições: d != NULL
***********************************************/
int alcanceDrone(drone d);

/***********************************************
alcanceDisponivelDrone - Consulta o alcance disponível do drone.
Parametros: d - drone do qual se quer consultar o alcance disponível
Retorno: alcance disponível do drone
Pre-condições: d != NULL
***********************************************/
int alcanceDisponivelDrone(drone d);

/***********************************************
restoVooDrone - Consulta o tempo restante de voo do drone.
Parametros: d - drone do qual se quer consultar o tempo restante de voo
Retorno: tempo restante de voo do drone
Pre-condições: d != NULL
***********************************************/
int restoVooDrone(drone d);

/***********************************************
restoManutencaoDrone - Consulta o tempo restante para a próxima manutenção do drone.
Parametros: d - drone do qual se quer consultar o tempo restante para a próxima manutenção
Retorno: tempo restante para a próxima manutenção do drone
Pre-condições: d != NULL
***********************************************/
int restoManutencaoDrone(drone d);

void cmdBasicoDrone(char *linha, base b, int *num_drones);

/***********************************************
cmdColetivoDrone - Processa o comando para criar um drone coletivo.
Parâmetros: linha - linha de comando com os IDs dos drones a serem agrupados, b - base onde os drones estão localizados, num_drones - contador do número de drones
Retorno:
Pre-condições: linha!=NULL, b!=NULL, num_drones!=NULL
***********************************************/
void cmdColetivoDrone(char *linha, base b, int *num_drones);

void printDrones(base b);

#endif /* DRONE_H_ */
