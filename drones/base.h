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

/***********************************************
criaBase - Cria uma instância da estrutura associada ao tipo base.
Parâmetros: nome - nome da base, localizacao - coordenadas da localização da base
Retorno: apontador para a instância criada
Pre-condições: localizacao != NULL
***********************************************/
base criaBase(char *nome, coordenadas localizacao);

/***********************************************
destroiBase - Liberta a memória ocupada pela instância da estrutura associada ao tipo base.
Parâmetros: b - base a ser destruída
Retorno:
Pre-condições: b!=NULL
***********************************************/
void destroiBase(base b);

/***********************************************
destroiBaseEDrones - Liberta a memória ocupada pela instância da estrutura associada ao tipo base,
bem como pelos drones e encomendas nela contidos.
Parâmetros: b - base a ser destruída
Retorno:
Pre-condições: b!=NULL
***********************************************/
void destroiBaseEDrones(base b);

/***********************************************
nomeBase - Consulta o nome da base.
Parâmetros: b - base da qual se quer consultar o nome
Retorno: nome da base
Pre-condições: b!=NULL
***********************************************/
char *nomeBase(base b);

/***********************************************
localizacaoBase - Consulta a localização da base.
Parâmetros: b - base da qual se quer consultar a localização
Retorno: coordenadas da localização da base
Pre-condições: b!=NULL
***********************************************/
coordenadas localizacaoBase(base b);

/***********************************************
avancaUmaHoraBase - Avança o tempo da base em um dado número de horas.
Parâmetros: b - base cujo tempo será avançado, tempo - número de horas a serem avançadas
Retorno:
Pre-condições: b!=NULL, tempo >= 0
***********************************************/
void avancaUmaHoraBase(base b, int tempo);

/***********************************************
adicionaDroneBase - Adiciona um drone à base.
Parâmetros: b - base à qual o drone será adicionado, d - drone a ser adicionado
Retorno:
Pre-condições: b!=NULL, d!=NULL
***********************************************/
void adicionaDroneBase(base b, drone d);

/***********************************************
adicionaEncomendaBase - Adiciona uma encomenda à base.
Parâmetros: b - base à qual a encomenda será adicionada, e - encomenda a ser adicionada
Retorno:
Pre-condições: b!=NULL, e!=NULL
***********************************************/
void adicionaEncomendaBase(base b, encomenda e);

/***********************************************
iteradorDaDroneBase - Cria um iterador para os drones da base.
Parâmetros: b - base da qual se quer criar o iterador
Retorno: iterador para os drones da base
Pre-condições: b!=NULL
***********************************************/
iterador iteradorDaDroneBase(base b);

/***********************************************
iteradorDaEncomendasBase - Cria um iterador para as encomendas da base.
Parâmetros: b - base da qual se quer criar o iterador
Retorno: iterador para as encomendas da base
Pre-condições: b!=NULL
***********************************************/
iterador iteradorDaEncomendasBase(base b);

/***********************************************
daLotacaoBase - Retorna a lotação atual da base (soma de drones e encomendas).
Parâmetros: b - base da qual se quer obter a lotação
Retorno: lotação atual da base
Pre-condições: b!=NULL
***********************************************/
int daLotacaoBase(base b);

/***********************************************
daDroneBase - Retorna o drone na posição i da base.
Parâmetros: b - base da qual se quer obter o drone, i - índice do drone na base
Retorno: drone na posição i da base
Pre-condições: b!=NULL, i deve ser um índice válido
***********************************************/
drone daDroneBase(base b, int i);

/***********************************************
daEncomendasBase - Retorna a encomenda na posição i da base.
Parâmetros: b - base da qual se quer obter a encomenda, i - índice da encomenda na base
Retorno: encomenda na posição i da base
Pre-condições: b!=NULL, i deve ser um índice válido
***********************************************/
encomenda daEncomendasBase(base b, int i);

/***********************************************
cmdListagemBase - Lista todos os drones e encomendas presentes na base.
Parâmetros: b - base da qual se quer listar os drones e encomendas
Retorno:
Pre-condições: b!=NULL
***********************************************/
void cmdListagemBase(char *linha, base b);

#endif /* BASE_H_ */
