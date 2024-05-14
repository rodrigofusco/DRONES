/*
 * pilhaVetor.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include "pilha.h"

/* Estrutura de dados: pilha ---> comportamento "Ultimo a chegar, Primeiro a sair" */
struct _pilha{
	void ** elems;
	int numElems;
	int capacidade;
	destroiFun destroi;
};

pilha criaPilha(int cap, destroiFun destroi){
	pilha p = malloc(sizeof(struct _pilha));
	if (p == NULL) return NULL;
	p->elems = malloc(sizeof(void *)*cap);
	if (p->elems == NULL){
		free(p);
		return NULL;
	}
	p->capacidade = cap;
	p->numElems = 0;
	p->destroi = destroi; /* guarda-se aqui, para quando for preciso usar */
	return p;
}

void destroiPilha (pilha p){
	free(p->elems);
	free(p);
}

void destroiPilhaEElems(pilha p){
	for (int i = 0; i < p->numElems; i++)
		p->destroi(p->elems[i]);
	free(p->elems);
	free(p);
}

bool vaziaPilha(pilha p){
	return p->numElems == 0;
}

int tamanhoPilha(pilha p){
	return p->numElems;
}

void * topoPilha(pilha p){
	return p->elems[p->numElems-1];
}

void incPilha (pilha p){
	void ** aux = malloc(sizeof(void *) * p->capacidade*2); // duplica
	for (int i = 0; i < p->numElems; i++)
		aux[i] = p->elems[i];
	free(p->elems);
	p->elems = aux;
	p->capacidade = p->capacidade * 2;
}

void emPilha(pilha p, void * elem){
	if (p->numElems == p->capacidade)
		incPilha(p);
	p->elems[p->numElems++] = elem;
}

void * desemPilha(pilha p){
	p->numElems--;
	return p->elems[p->numElems];
}

