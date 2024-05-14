/*
 * pilha.h
 */

#ifndef _H_PILHA
#define _H_PILHA

/* requer a inclusao previa de <stdbool.h> */

/* Tipo de dados: pilha
	- comportamento "Ultimo a chegar, Primeiro a sair" */
typedef struct _pilha * pilha;

typedef void (*destroiFun)(void *);

/* Prototipos das funcoes associadas a uma pilha */

/***********************************************
criaPilha - Criacao da instancia da estrutura associada a uma pilha.
Parametros:
	cap - capacidade prevista da pilha
	destroi - funcao de destruicao dos elementos, para quando for preciso usar
Retorno: apontador para a instancia criada
Precondicoes: cap >= 0
***********************************************/
pilha criaPilha(int cap, destroiFun destroi);

/***********************************************
destroiPilha - Liberta a memoria ocupada pela instancia da estrutura associada a pilha.
Parametros:
	p - pilha - pilha a destruir
Retorno:
Precondicoes: p != NULL
***********************************************/
void destroiPilha (pilha p);

/***********************************************
destroipilhaEElems - Liberta a memoria ocupada pela instancia da estrutura associada a pilha e os elementos.
Parametros:
	p - pilha a destruir	destroi - funcao para destruicao dos elementos
Retorno:
Precondicoes: p != NULL
***********************************************/
void destroiPilhaEElems(pilha p);

/***********************************************
vaziaPilha - Indica se a pilha esta vazia.
Parametros:
	p - pilha
Retorno: true - caso pilha vazia; false - caso contrario
Precondicoes: p != NULL
***********************************************/
bool vaziaPilha(pilha p);

/***********************************************
tamanhoPilha - Consulta o numero de elementos na pilha.
Parametros:
	p - pilha
Retorno: numero de elementos na pilha
Precondicoes: p != NULL
***********************************************/
int tamanhoPilha(pilha p);

/***********************************************
topoPilha - Retorna o elemento no topo.
Parametros:
	p - pilha
Retorno: retorna o elemento
Precondicoes: p != NULL && !vaziaPilha(p)
***********************************************/
void * topoPilha(pilha p);

/***********************************************
emPilha - Adiciona o elemento dado no topo.
Parametros:
	p - pilha
	elem - elemento
Retorno:
Precondicoes: p != NULL
***********************************************/
void emPilha(pilha p, void * elem);

/***********************************************
desemPilha - Remove o elemento a menos tempo na pilha (no topo).
Parametros:
	p - pilha
Retorno: retorna o elemento
Precondicoes: p != NULL && !vaziaPilha(p)
***********************************************/
void * desemPilha(pilha p);

#endif /* _H_PILHA */
