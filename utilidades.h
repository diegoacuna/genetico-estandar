#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include "genotipo.h"

double randval();
double randval_between(double smallNumber, double bigNumber);
double binary_gen_to_double(gen bin_gen);
void AvgVar(double x, double *mean, double *var);

#endif