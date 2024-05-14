/*
 * no.h
 */

#ifndef _H_NO
#define _H_NO

/* requer a inclusao previa de <stdbool.h> */

/* Tipo de dados: no */
typedef struct _no * no;

/* Prototipos das funcoes associadas a um no - TAD no */

/***********************************************
criaNo - Cria um no
Parametros:
	e - elemento a guardar no no (void *)
	seg - no seguinte
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
no criaNo(void * e, no seg);

/***********************************************
destroiNo - Liberta o no
Parametros:
	n - no a destruir
Retorno:
Precondicoes: n != NULL
***********************************************/
void destroiNo(no n);

/***********************************************
atribuiElemNo - Guarda o elemento dado no no
Parametros:
	n - no
	e - elemento (void *)
Retorno:
Precondicoes: n != NULL
***********************************************/
void atribuiElemNo(no n, void * e);

/***********************************************
atribuiSegNo - Guarda o no seguinte
Parametros:
	n - no
	seg - no seguinte
Retorno:
Precondicoes: n != NULL
***********************************************/
void atribuiSegNo(no n, no seg);

/***********************************************
elemNo - Retorna o elemento do no dado.
Parametros:
	n - no
Retorno: elemento (void *)
Precondicoes: n != NULL
***********************************************/
void * elemNo(no n);

/***********************************************
segNo - Retorna o no seguinte
Parametros:
	n - no
Retorno: no seguinte
Precondicoes: n != NULL
***********************************************/
no segNo(no n);

#endif /* _H_NO */
