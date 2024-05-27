#ifndef _SISTEMA_H_
#define _SISTEMA_H_

/* Tipo de dados: sistema */
typedef struct _sistema *sistema;

sistema criaSistema(void);

void destroiSistema(sistema s);
base daBaseSistema(sistema s);
char *nomeBaseSistema(sistema s);
int tempoSistema(sistema s);
int tempoAvancaSistema(sistema s, int n);

void BasicoDroneSistema(sistema s, int capacidade, int alcance, int *num_drones);
void EncomendasSistema(sistema s, int peso, int lat, int lon, int tempoCorrente, int *num_encomendas);
//void ColetivoDroneSistema(sistema s, int num_ids, int *num_drones);
drone ColetivoDroneSistema(sistema s, int *ids, int num_ids, int *num_drones);
int distanciaEncomendaSistema(sistema s, int id);
void tempoSaidaEncomenda(sistema s, int id, int tempoSaida);

#endif /* _SISTEMA_H_ */
