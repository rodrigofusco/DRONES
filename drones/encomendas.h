
/*encomendas.h*/

#ifndef ENCOMENDAS_H_
#define ENCOMENDAS_H_



/* Tipo de dados: encomendas */
typedef struct _encomenda *encomenda;

/*coemntar*/
encomenda criaEncomenda(int peso, coordenadas destino);

/*encomendas*/
void destroiEncomenda(encomenda e);

void cmdBaseEncomenda(char *linha, encomenda e, int *num_encomendas);

#endif /*ENCOMENDAS_H_*/
