/*
 * chaveInt.h
 */

#ifndef _H_CHAVE_INT
#define _H_CHAVE_INT

/* Tipo de dados: chaveInt */
typedef struct _chaveInt * chaveInt;

/***********************************************
criaChaveInt - Criacao duma chave de tipo Int.
Parametros:
	i - o inteiro
Retorno: apontador para a instancia criada
***********************************************/
chaveInt criaChaveInt(int i);

/***********************************************
tipo destroiChaveInt - Destroi chave.
Parametros:
	ch - chave a destruir
Precondicoes: ch != NULL
**********************************************/
void destroiChaveInt(chaveInt ch);

/***********************************************
tipo valorChaveInt - Obtem o inteiro duma chave.
Parametros:
	ch - chave
Retorno: o inteiro guardado na chave
Precondicoes: ch != NULL
**********************************************/
int valorChaveInt(chaveInt ch);

/***********************************************
comparaChavesInt - Compara duas chaves.
Parametros:
	ch1 - chave1
	ch2 - chave2
Retorno: 0 - ch1 == ch2; -1 - ch1 < ch2; 1 - ch1 > ch2
Precondicoes: ch1 != NULL && ch2 != NULL
**********************************************/
int comparaChavesInt(chaveInt ch1, chaveInt ch2);

/***********************************************
dispersaoChaveInt - Retorna o valor associado a funcao de dispersao
aplicada a chave dada, numa tabela de dispersao com dimensao dada.
Parametros:
	chave - chave
	dim - dimensao da tabela de dispersao
Retorno: valor da funcao de dispersao (posicao na tabela de dispersao)
Precondicoes: chave != NULL && dim > 0
**********************************************/
int dispersaoChaveInt(chaveInt chave, int dim);

#endif /* _H_CHAVE_INT */
