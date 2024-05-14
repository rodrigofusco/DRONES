/*
 * fila.h
 */

#ifndef _H_FILA
#define _H_FILA

/*** requer a inclusao previa de <stdbool.h> ***/

/* Tipo de dados: fila
	- comportamento "Primeiro a chegar, Primeiro a sair" */
typedef struct _fila * fila;

typedef void (*destroiFun)(void *);

/* Prototipos das funcoes associadas a uma fila */

/***********************************************
criaFila - Criacao duma fila.
Parametros:
	cap - capacidade prevista da fila
	destroi - funcao de destruicao dos elementos, para quando for preciso usar
Retorno: apontador para a fila criada
Precondicoes: cap >= 0
***********************************************/
fila criaFila(int cap, destroiFun destroi);

/**************************
destroiFila - Liberta a memoria ocupada pela instancia da estrutura associada a fila.
Parametros:
	f - fila a destruir
Retorno:
Precondicoes: f != NULL
***********************************************/
void destroiFila (fila f);

/***********************************************
destroiFilaEElems - Liberta a memoria ocupada pela instancia da estrutura associada a fila e os elementos.
Parametros:
	f - fila a destruir	destroi - funcao para destruicao dos elementos
Retorno:
Precondicoes: f != NULL
***********************************************/
void destroiFilaEElems(fila f);

/***********************************************
vaziaFila - Indica se a fila esta vazia.
Parametros:
	f - fila
Retorno: true - caso fila vazia; false - caso contrario
Precondicoes: f != NULL
***********************************************/
bool vaziaFila(fila f);

/***********************************************
tamanhoFila - Consulta o numero de elementos na fila.
Parametros:
	f - fila
Retorno: numero de elementos na fila
Precondicoes: f != NULL
***********************************************/
int tamanhoFila(fila f);

/***********************************************
elementoFila - Retorna o elemento ha mais tempo na fila.
Parametros:
f - fila
Retorno: retorna o elemento
Precondicoes: f != NULL && tamanhoFila(f) > 0
***********************************************/
void * elementoFila(fila f);

/***********************************************
adicionaElemFila - Adiciona o elemento dado na fila.
Parametros:
	f - fila
	elem - elemento
Retorno:
Precondicoes: f != NULL
***********************************************/
void adicionaElemFila(fila f, void * elem);

/***********************************************
removeElemFila - Remove o elemento a mais tempo na fila.
Parametros:
	f - fila
Retorno: retorna o elemento
Precondicoes: f != NULL && !vaziaFila(f)
***********************************************/
void * removeElemFila(fila f);

#endif /* _H_FILA */
