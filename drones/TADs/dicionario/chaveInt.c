/*
 * chaveInt.c
 */

#include <stdlib.h>
#include <string.h>

#include "chaveInt.h"

/* Estrutura de dados */
struct _chaveInt{
	int i;
};

chaveInt criaChaveInt(int i){
	chaveInt ch = malloc(sizeof(struct _chaveInt));
	if (ch == NULL) return NULL;
	ch->i = i;
	return ch;
}	

void destroiChaveInt(chaveInt ch){
	free(ch);
}

int valorChavesInt(chaveInt ch){
	return ch->i;
}

int comparaChavesInt(chaveInt ch1, chaveInt ch2){
	if (ch1->i == ch2->i) return 0;
	else if (ch1->i < ch2->i) return -1;
	else return 1;
}

int dispersaoChaveInt(chaveInt ch, int dim){
	return ch->i % dim;
}

