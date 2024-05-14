/*
 * dicionario.h
 */

#ifndef _H_DICIONARIO
#define _H_DICIONARIO

/* requer a inclusao previa de <stdbool.h> */

/* Tipo de dados: dicionario
	- associa uma chave a cada elemento; as chaves nao podem ser repetidas */
typedef struct _dicionario * dicionario;

typedef int (*comparaFun)(void * ch1, void * ch2);
typedef void (*destroiFun)(void *obj);

/* Prototipos das funcoes associadas a um dicionario */

/***********************************************
criaDicionario - Criacao de um dicionario.
Parametros:
	cap - capacidade inicial do dicionario
	comparaChaves - funcao de comparacao de chaves
	destroiChave - funcao de destruicao de chaves 
	destroiElem - funcao de destruicao de elementos 
Retorno: apontador para a instancia criada
Precondicoes: cap >= 0
***********************************************/
dicionario criaDicionario(int cap, comparaFun comparaChaves, destroiFun destroiChave, destroiFun destroiElem);

/***********************************************
destroiDicionario - Liberta a memoria ocupada pelo dicionario.
Parametros:	d - dicionario a destruir
Retorno:
Precondicoes: d != NULL
***********************************************/
void destroiDicionario (dicionario d);

/***********************************************
destroiDicEElems - Liberta a memoria ocupada pelo dicionario e os seus elementos.
Parametros:
	d - dicionario a destruir
Retorno:
Precondicoes: d != NULL
***********************************************/
void destroiDicEElems(dicionario d);

/***********************************************
vazioDicionario - Testa se o dicionario esta vazio.
Parametros:
	d - dicionario
Retorno: true - caso dicionario vazio; false - caso contrario
Precondicoes: d != NULL
***********************************************/
bool vazioDicionario(dicionario d);

/***********************************************
tamanhoDicionario - Consulta o numero de elementos no dicionario.
Parametros:
	d - dicionario
Retorno: numero de elementos no dicionario
Precondicoes: d != NULL
***********************************************/
int tamanhoDicionario(dicionario d);

/***********************************************
existeElemDicionario - Indica se o elemento com a chave dada existe no dicionario.
Parametros:
	d - dicionario
	ch - chave do elemento
Retorno: retorna true se existir, e false, caso contrario
Precondicoes: d != NULL && ch != NULL
***********************************************/
bool existeElemDicionario(dicionario d, void * ch);

/***********************************************
elementoDicionario - retorna o elemento no dicionario com a chave dada
Parametros:
	d - dicionario
	ch - chave do elemento
Retorno: retorna o elemento
Precondicoes: d != NULL && ch != NULL
***********************************************/
void * elementoDicionario(dicionario d, void * ch);

/***********************************************
adicionaElemDicionario - Adiciona o elemento dado no dicionario, se nao existir um elemento com a mesma chave.
Parametros:
	d - dicionario
	ch - chave do elemento
	elem - elemento
Retorno: Retorna true se adicionar, e false caso contrario
Precondicoes: d != NULL && ch != NULL && elem != NULL
***********************************************/
bool adicionaElemDicionario(dicionario d, void * ch, void * elem);

/***********************************************
removeElemDicionario - Remove o elemento com a chave dada no dicionario, se existir.
Parametros:
	d - dicionario
	ch - chave
Retorno: Retorna o elemento, caso exista ou NULL, caso contrario
Precondicoes: d != NULL && ch != NULL
***********************************************/
void * removeElemDicionario(dicionario d, void * ch);

/***********************************************
iteradorDicionario - Cria um iterador para os elementos do dicionario.
Parametros:
d - dicionario
Retorno: iterador dos elementos
Precondicoes: d != NULL
***********************************************/
iterador iteradorDicionario(dicionario d);

/***********************************************
iteradorChavesDicionario - Cria um iterador para as chaves do dicionario.
Parametros: d - dicionario
Retorno: iterador das chaves
Precondicoes: d != NULL
***********************************************/
iterador iteradorChavesDicionario(dicionario d);

/***********************************************
iteradorOrdenadoChavesDicionario - Cria um iterador ordenado para as chaves do dicionario.
Parametros: d - dicionario
Retorno: iterador ordenado das chaves
Precondicoes: d != NULL
***********************************************/
iterador iteradorOrdenadoChavesDicionario(dicionario d);

#endif /* _H_DICIONARIO */
