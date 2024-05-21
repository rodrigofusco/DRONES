#ifndef _SISTEMA_H_
#define _SISTEMA_H_

/* Tipo de dados: sistema */
typedef struct _sistema *sistema;

sistema criaSistema(void);

void destroiSistema(sistema s);
base daBaseSistema(sistema s);
char *nomeBaseSistema(sistema s);

int tempoAvancaSistema(sistema s, int n);

void BasicoDroneSistema(sistema s, int capacidade, int alcance, int *num_drones);
void EncomendasSistema(sistema s, int peso, int lat, int lon, int *num_encomendas);
//void ColetivoDroneSistema(sistema s, int num_ids, int *num_drones);
drone ColetivoDroneSistema(sistema s, int *ids, int num_ids, int *num_drones);

#endif /* _SISTEMA_H_ */
