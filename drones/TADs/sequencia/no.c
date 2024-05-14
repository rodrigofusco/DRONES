/*
 * no.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include "no.h"

/* Tipo do TAD no */
struct _no{
	void * elem;
	struct _no * seguinte;
};

no criaNo(void * e, no seg){
	no aux = malloc(sizeof(struct _no));
	if (aux == NULL)
		return NULL;
	aux->elem = e;
	aux-> seguinte = seg;
	return aux;
}

void destroiNo(no n){
	free(n);
}

void atribuiElemNo(no n, void * e){
	n->elem = e;
}

void atribuiSegNo(no n, no seg){
	n->seguinte = seg;
}

void * elemNo(no n){
	return n->elem;
}

no segNo(no n){
	return n->seguinte;
}

