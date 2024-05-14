#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "TADs/iterador/iterador.h"

#include "coordenadas.h"
#include "base.h"
#include "sistema.h"

#define TEMPO_ORIGEM	0

struct _sistema{
	base base;
	int tempoCorrente;
};

#include <stdio.h>

sistema criaSistema(){
	sistema s = malloc(sizeof(struct _sistema));
	if (s == NULL) return NULL;
   
	s->base = criaBase("FCT", criaCoordenadas(0,0));
	if (s->base == NULL) { free(s); return NULL;}
	
	s->tempoCorrente = TEMPO_ORIGEM;
	return s;
}

void destroiSistema(sistema s){
	destroiBase(s->base);
	free(s);
}

char *nomeBaseSistema(sistema s){
	return nomeBase(s->base);
}

int tempoAvancaSistema(sistema s, int n){
	for (int i = 0; i < n; i++){
		avancaUmaHoraBase(s->base, ++s->tempoCorrente);
	}
	return s->tempoCorrente;
}

