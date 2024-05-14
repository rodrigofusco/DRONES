/*
 * chaveString.h
 */

#ifndef _H_CHAVE_STRING
#define _H_CHAVE_STRING

/* Tipo de dados: chaveString */
typedef struct _chaveString * chaveString;

/* Prototipos das funcoes associadas a uma chaveString */

/***********************************************
criaChaveString - Criacao duma chave de tipo string.
Parametros:
	string - a string
Retorno: apontador para a instancia criada
Precondicoes: strlen(string) <= MAX_STRING
***********************************************/
chaveString criaChaveString(char *string);

/***********************************************
tipo destroiChaveString - Destroi chave.
Parametros:
	ch - chave a destruir
Precondicoes: ch != NULL
**********************************************/
void destroiChaveString(chaveString ch);

/***********************************************
tipo valorChaveString - Obtem a string duma chave.
Parametros:
	ch - chave
Retorno: a string guardada na chave
Precondicoes: ch != NULL
**********************************************/
char * valorChaveString(chaveString ch);

/***********************************************
comparaChavesString - Compara duas chaves.
Parametros:
	ch1 - chave1
	ch2 - chave2
Retorno: 0 - ch1 == ch2; -1 - ch1 < ch2; 1 - ch1 > ch2
Precondicoes: ch1 != NULL && ch2 != NULL
**********************************************/
int comparaChavesString(chaveString ch1, chaveString ch2);

/***********************************************
dispersaoChavesString - Retorna o valor associado a funcao de dispersao
aplicada a chave dada, numa tabela de dispersao com dimensao dada.
Parametros:
	chave - chave
	dim - dimensao da tabela de dispersao
Retorno: valor da funcao de dispersao (posicao na tabela de dispersao)
Precondicoes: chave != NULL && dim > 0
**********************************************/
int dispersaoChavesString(chaveString chave, int dim);

#endif /* _H_CHAVE_STRING */
