#ifndef SELECCION_H_INCLUDED
#define SELECCION_H_INCLUDED

#include "genotipo.h"

int comparar(const void *arg1, const void *arg2);
void ranking(poblacion pob);
void tournament(poblacion pob);
void proportional(poblacion pob);

#endif
