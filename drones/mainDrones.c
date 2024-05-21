/* mainDrones.c */

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

#define MAX_LINHA 80
#define MAX_ELEMS_COLETIVO 6

void invalido(void){
    printf("Dados invalidos\n");
}

void proibido(void){
    printf("Nao pode fazer isso\n");
}

void cmdTempoAvanca(char *linha, sistema s){
    char ignora;
    int horas, extra;
    if (sscanf(linha,"%c %d %d", &ignora, &horas, &extra) != 2) { 
        invalido(); 
        return; 
    }

    if(horas < 0){
        invalido();
    } else {
        horas = tempoAvancaSistema(s, horas);
        printf("O novo tempo e' %d\n", horas);    
    }
}

void txtDroneB(drone d, char *txt){
    char *cat = "basico";
    int id = idDrone(d);
    int cap = capacidadeCargaDrone(d);
    int alc = alcanceDrone(d);
    int alcD = alcanceDisponivelDrone(d);
    int voo = restoVooDrone(d);
    int man = restoManutencaoDrone(d);

    char aux[MAX_LINHA] = "";
    sprintf(txt, "drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d%s)",
        cat, id, cap, alcD, alc, voo, man, aux);
}

void txtDroneC(drone d, char *txt, int *elems, int num_elems) {
    char *cat = "coletivo";
    int id = idDrone(d);
    int cap = capacidadeCargaDrone(d);
    int alc = alcanceDrone(d);
    int alcD = alcanceDisponivelDrone(d);
    int voo = restoVooDrone(d);
    int man = restoManutencaoDrone(d);

    sprintf(txt, "drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d, elems=(",
        cat, id, cap, alcD, alc, voo, man);
    
    for (int i = 0; i < num_elems; i++) {
        if (i > 0) sprintf(txt + strlen(txt), " ");
        sprintf(txt + strlen(txt), "%d", elems[i]);
    }
    sprintf(txt + strlen(txt), "))");
}

void txtEncomenda(encomenda e, char *txt){
    int id = idEncomenda(e);
    int peso = pesoEncomenda(e);
    int lat = latitudeEncomenda(e);
    int lon = longitudeEncomenda(e);
    int cria = criacaoEncomenda(e);
    int saida = saidaEncomenda(e);
    int entrega = entregaEncomenda(e);

    sprintf(txt, "encomenda(id=%d, peso=%d, coord=(%d,%d), cria=%d, saida=%d, entrega=%d)",
        id, peso, lat, lon, cria, saida, entrega);
}

void cmdBasicoDrone(char *linha, sistema s, int *num_drones) {
    int cap, alc;
    char extra;
    if (sscanf(linha + 1, "%d %d %c", &cap, &alc, &extra) != 2) {
        invalido();
        return;
    }
    if (cap < 0 || alc < 0) {
        invalido();
        return;
    }
            
    BasicoDroneSistema(s, cap, alc, num_drones);
    
    // Obter a lista de drones básicos
    base b = daBaseSistema(s);
    sequencia db = sequenciaDronesBasicosBase(b);
    
    // Acessar o último drone na lista de drones básicos
    drone novo_drone = elementoPosSequencia(db, tamanhoSequencia(db) - 1);
    
    if (novo_drone) {
        char txt[MAX_LINHA];
        txtDroneB(novo_drone, txt);
        printf("Adicionado %s\n", txt);
    }
}

void cmdBaseEncomenda(char *linha, sistema s, int *num_encomendas) {
    int peso = 0, lat = 0, lon = 0;
    sscanf(linha + 1, "%d %d %d", &peso, &lat, &lon);
    if(peso <0){
        invalido();
    }
    else{
    EncomendasSistema(s, peso, lat, lon, num_encomendas);
    encomenda nova_encomenda = daEncomendasBase(daBaseSistema(s), *num_encomendas - 1002);

        if (nova_encomenda) {
            char txt[MAX_LINHA];
            txtEncomenda(nova_encomenda, txt);
            printf("Adicionada %s\n", txt);
        }
    }
}

