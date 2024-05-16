#ifndef ENCOMENDAS_H_
#define ENCOMENDAS_H_

#include "base.h"

typedef struct _encomenda *encomenda;

/***********************************************
criaEncomenda - Cria uma instância da estrutura associada ao tipo encomenda.
Parâmetros: peso - peso da encomenda, lat - latitude do destino da encomenda, lon - longitude do destino da encomenda
Retorno: apontador para a instância criada
Pre-condições: peso > 0
***********************************************/
encomenda criaEncomenda(int peso, int lat, int lon);

/***********************************************
destroiEncomenda - Liberta a memória ocupada pela instância da estrutura associada ao tipo encomenda.
Parâmetros: e - encomenda a ser destruída
Retorno:
Pre-condições: e!=NULL
***********************************************/
void destroiEncomenda(encomenda e);

/***********************************************
cmdBaseEncomenda - Processa o comando para adicionar uma encomenda à base.
Parâmetros: linha - linha de comando com os parâmetros da encomenda, b - base à qual a encomenda será adicionada, num_encomendas - contador do número de encomendas
Retorno:
Pre-condições: linha!=NULL, b!=NULL, num_encomendas!=NULL
***********************************************/
void cmdBaseEncomenda(char *linha, base b, int *num_encomendas);

/***********************************************
idEncomenda - Obtém o ID da encomenda.
Parâmetros: e - encomenda da qual se quer obter o ID
Retorno: ID da encomenda
Pre-condições: e!=NULL
***********************************************/
int idEncomenda(encomenda e);

/***********************************************
pesoEncomenda - Obtém o peso da encomenda.
Parâmetros: e - encomenda da qual se quer obter o peso
Retorno: peso da encomenda
Pre-condições: e!=NULL
***********************************************/
int pesoEncomenda(encomenda e);

/***********************************************
latitudeEncomenda - Obtém a latitude do destino da encomenda.
Parâmetros: e - encomenda da qual se quer obter a latitude
Retorno: latitude do destino da encomenda
Pre-condições: e!=NULL
***********************************************/
int latitudeEncomenda(encomenda e);

/***********************************************
longitudeEncomenda - Obtém a longitude do destino da encomenda.
Parâmetros: e - encomenda da qual se quer obter a longitude
Retorno: longitude do destino da encomenda
Pre-condições: e!=NULL
***********************************************/
int longitudeEncomenda(encomenda e);

/***********************************************
criacaoEncomenda - Obtém o tempo de criação da encomenda.
Parâmetros: e - encomenda da qual se quer obter o tempo de criação
Retorno: tempo de criação da encomenda
Pre-condições: e!=NULL
***********************************************/
int criacaoEncomenda(encomenda e);

/***********************************************
saidaEncomenda - Obtém o tempo de saída da encomenda.
Parâmetros: e - encomenda da qual se quer obter o tempo de saída
Retorno: tempo de saída da encomenda
Pre-condições: e!=NULL
***********************************************/
int saidaEncomenda(encomenda e);

/***********************************************
entregaEncomenda - Obtém o tempo de entrega da encomenda.
Parâmetros: e - encomenda da qual se quer obter o tempo de entrega
Retorno: tempo de entrega da encomenda
Pre-condições: e!=NULL
***********************************************/
int entregaEncomenda(encomenda e);

#endif /* ENCOMENDAS_H_ */
