#ifndef AG_H_INCLUDED
#define AG_H_INCLUDED

#include <matheval.h>
#include "genotipo.h"
#include "operadores.h"
#include "seleccion.h"

void inicializar(poblacion *pob, variable **var, char* instancia);
void copiar_genes(gen *desde, gen *hacia, int total_genes);
void evaluar(poblacion pob,void *f,int n_var,char **var_names);
void elitismo(poblacion pob);
void mantener_el_mejor(poblacion pob);
void generar_reporte(poblacion pob, int generacion);

#endif