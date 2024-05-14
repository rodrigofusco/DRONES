/*
 * chaveString.c
 */

#include <stdlib.h>
#include <string.h>
#include "chaveString.h"

/* Estrutura de dados */
struct _chaveString{
	char *string;
};

chaveString criaChaveString(char *string) {
	chaveString ch = malloc(sizeof(struct _chaveString));
	if (ch == NULL) return NULL;
	ch->string = malloc(strlen(string)+1);
	if (ch->string == NULL) { free(ch); return NULL; }
	strcpy(ch->string, string);
	return ch;
}	

void destroiChaveString(chaveString ch){
	free(ch->string);
	free(ch);
}

char * valorChaveString(chaveString ch){
	return ch->string;
}

int comparaChavesString(chaveString ch1, chaveString ch2){
	return strcmp(ch1->string, ch2->string);
}

int dispersaoChavesString(chaveString ch, int dim){
	int num=0, comp=strlen(ch->string);
	for (int i=0 ; i<comp ; i++)
		num = num + ch->string[i];
	return num % dim;
}

