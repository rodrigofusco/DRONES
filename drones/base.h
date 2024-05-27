#ifndef BASE_H_
#define BASE_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"
#include "coordenadas.h"
#include "drone.h"
#include "encomendas.h"

typedef struct _base *base;

base criaBase(char *nome, coordenadas localizacao);
void destroiBase(base b);
void destroiBaseEDrones(base b);
char *nomeBase(base b);
coordenadas localizacaoBase(base b);
void avancaUmaHoraBase(base b, int tempo);
void adicionaDroneBasicoBase(base b, drone d);
void adicionaDroneColetivoBase(base b, drone d);
void adicionaEncomendaBase(base b, encomenda e);
int daLotacaoBase(base b);
drone daDroneBase(base b, int i);
encomenda daEncomendasBase(base b, int i);
sequencia sequenciaDronesBase(base b);
sequencia sequenciaEncomendasBase(base b);
bool droneExisteNaBase(base b, int id); //selfExplanatory
//para c 1 2 3 mas 3 e coletivo
bool EncomendaExisteNaBase(base b, int id);
bool idDuplicadoNaBase(base b, int id);
void removeDroneBase(base b, int id);
bool droneBasicoEmColetivo(base b, int id);

#endif /* BASE_H_ */
