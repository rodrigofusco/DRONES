/*
 * dicionarioVetor.c
*/

#include <stdbool.h>
#include <stdlib.h>

#include "../iterador/iterador.h"
#include "../iterador/iteradorOrdenado.h"
#include "../dicionario/dicionario.h"

/* Estrutura de dados do tipo de dados: dicionario ---> as chaves nao podem ser repetidas */
struct _dicionario{
	void ** chaves;	/* vetor das chaves */
	void ** elems;	/* vetor dos elementos */
	int numElems;
	int capacidade;
	comparaFun comparaChaves;
	destroiFun destroiChave, destroiElem;
};

dicionario criaDicionario(int cap, comparaFun comparaChaves, destroiFun destroiChave, destroiFun destroiElem) {
	dicionario d = malloc(sizeof(struct _dicionario));
	if (d == NULL) return NULL;
	d->chaves = malloc(sizeof(void *) * cap);
	if (d->chaves == NULL) { free(d); return NULL; }	
	d->elems = malloc(sizeof(void *) * cap);
	if (d->elems == NULL) { free(d); free(d->chaves); return NULL; }
	d->numElems = 0;
	d->capacidade = cap;
	d->comparaChaves = comparaChaves;
	d->destroiChave = destroiChave;
	d->destroiElem = destroiElem;
	return d;
}

void destroiDicionario (dicionario d){
	for (int i = 0; i < d->numElems; i++)
		d->destroiChave(d->chaves[i]);
	free(d->chaves);
	free(d->elems);
	free(d);
}

void destroiDicEElems(dicionario d){
	for (int i = 0; i < d->numElems; i++){
		d->destroiChave(d->chaves[i]);
		d->destroiElem(d->elems[i]);
	}
	free(d->chaves);
	free(d->elems);
	free(d);
}

bool vazioDicionario(dicionario d){
	return d->numElems == 0;
}

int tamanhoDicionario(dicionario d){
	return d->numElems;
}

int posElemDicionario(dicionario d, void * ch){
	for (int i = 0; i < d->numElems; i++)
		if (d->comparaChaves(ch, d->chaves[i]) == 0)
			return i;
	return -1;
}

bool existeElemDicionario(dicionario d, void * ch){
	return posElemDicionario(d, ch) != -1;
}

void * elementoDicionario(dicionario d, void * ch){
	int pos = posElemDicionario(d, ch);
	if (pos != -1)
		return d->elems[pos];
	return NULL;
}

void incDicionario (dicionario d){
	void ** chaves2 = malloc(sizeof(void *) * d->capacidade*2); // duplica
	void ** elems2 = malloc(sizeof(void *) * d->capacidade*2); // duplica
	for (int i = 0; i < d->numElems; i++) {
		chaves2[i] = d->chaves[i];
		elems2[i] = d->elems[i];
	}
	free(d->chaves);
	free(d->elems);
	d->chaves = chaves2;
	d->elems = elems2;
	d->capacidade = d->capacidade * 2;
}

bool adicionaElemDicionario(dicionario d, void * ch, void * elem){
	int pos = posElemDicionario(d,ch);
	if (pos != -1)
		return false;
	if (d->numElems == d->capacidade)
		incDicionario(d);
	d->chaves[d->numElems] = ch;
	d->elems[d->numElems++] = elem;
	return true;
}

void * removeElemDicionario(dicionario d, void * ch){
	void * elem;
	int pos = posElemDicionario(d,ch);
	if (pos == -1)
		return NULL;
	elem = d->elems[pos];
	d->destroiChave(d->chaves[pos]);
	d->numElems--;
	d->chaves[pos] = d->chaves[d->numElems];
	d->elems[pos] = d->elems[d->numElems];
	return elem;
}

iterador iteradorDicionario(dicionario d){
	void **v = copiaVetor(d->elems, d->numElems);
	return criaIterador(v, d->numElems);
}

iterador iteradorChavesDicionario(dicionario d){
	void **v = copiaVetor(d->chaves, d->numElems);
	return criaIterador(v, d->numElems);
}

iterador iteradorOrdenadoChavesDicionario(dicionario d){
	void **v = copiaVetor(d->chaves, d->numElems);
	return criaIteradorOrdenado(v, d->numElems, d->comparaChaves);
}
