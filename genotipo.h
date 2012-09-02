#ifndef GENOTIPO_H_INCLUDED
#define GENOTIPO_H_INCLUDED

typedef struct{
	double up_bound;
	double low_bound;
	int p;
} variable;

typedef struct{
	char *valor;
	variable *var;
} gen;

/*
 * Estructura que representa un individuo de la poblacion
 */
typedef struct{
	/*@{*/
	gen *genes;	/**< genes del individuo */
	/*@}*/
	/**
	* @name Fitness del indivudio
	*/
	/*@{*/
	double fitness;	   /**< fitness total */
  double nfitness;   /**< normalized fitness (para proportional selection) */
	double rfitness;   /**< relative fitness */
	double cfitness;   /**< cumulative fitness */
	/*@}*/
} genotipo;

typedef struct{
	genotipo *individuos;
	int tam_poblacion;
	int num_variables;
} poblacion;

#endif
