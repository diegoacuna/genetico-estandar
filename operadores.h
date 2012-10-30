#ifndef OPERADORES_H_OPERADORES
#define OPERADORES_H_INCLUDED

#include "genotipo.h"

void mutacion(poblacion pob,double prob_mut);
void crossover(poblacion pob,double prob_cross);
void xover(gen *ind1, gen *ind2, poblacion pob);

#endif
