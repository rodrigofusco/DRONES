/*mainDrones.c*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"

#include "base.h"
#include "sistema.h"
#include "drone.h"
#include "encomendas.h"
#include "coordenadas.h"

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

void txtDrone(drone d, char *txt){
	char *cat; //basicoDrone(d) ? "basico" : "coletivo";
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
*/

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

void interpretador(sistema s, base b, int *num_drones, int *num_encomendas){

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
				int cap, alc;

    			if(sscanf(linha + 1, "%d %d", &cap, &alc) != 2){
        			printf("Não pode fazer isso.\n");
					break;
    			}

				cmdBasicoDrone(linha, b, num_drones);
    			break;

			case 'C':
				int nmr_ids[5];

				if(sscanf(linha + 1, "%d %d %d %d %d %d", &nmr_ids[0], &nmr_ids[1], &nmr_ids[2], &nmr_ids[3], &nmr_ids[4], &nmr_ids[5]) < 2){
					printf("Não pode fazer isso.\n");
					break;
				}
				
				cmdColetivoDrone(linha, b, num_drones);
				break;

			case 'E':
				cmdBaseEncomenda(linha, b, num_encomendas);
				break;

			case 'L':
				cmdListagemBase(linha, b);
				break;
				
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
	//int cap = 0, alc = 0;
	char *nome = "WASD";
	sistema s = criaSistema();

	coordenadas c = criaCoordenadas(10,10);

	base b = criaBase(nome, c);

	int num_drones = 0;
	int num_encomendas = 1000;

	interpretador(s, b, &num_drones, &num_encomendas);
	
	destroiSistema(s);
	//txtDrone(d, linha);
	//printf("%s", linha);
	return 0;
	
	
}
