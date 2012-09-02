#ifndef AG_H_INCLUDED
#define AG_H_INCLUDED

#include "genotipo.h"
#include "operadores.h"
#include "seleccion.h"

#define TAM_POBLACION 50   /* tamano de la poblacion */

void inicializar(poblacion *pob, variable **var);
void copiar_genes(gen *desde, gen *hacia, int total_genes);
void evaluar(poblacion pob,double(*f)(double*));
void elitismo(poblacion pob);
void mantener_el_mejor(poblacion pob);
void generar_reporte(poblacion pob, int generacion);

#endif