#ifndef _SISTEMA_H_
#define _SISTEMA_H_

/* Tipo de dados: sistema */
typedef struct _sistema *sistema;

/* Protótipos das funções associadas a um sistema */

/***********************************************
criaSistema - Cria uma instância do sistema.
Retorno: Um ponteiro para a instância criada do sistema
Precondições: Nenhuma
***********************************************/
sistema criaSistema(void);

/***********************************************
destroiSistema - Libera a memória alocada para uma instância do sistema.
Parametros:
    s - O sistema a ser destruído
Retorno: Nenhum
Precondições: O sistema não deve ser NULL
***********************************************/
void destroiSistema(sistema s);

/***********************************************
nomeBaseSistema - Obtém o nome da base associada ao sistema.
Parametros:
    s - O sistema
Retorno: O nome da base associada ao sistema
Precondições: O sistema não deve ser NULL
***********************************************/
char *nomeBaseSistema(sistema s);

/***********************************************
tempoAvancaSistema - Avança o tempo do sistema em um número específico de horas.
Parametros:
    s - O sistema
    n - O número de horas a avançar
Retorno: O novo tempo corrente do sistema
Precondições: O sistema não deve ser NULL
***********************************************/
int tempoAvancaSistema(sistema s, int n);

#endif /* _SISTEMA_H_ */
