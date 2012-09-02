#ifndef OPERADORES_H_OPERADORES
#define OPERADORES_H_INCLUDED

#include "genotipo.h"

#define PROB_MUT   0.01
#define PROB_CROSS 0.25

void mutacion(poblacion pob);
void crossover(poblacion pob);
void xover(gen *ind1, gen *ind2, poblacion pob);

#endif
