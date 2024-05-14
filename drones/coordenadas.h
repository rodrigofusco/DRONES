typedef struct _coordenadas *coordenadas;

coordenadas criaCoordenadas(int lat, int lon);

void destroiCoordenadas(coordenadas c);

int latCoordenadas(coordenadas c);

int lonCoordenadas(coordenadas c);

int distanciaCoordenadas(coordenadas c1, coordenadas c2, int velocidade);
