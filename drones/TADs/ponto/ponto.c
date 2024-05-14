/*
 * ponto.c
 */

#include <stdlib.h>
#include <math.h>
#include "ponto.h"

/* Estrutura de dados associada a um ponto */
struct _ponto{
	float abscissa;
	float ordenada;
};

/* Implementacao das funcoes associadas a um ponto */

/***********************************************
criaPonto - Criacao da instancia da estrutura associada a um ponto.
Parametros:
	x - abscissa do ponto
	y - ordenada do ponto
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
ponto criaPonto(float x, float y){
	ponto p = malloc(sizeof(struct _ponto));
	if (p == NULL)
		return NULL;
	p->abscissa = x;
	p->ordenada = y;
	return p;
}

/***********************************************
destroiPonto - Liberta a memoria ocupada pela instancia da estrutura associada ao ponto.
Parametros:
	p - ponto a destruir
Retorno:
Precondicoes: p != NULL
***********************************************/
void destroiPonto(ponto p){
	free(p);
}

/***********************************************
abscissaPonto - consulta da abscissa de um ponto dado.
Parametros:
	p - ponto
Retorno: abscissa do ponto
Precondicoes: p != NULL
***********************************************/
float abscissaPonto (ponto p){
	return p->abscissa;
}

/***********************************************
ordenadaPonto - consulta da ordenada de um ponto dado.
Parametros:
	p - ponto
Retorno: ordenada do ponto
Precondicoes: p != NULL
***********************************************/
float ordenadaPonto (ponto p){
	return p->ordenada;
}

/***********************************************
distanciaPontos - calcula a distancia entre dois pontos dados.
Parametros:
	p1 - ponto
	p2 - ponto
Retorno: distancia entre os pontos p1 e p2
Precondicoes: p1 != NULL && p2 != NULL
***********************************************/
float distanciaPontos (ponto p1, ponto p2){
	return sqrt(pow(p1->abscissa - p2->abscissa,2)+pow(p1->ordenada - p2->ordenada,2));
}




