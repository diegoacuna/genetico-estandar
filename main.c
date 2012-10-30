#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "utilidades.h"
#include "ag.h"
#include "cmdline.h"

#define MAX_GEN 500
#define PI      3.14159

struct gengetopt_args_info params;

/* FUNCION A OPTIMIZAR */
double f(double *x) 
{
	return 1+(((x[0]*x[0])/4000)+((x[1]*x[1])/4000)+((x[2]*x[2])/4000)+((x[3]*x[3])/4000)+((x[4]*x[4])/4000)+((x[5]*x[5])/4000)+
		((x[6]*x[6])/4000)+((x[7]*x[7])/4000)+((x[8]*x[8])/4000)+((x[9]*x[9])/4000))-
		((cos(x[0]/sqrt(1)))*(cos(x[1]/sqrt(2)))*(cos(x[2]/sqrt(3)))*(cos(x[3]/sqrt(4)))*(cos(x[4]/sqrt(5)))*(cos(x[5]/sqrt(6)))
		*(cos(x[6]/sqrt(7)))*(cos(x[7]/sqrt(8)))*(cos(x[8]/sqrt(9)))*(cos(x[9]/sqrt(10))));
	//func1
	//return x[0]*x[0]+x[1]*x[1]+x[2]*x[2];
	//func2
	//return 100*((x[1]-(x[0]*x[0]))*(x[1]-(x[0]*x[0])))+(1-x[0])*(1-x[0]);
	//func4
	//return 0.5 + ((sin(sqrt(x[1]*x[1] + x[0]*x[0])))*(sin(sqrt(x[1]*x[1] + x[0]*x[0]))) - 0.5)/(1+0.0001*(x[1]*x[1] + x[0]*x[0])*(x[1]*x[1] + x[0]*x[0]));
	//schwefel
	//return 418.9829*5+(-1*x[0]*sin(sqrt(abs(x[0]))))+(-1*x[1]*sin(sqrt(abs(x[1]))))+(-1*x[2]*sin(sqrt(abs(x[2]))))+(-1*x[3]*sin(sqrt(abs(x[3]))))+(-1*x[4]*sin(sqrt(abs(x[4]))));
}

int main(int argc, char **argv)
{
	char buffer[256];int length;void *func;
	poblacion pob;
	variable *variables;
	int n_var;	
	char **var_names;
	
	int i,generaciones=0;
	
	if(cmdline_parser(argc,argv,&params)!=0)
		return 0;
	
	//se lee la funcion a optimizar
	printf ("f = ");
	fgets (buffer, 256, stdin);
	length = strlen (buffer);
	if (length > 0 && buffer[length - 1] == '\n')
		buffer[length - 1] = '\0';
	func = evaluator_create(buffer);
	assert(func);
	evaluator_get_variables(func,&var_names,&n_var);
	
	srand(params.srand_arg);
  
	if(params.debug_flag==1)
		printf("SEED: %d;PROB_MUT: %f;PROB_CROSS: %f\n",params.srand_arg,params.mut_arg,params.cross_arg);
	
	pob.tam_poblacion=params.pop_arg;
	
	inicializar(&pob,&variables,params.instancia_arg);
	evaluar(pob,func,n_var,var_names);
	mantener_el_mejor(pob);
	while(generaciones<MAX_GEN)
	{
		generaciones++;
		proportional(pob);
		crossover(pob,params.cross_arg);
		mutacion(pob,params.mut_arg);
		if(params.debug_flag==1)
			generar_reporte(pob,generaciones);
		evaluar(pob,func,n_var,var_names);
		elitismo(pob);
	}
	
	printf("\nMEJOR INDIVIDUO FITNESS: ; %f\n",pob.individuos[pob.tam_poblacion].fitness);
  
	for(i=0;i<pob.num_variables;i++)
		printf("VALOR X%d: %f\n",i,binary_gen_to_double(pob.individuos[pob.tam_poblacion].genes[i]));
	
	free(variables);
	
	return 0;
}
