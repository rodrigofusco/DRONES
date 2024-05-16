#ifndef ENCOMENDAS_H_
#define ENCOMENDAS_H_

/* Tipo de dados: encomenda */
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

int idEncomenda(encomenda e);

int pesoEncomenda(encomenda e);

int latitudeEncomenda(encomenda e);

int longitudeEncomenda(encomenda e);

int criacaoEncomenda(encomenda e);

int saidaEncomenda(encomenda e);

int entregaEncomenda(encomenda e);

#endif /* ENCOMENDAS_H_ */
