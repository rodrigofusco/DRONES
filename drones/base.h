/*base.h*/

#ifndef BASE_H_
#define BASE_H_

/*TAD´s usados*/
#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"

#include "base.h"
#include "sistema.h"
#include "drone.h"
#include "coordenadas.h"
/* Tipo de dados: base */
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

/*comentar*/
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
avancaUmaHoraBase - Avança o tempo da base em uma hora.
Parâmetros: b - base cujo tempo será avançado, tempo - número de horas a serem avançadas
Retorno:
Pre-condições: b!=NULL, tempo >= 0
***********************************************/
void avancaUmaHoraBase(base b, int tempo);

/*comentar*/
void adicionaDroneBase(base b, drone d);

sequencia sequenciaDrones(base b);
/*
iterador iteradorDaDroneBase(base b); // idk se e preciso
*/


#endif /*BASE_H_*/
