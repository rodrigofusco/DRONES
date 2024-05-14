/*
 * filaVetor.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include "fila.h"

/* Estrutura de dados: fila ---> comportamento (Disciplina):
 * "Primeiro a chegar, Primeiro a sair" ou "First In First Out" (FIFO)
 * Elementos na fila sao de tipo "generico"
 */
struct _fila{
	void ** elems;
	int numElems;
	int capacidade;
	destroiFun destroi;
};

fila criaFila(int cap, destroiFun destroi){
	fila f = malloc(sizeof(struct _fila));
	if (f == NULL) return NULL;
	f->elems = malloc(sizeof(void *)*cap);
	if (f->elems == NULL){
		free(f);
		return NULL;
	}
	f->capacidade = cap;
	f->numElems = 0;
	f->destroi = destroi; /* guarda-se aqui, para quando for preciso usar */
	return f;
}


void destroiFila (fila f){
	free(f->elems);
	free(f);
}

void destroiFilaEElems(fila f){
	for (int i = 0; i < f->numElems; i++)
		f->destroi(f->elems[i]);
	free(f->elems);
	free(f);
}

bool vaziaFila(fila f){
	return f->numElems == 0;
}

int tamanhoFila(fila f){
	return f->numElems;
}

void * elementoFila(fila f){
	return f->elems[0];
}

void incFila (fila f){
	void ** aux = malloc(sizeof(void *) * f->capacidade*2); // duplica
	for (int i = 0; i < f->numElems; i++)
		aux[i] = f->elems[i];
	free(f->elems);
	f->elems = aux;
	f->capacidade = f->capacidade * 2;
}

void adicionaElemFila(fila f, void * elem){
	if (f->capacidade == f->numElems)
		incFila(f);
	f->elems[f->numElems++] = elem;
}

void * removeElemFila(fila f){
	void * aux = f->elems[0];
	f->numElems--;
	for (int i = 0; i < f->numElems; i++)
		f->elems[i] = f->elems[i+1];
	return aux;
}
