#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "TADs/iterador/iterador.h"

#include "coordenadas.h"
#include "base.h"

#define CAP	100

// DRONE BASE
struct _base{
	char *nome;
	coordenadas localizacao;
	int tempo;//horas
	
};

base criaBase(char *nome, coordenadas localizacao){
	base b = malloc(sizeof(struct _base));
	if (b == NULL) return NULL;
	b->nome = strcpy(malloc(sizeof(nome)+1), nome);
	b->localizacao = localizacao;
	// Fazer
	return b;
}

void destroiBase(base b){
	// Fazer
	destroiCoordenadas(b->localizacao);
	free(b->nome);
	free(b);
}

char *nomeBase(base b){
	return b->nome;
}

coordenadas localizacaoBase(base b){
	return b->localizacao;
}

void avancaUmaHoraBase(base b, int tempo){

	b->tempo += tempo;

}

