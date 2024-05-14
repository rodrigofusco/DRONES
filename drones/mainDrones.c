#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "TADs/iterador/iterador.h"

#include "sistema.h"
#include "drone.h"

#define MAX_LINHA	80


void invalido(void){
	printf("Dados invalidos\n");
}

void proibido(void){
	printf("Nao pode fazer isso\n");
}

/*
void txtColetivo(drone d, char *txt){
	char aux[MAX_LINHA];
	sprintf(txt, "%s", ""); // Limpa o array para garantir que começa vazio
	if (basicoDrone(d)) // verifica se é um dorne básico(pois o objetivo é drones coletivos)
		return;
	iterador it = iteradorColetivoDrone(d); // cria um iterador para correr os drones básicos
	sprintf(txt, ", elems=(");
	while (temSeguinteIterador(it)){
		drone d = seguinteIterador(it);		
		if (temSeguinteIterador(it))
			sprintf(aux, "%i ", idDrone(d));
		else
			sprintf(aux, "%i", idDrone(d));
		strcat(txt, aux);
	}
	strcat(txt, ")");
	destroiIterador(it);
}
*/
void txtDrone(_drone d, char *txt){
	char *cat = basicoDrone(d) ? "basico" : "coletivo";
	int id = idDrone(d);
	int cap = capacidadeCargaDrone(d);
	int alc = alcanceDrone(d);
	int alcD = alcanceDisponivelDrone(d);
	int voo = restoVooDrone(d);
	int man = restoManutencaoDrone(d);

	char aux[MAX_LINHA];
	//txtColetivo(d, aux);
	sprintf(txt, "drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d%s)",
		cat, id, cap, alcD, alc, voo, man, aux);
}


void cmdTempoAvanca(sistema s, char *linha){
	char ignora;
	int horas, extra;
	if (sscanf(linha,"%c %d %d", &ignora, &horas, &extra) != 2)
		{ invalido(); return; }
	horas = tempoAvancaSistema(s, horas);
	printf("O novo tempo e %d\n", horas);	
}

void cmdMenu(void){
	printf("Menu:\n");
	printf("  B - cria um novo drone Basico e regista-o na base\n");
	printf("  C - cria um novo drone Coletivo e regista-o na base\n");
	printf("  D - Despacha uma encomenda usando um drone\n");
	printf("  E - cria uma nova Encomenda\n");
	printf("  L - Lista drones e encomendas\n");
	printf("  R - Remove drone da base e destroi-o\n");
	printf("  T - avança o Tempo um dado numero de horas\n");
	printf("  ? - mostra os comandos disponíveis\n");
	printf("  . - finaliza a execução do programa\n");
}

void interpretador(sistema s){
	
	char linha[MAX_LINHA], cmd;
	do {
		printf("> ");
		if (fgets(linha, MAX_LINHA, stdin) == NULL){
			printf("\n");	// input terminou inopinadamente...
			break;
		}
		cmd = toupper(linha[0]);
		//printf("%s", linha);
		switch (cmd){
			case 'B':

				typedef struct _drone *_drone;     
				int _cap, _alc;

    				// Ler os valores da linha ignorando o primeiro caractere (o comando)
    				sscanf(linha + 1, "%d %d", &_cap, &_alc);
   					d->id++;
    				d->cap = _cap;
    				d->alc = _alc;

    			// Imprimir os valores para verificar se foram lidos corretamente
    			printf("ID: %d, Capacidade: %d, Alcance: %d\n\n", d->id, d->cap, d->alc);

    			break;

			case 'C':
				typedef struct _drone _drone;
				int nmr_drones[5],

				sscanf(linha + 1, "%d %d %d %d %d %d", &nmr_drones[0], &nmr_drones[1], &nmr_drones[2], &nmr_drones[3], &nmr_drones[4]);
			case 'T': cmdTempoAvanca(s, linha); break;
			case '?': cmdMenu(); break;
			case '.': break;
			case '\n': break;
			default: printf("Comando invalido\n"); break;
		}
	} while (cmd != '.');
	printf ("Obrigado. Volte sempre!\n");
}

int main(void){

	sistema s = criaSistema();
	interpretador(s);
	destroiSistema(s);
	//txtDrone(d, linha);
	//printf("%s", linha);
	return 0;
	
	
}


