/*
 * iterador.h
 */

#ifndef _H_ITERADOR
#define _H_ITERADOR

/* requer a inclusao previa de <stdbool.h> */

/* Tipo de dados: iterador */
typedef struct _iterador * iterador;

/* Prototipos das funcoes associadas a um iterador */

/***********************************************
criaIterador - Cria iterador
Parametros:
	vetorCopia - copia do vetor a iterar
	n - numero de elementos no vetor
Retorno: apontador para a instancia criada
Precondicoes: vetor != NULL && n >= 0
***********************************************/
iterador criaIterador(void ** vetorCopia, int n);

/***********************************************
destroiIterador - Liberta o iterador.
Parametros:
	it - iterador a destruir
Retorno:
Precondicoes: it != NULL
***********************************************/
void destroiIterador (iterador it);

/***********************************************
temSeguinteIterador - Indica se existe mais elementos para iterar no iterador.
Parametros:
	it - iterador
Retorno: true - caso exista mais elementos; false - caso contrario
Precondicoes: it != NULL
***********************************************/
bool temSeguinteIterador(iterador it);

/***********************************************
seguinteIterador - Consulta o elemento seguinte no iterador.
Parametros:
	it - iterador
Retorno: elemento
Precondicoes: it != NULL && temSeguinteIterador(it)
***********************************************/
void * seguinteIterador(iterador it);

/***********************************************
copiaVetor - Copia um vetor de apontadores.
Parametros:
	vetor - vetor a copiar
	n - número de elementos no vetor a copiar
Retorno: copia do vetor
Precondicoes: n >= 0
***********************************************/
void *copiaVetor(void *vetor, int n);

#endif /* _H_ITERATOR */
