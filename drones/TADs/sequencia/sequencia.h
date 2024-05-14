/*
 * sequencia.h
 */

#ifndef _H_SEQUENCIA
#define _H_SEQUENCIA

/* requer a inclusao previa de <stdbool.h> */

/* Tipo de dados: sequencia
	- s0, s1, s2 ... */
typedef struct _sequencia * sequencia;

typedef void (*destroiFun)(void *);

/* Prototipos das funcoes associadas a uma sequencia */

/***********************************************
criaSequencia - Cria uma sequencia.
Parametros:
	cap - capacidade prevista da sequencia
	destroi - funcao de destruicao dos elementos, para quando for preciso usar
Retorno: apontador para a instancia criada
Precondicoes: cap >= 0
***********************************************/
sequencia criaSequencia(int cap, destroiFun destroi);

/***********************************************
destroiSequencia - Liberta a estrutura da sequencia.
Parametros:
	s - sequencia a destruir
Retorno:
Precondicoes: s != NULL
***********************************************/
void destroiSequencia (sequencia s);

/***********************************************
destroiSeqEElems - Liberta a estrutura da sequencia e os elementos.
Parametros:
	s - sequencia a destruir
Retorno:
Precondicoes: s != NULL
***********************************************/
void destroiSeqEElems(sequencia s);

/***********************************************
vaziaSequencia - Indica se a sequencia esta vazia.
Parametros:
	s - sequencia
Retorno: true - caso sequencia vazia; false - caso contrario
Precondicoes: s != NULL
***********************************************/
bool vaziaSequencia(sequencia s);

/***********************************************
tamanhoSequencia - Consulta o numero de elementos na sequencia.
Parametros:
	s - sequencia
Retorno: numero de elementos na sequencia
Precondicoes: s != NULL
***********************************************/
int tamanhoSequencia(sequencia s);

/***********************************************
elementoPosSequencia - Consulta o elemento i-esimo na sequencia.
Parametros:
	s - sequencia
	i - posicao na sequencia, conta a partir de 0
Retorno: elemento
Precondicoes: s != NULL && i>=0 && i<tamanhoSequencia(s)
***********************************************/
void * elementoPosSequencia(sequencia s, int i);

/***********************************************
adicionaPosSequencia - Adiciona o elemento dado na posicao i da sequencia.
Parametros:
	s - sequencia
	elem - elemento
	i - posicao na sequencia, conta a partir de 0
Retorno:
Precondicoes: s != NULL && i>=0 && i<tamanhoSequencia(s)+1
***********************************************/
void adicionaPosSequencia(sequencia s, void * elem, int i);

/***********************************************
removePosSequencia - Remove o elemento na posicao i da sequencia.
Parametros:
	s - sequencia
	i - posicao na sequencia, conta a partir de 0
Retorno: retorna o elemento
Precondicoes: s != NULL && i>=0 && i<tamanhoSequencia(s)
***********************************************/
void * removePosSequencia(sequencia s, int i);

/***********************************************
iteradorSequencia - Cria e devolve um iterador para a sequencia.
Parametros:
	s - sequencia
Retorno: iterador da sequencia
Precondicoes: s != NULL
***********************************************/
iterador iteradorSequencia(sequencia s);

#endif /* _H_SEQUENCIA */
