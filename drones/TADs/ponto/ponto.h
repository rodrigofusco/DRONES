/*
 * ponto.h
 */

#ifndef H_PONTO
#define H_PONTO

/* Tipo de dados: ponto */
typedef struct _ponto * ponto;

/* Prototipos das funcoes associadas a um ponto */

/***********************************************
criaPonto - Criacao da instancia da estrutura associada a um ponto.
Parametros:
	x - abscissa do ponto
	y - ordenada do ponto
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
ponto criaPonto(float x, float y);

/***********************************************
destroiPonto - Liberta a memoria ocupada pela instancia da estrutura associada ao ponto.
Parametros:
	p - ponto a destruir
Retorno:
Precondicoes: p != NULL
***********************************************/
void destroiPonto(ponto p);

/***********************************************
abscissaPonto - consulta da abscissa de um ponto dado.
Parametros:
	p - ponto
Retorno: abscissa do ponto
Precondicoes: p != NULL
***********************************************/
float abscissaPonto (ponto p);

/***********************************************
ordenadaPonto - consulta da ordenada de um ponto dado.
Parametros:
	p - ponto
Retorno: ordenada do ponto
Precondicoes: p != NULL
***********************************************/
float ordenadaPonto (ponto p);

/***********************************************
distanciaPontos - calcula a distancia entre dois pontos dados.
Parametros:
	p1 - ponto
	p2 - ponto
Retorno: distancia entre os pontos p1 e p2
Precondicoes: p1 != NULL && p2 != NULL
***********************************************/
float distanciaPontos (ponto p1, ponto p2);

#endif /* H_PONTO */
