/*
 * iteradorVetor.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include "iterador.h"

/* Estrutura de dados do tipo de dados: iterador (generico) */
struct _iterador{
	void ** vetorCopia;
	int numElems;
	int corrente;
};

iterador criaIterador(void ** vetorCopia, int n){
	iterador it = malloc(sizeof(struct _iterador));
	if (it == NULL) return NULL;
	it->vetorCopia = vetorCopia;
	it->numElems = n;
	it->corrente = 0;
	return it;
}

void destroiIterador (iterador it){
	free(it->vetorCopia);
	free(it);
}

bool temSeguinteIterador(iterador it){
	return it->corrente != it->numElems;
}

/* precondicao: temSeguinteIterador(it) */
void * seguinteIterador(iterador it){
	return it->vetorCopia[it->corrente++];
}

void *copiaVetor(void *vetor, int n){
	void **original = vetor;
	void **copia = malloc(sizeof(void *) * n);
	for (int i = 0 ; i < n ; i++) {
		copia[i] = original[i];
	}
	return copia;
}

