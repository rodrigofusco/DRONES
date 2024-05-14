/*
 * iteradorOrdenado.h
 */

#ifndef _H_ITERADOR_ORDENADO
#define _H_ITERADOR_ORDENADO

/* requer a inclusao previa de "iterador.h" */

/* nao introduz nenhum TAD novo */

typedef int (*comparaFun)(void * ch1, void * ch2); 

/***********************************************
criaIteradorOrdenado - Cria iterador ordenado
Parametros:
	vetorCopia - copia do vetor a iterar
	n - numero de elementos no vetor
	compara - funcao de comparacao de elementos
Retorno: apontador para a instancia criada
Precondicoes: vetor != NULL && n >= 0
***********************************************/
iterador criaIteradorOrdenado(void ** vetorCopia, int n, comparaFun compara);

#endif /* _H_ITERATOR_ORDENADO */
