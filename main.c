#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utilidades.h"
#include "ag.h"

#define MAX_GEN 500
#define PI      3.14159

/* FUNCION A OPTIMIZAR */
double f(double *x) 
{
	return 0.5 + ((sin(sqrt(x[1]*x[1] + x[0]*x[0])))*(sin(sqrt(x[1]*x[1] + x[0]*x[0]))) - 0.5)/(1+0.0001*(x[1]*x[1] + x[0]*x[0])*(x[1]*x[1] + x[0]*x[0]));
}

int main(int argc, char **argv)
{
	poblacion pob;
	variable *variables;
	
	int i,j,generaciones=0;
	
	srand(atoi(argv[1]));
  
  printf("SEED: %s;PROB_MUT: 0.01;PROB_CROSS: 0.25\n",argv[1]);

	inicializar(&pob,&variables);
	evaluar(pob,f);
	mantener_el_mejor(pob);
	while(generaciones<MAX_GEN)
	{
		generaciones++;
		proportional(pob);
		crossover(pob);
		mutacion(pob);
		generar_reporte(pob,generaciones);
		evaluar(pob,f);
		elitismo(pob);
	}
	
	printf("\nMEJOR INDIVIDUO FITNESS: ; %f\n",pob.individuos[pob.tam_poblacion].fitness);
  
  for(i=0;i<pob.num_variables;i++)
    printf("VALOR X%d: %f\n",i,binary_gen_to_double(pob.individuos[pob.tam_poblacion].genes[i]));
	
	free(variables);
	/*for(i=0;i<pob.tam_poblacion;i++)
	{
		for(j=0;j<pob.num_variables;j++)
			free(pob.individuos[i].genes[j].valor);
		free(pob.individuos[i].genes);
	}
	free(pob.individuos);*/
	
	return 0;
}
