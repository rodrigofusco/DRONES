/*
 * sequenciaVetor.c
 */

#include <stdbool.h>
#include <stdlib.h>

#include "../iterador/iterador.h"
#include "sequencia.h"

/* Estrutura de dados: sequencia implementada em vetor */
struct _sequencia{
	void ** elems;
	int numElems;
	int capacidade;
	destroiFun destroi;
};

sequencia criaSequencia(int cap, destroiFun destroi){
	sequencia s = malloc(sizeof(struct _sequencia));
	if (s == NULL)
		return NULL;
	s->elems = malloc(sizeof(void *) * cap);
	if (s->elems == NULL) {
		free(s);
		return NULL;
	}
	s->numElems = 0;
	s->capacidade = cap;
	s->destroi = destroi; /* guarda-se aqui, para quando for preciso usar */
	return s;
}

void destroiSequencia (sequencia s){
	free(s->elems);
	free(s);
}

void destroiSeqEElems(sequencia s){
	for (int i=0 ; i< s->numElems; i++)
		s->destroi(s->elems[i]);
	free(s->elems);
	free(s);
}

bool vaziaSequencia(sequencia s){
	return s->numElems == 0;
}


int tamanhoSequencia(sequencia s){
	return s->numElems;
}

void * elementoPosSequencia(sequencia s, int i){
	return s->elems[i];
}

void incCapacidadeSequencia (sequencia s){
	void ** aux = malloc(sizeof(void *) * s->capacidade*2); // duplica
	for (int i=0; i<s->numElems; i++)
		aux[i] = s->elems[i];
	free(s->elems);
	s->elems = aux;
	s->capacidade = s->capacidade * 2;
}

void adicionaPosSequencia(sequencia s, void * elem, int i){
	if( s->capacidade == s->numElems)
		incCapacidadeSequencia(s);
	for (int k=s->numElems-1; k>=i ; k--)
		s->elems[k+1] = s->elems[k];
	s->elems[i] = elem;
	s->numElems++;
}

void * removePosSequencia(sequencia s, int i){
	void * aux = elementoPosSequencia(s, i);
	for (int k=i+1; k < s->numElems; k++)
		s->elems[k-1] = s->elems[k];
	s->numElems--;
	return aux;
}

iterador iteradorSequencia(sequencia s){
	return criaIterador(copiaVetor(s->elems, s->numElems), s->numElems);
}
