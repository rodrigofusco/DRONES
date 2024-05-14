/*
 * iteradorOrdenadoVetor.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include "iterador.h"
#include "iteradorOrdenado.h"

void troca(void **a, void **b){
    void * aux = *a;
    *a = *b;
    *b = aux;
}

void ** ordenacaoPorSelecao(void ** v, int n, comparaFun compara){
	for (int i=0; i < n-1; i++) {
		int minIdx = i;   // procura o minimo seguinte
		for (int j=i+1; j < n; j++) {
			if (compara(v[j], v[minIdx]) < 0)
				minIdx = j;
		}
		troca(&v[i], &v[minIdx]);
	}
	return v;
}

iterador criaIteradorOrdenado(void ** vetorCopia, int n, comparaFun compara){
	void ** v = ordenacaoPorSelecao(vetorCopia, n, compara);
	return criaIterador(v, n);
}
