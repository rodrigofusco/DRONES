typedef struct _base *base;

base criaBase(char *nome, coordenadas localizacao);
// cria base -> cria o drone

void destroiBase(base b);

char *nomeBase(base b);

void avancaUmaHoraBase(base b, int tempo);

