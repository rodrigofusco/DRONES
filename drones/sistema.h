typedef struct _sistema *sistema;

sistema criaSistema(void);
void destroiSistema(sistema s);

char *nomeBaseSistema(sistema s);

int tempoAvancaSistema(sistema s, int n);

