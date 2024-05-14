#include <stdlib.h>
#include <math.h>

#include "coordenadas.h"

struct _coordenadas{
	int lat;
	int lon;
};

coordenadas criaCoordenadas(int lat, int lon){
	coordenadas c = malloc(sizeof(struct _coordenadas));
	if (c == NULL) return NULL;
	c->lat = lat;
	c->lon = lon;
	return c;
}

void destroiCoordenadas(coordenadas c){
	free(c);
}

int latCoordenadas(coordenadas c){
	return c->lat;
}

int lonCoordenadas(coordenadas c){
	return c->lon;
}

int distanciaCoordenadas(coordenadas c1, coordenadas c2, int velocidade){
        int dLat = c1->lat - c2->lat;
        int dLon = c1->lon - c2->lon;
        int dist = ceil(sqrt(dLat * dLat + dLon * dLon));
        return ((dist + velocidade - 1)/velocidade) * velocidade;
}