void cmdColetivoDrone(char *linha, sistema s, int *num_drones) {
    int ids[MAX_ELEMS_COLETIVO];
    int num_ids = 0;
    char *token = strtok(linha + 1, " ");

    while (token != NULL) {
        int id = atoi(token); // se token = 123 transforma em int n = 123

        if(token[0] == '\n'){ // caso se escreva so "c"
            drone novo_drone = ColetivoDroneSistema(s, ids, num_ids, num_drones);

            if (novo_drone) {
                char txt[MAX_LINHA];
                int *elems = elementosDroneColetivo(novo_drone);
                int num_elems = tamanhoElementosDroneColetivo(novo_drone);
                txtDroneC(novo_drone, txt, elems, num_elems);
                printf("Adicionado %s\n", txt);
            }        
            return;
        }
        if (id < 0 || num_ids >= MAX_ELEMS_COLETIVO) { // c -1  ou c 1 2 3 4 5 6 7
            invalido();
            return;
        }
        if (strcmp(token, "0") == 0 || idDuplicadoNaBase(daBaseSistema(s), id)) { // c 0  ou coletivo no coletivo
            proibido();
            return;
        }
        ids[num_ids++] = id;
        token = strtok(NULL, " ");
    }

    if (num_ids < 1) {
        invalido();
        return;
    }

    base b = daBaseSistema(s);
    for (int i = 0; i < num_ids; i++) {
        if (!droneExisteNaBase(b, ids[i])) {
            proibido();
            return;
        }
    }

    drone novo_drone = ColetivoDroneSistema(s, ids, num_ids, num_drones);

    if (novo_drone) {
        char txt[MAX_LINHA];
        int *elems = elementosDroneColetivo(novo_drone);
        int num_elems = tamanhoElementosDroneColetivo(novo_drone);
        txtDroneC(novo_drone, txt, elems, num_elems);
        printf("Adicionado %s\n", txt);
    }
}




void cmdListagem(char *linha, sistema s) {
    base b = daBaseSistema(s);
    sequencia db = sequenciaDronesBasicosBase(b);
    sequencia e = sequenciaEncomendasBase(b);
    int numDronesB = tamanhoSequencia(db);
    int numEncomendas = tamanhoSequencia(e);

        char txt[MAX_LINHA];

        for (int i = 0; i < numDronesB; i++) {
            drone droneb = elementoPosSequencia(db, i);
            if(strcmp(categoriaDrone(droneb),"basico")==0){
                txtDroneB(droneb, txt);
                printf("%s\n", txt);
            }else{
                int *elems = elementosDroneColetivo(droneb);
                txtDroneC(droneb, txt, elems, droneb->numElementos);
                printf("%s\n", txt);
            }
        }
        for (int i = 0; i < numEncomendas; i++) {
            encomenda enc = elementoPosSequencia(e, i);
            txtEncomenda(enc, txt);
            printf("%s\n", txt);
        }

        if(numDronesB == 0 && numEncomendas == 0){
            printf("Nao existem drones nem encomendas\n");
        }
}

void cmdRemoveDrone(char *linha, sistema s){
    int id;
    base b = daBaseSistema(s);
    if ( sscanf(linha + 1, "%d", &id) != 1 || !droneExisteNaBase(b, id) || droneBasicoEmColetivo(b, id)) {
        invalido();
        return;
    }
    removeDroneBase(b, id);
    printf("Drone com id %d removido\n", id);

}

void cmdMenu(void){
    printf("Menu:\n");
    printf("  B - cria um novo drone Basico e regista-o na base\n");
    printf("  C - cria um novo drone Coletivo e regista-o na base\n");
    printf("  D - Despacha uma encomenda usando um drone\n");
    printf("  E - cria uma nova Encomenda\n");
    printf("  L - Lista drones e encomendas\n");
    printf("  R - Remove drone da base e destroi-o\n");
    printf("  T - avanca o Tempo um dado numero de horas\n");
    printf("  ? - mostra os comandos disponiveis\n");
    printf("  . - finaliza a execucao do programa\n");
}

void interpretador(sistema s, int *num_drones, int *num_encomendas){
    char linha[MAX_LINHA], cmd;
    do {
        printf("> ");
        if (fgets(linha, MAX_LINHA, stdin) == NULL){
            printf("\n");    
            break;
        }
        cmd = toupper(linha[0]);
        switch (cmd){
            case 'B': {
                cmdBasicoDrone(linha, s, num_drones);
                break;
            }
            case 'C': {
                cmdColetivoDrone(linha, s, num_drones);
                break;
            }

            case 'E': {
                int peso, lat, lon;
                char extra;
                if (sscanf(linha + 1, "%d %d %d %c", &peso, &lat, &lon, &extra) != 3) {
                    invalido(); 
                    break;
                } else {
                    cmdBaseEncomenda(linha, s, num_encomendas);
                    break;
                }
            }
            
            case 'L': cmdListagem(linha, s); break;
            case 'T': cmdTempoAvanca(linha, s); break;
            case 'R': cmdRemoveDrone(linha, s); break;
            case '?': cmdMenu(); break;
            case '.': break;
            case '\n': break;
            default: printf("Comando desconhecido\n"); break;
        }
    } while (cmd != '.');
    printf ("Obrigado. Volte sempre!\n");
}

int main(void){
    
    sistema s = criaSistema();
    int num_drones = 0;
    int num_encomendas = 1001;

    interpretador(s, &num_drones, &num_encomendas);
    
    destroiSistema(s);
    return 0;
}
