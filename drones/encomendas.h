#ifndef ENCOMENDAS_H
#define ENCOMENDAS_H

typedef struct _encomenda *encomenda;

encomenda criaEncomenda(int peso, int lat, int lon, int tempoCriacao);
void destroiEncomenda(encomenda e);

int idEncomenda(encomenda e);
int pesoEncomenda(encomenda e);
int latitudeEncomenda(encomenda e);
int longitudeEncomenda(encomenda e);
int criacaoEncomenda(encomenda e);
int saidaEncomenda(encomenda e);
void defineSaidaEncomenda(encomenda e, int tempoSaida);
int entregaEncomenda(encomenda e);
void defineIdEncomenda(encomenda e, int id);

#endif // ENCOMENDAS_H
