#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ag.h"
#include "utilidades.h"

void inicializar(poblacion *pob, variable **var, char* instancia)
{
	int num_var;
	int i,j,k;
	double val;
	variable *variables;
	FILE *fichero;
	
	fichero=fopen(instancia,"r");
	
	fscanf(fichero, "%d\n",&num_var);
	pob->num_variables=num_var;
	pob->individuos=malloc(sizeof(genotipo)*(pob->tam_poblacion+1));
	
	for(i=0;i<pob->tam_poblacion+1;i++)
		pob->individuos[i].genes=malloc(sizeof(gen)*num_var);
	variables=malloc(sizeof(variable)*num_var);
	
	for(i=0;i<num_var;i++)
	{
		fscanf(fichero,"%lf %lf %d",&variables[i].low_bound,&variables[i].up_bound,&variables[i].p);
		variables[i].p=(variables[i].up_bound-variables[i].low_bound)*pow(10,variables[i].p);
		variables[i].p=ceil(log(variables[i].p)/log(2));
		for(j=0;j<pob->tam_poblacion+1;j++)
		{
			pob->individuos[j].genes[i].var=&(variables[i]);
			//genero una solucion inicial para esta variable
			pob->individuos[j].genes[i].valor=malloc(sizeof(char)*(variables[i].p+1));
			for(k=0;k<variables[i].p;k++)
			{
				val=randval();
				if(val>0.5)
				{
					pob->individuos[j].genes[i].valor[k]='1';
				}
				else
				{
					pob->individuos[j].genes[i].valor[k]='0';
				}
			}
			pob->individuos[j].genes[i].valor[variables[i].p]='\0';
		}
	}
	*var=variables;
}

void copiar_genes(gen *desde, gen *hacia, int total_genes)
{
	int i;
	for(i=0;i<total_genes;i++)
	{
		strcpy(hacia[i].valor,desde[i].valor);
		hacia[i].var=desde[i].var;
	}
}

void evaluar(poblacion pob,void *f,int n_var,char **var_names)
{
	int i,j;
	double *vars;
	vars=malloc(sizeof(double)*pob.num_variables);
	for(i=0;i<pob.tam_poblacion;i++)
	{
		for(j=0;j<pob.num_variables;j++)
			vars[j]=binary_gen_to_double(pob.individuos[i].genes[j]);
		pob.individuos[i].fitness=evaluator_evaluate(f,n_var,var_names,vars);
	}
	/*for(i=0;i<pob.tam_poblacion;i++)
		printf("INDIVIDUO %d FITNESS: %f\n",i,pob.individuos[i].fitness);*/
}

void elitismo(poblacion pob)
{
	int mejor,peor,i;
	mejor=peor=0;
	/* se encuentra al mejor y el peor de los individuos */
	for(i=0;i<pob.tam_poblacion;i++)
	{
		if(pob.individuos[i].fitness>pob.individuos[mejor].fitness)
			mejor=i;
		if(pob.individuos[i].fitness<pob.individuos[peor].fitness)
			peor=i;
	}
	/* se actualizan los individuos si es que corresponde */
	if(pob.individuos[pob.tam_poblacion].fitness<pob.individuos[mejor].fitness)
	{
		copiar_genes(pob.individuos[mejor].genes,pob.individuos[pob.tam_poblacion].genes,pob.num_variables);
		pob.individuos[pob.tam_poblacion].fitness=pob.individuos[mejor].fitness;
	}
	else
	{
		copiar_genes(pob.individuos[pob.tam_poblacion].genes,pob.individuos[peor].genes,pob.num_variables);
		pob.individuos[peor].fitness=pob.individuos[pob.tam_poblacion].fitness;
	}
}

void mantener_el_mejor(poblacion pob)
{
	int i,mejor=0;
	copiar_genes(pob.individuos[0].genes,pob.individuos[pob.tam_poblacion].genes,pob.num_variables);
	pob.individuos[pob.tam_poblacion].fitness=pob.individuos[0].fitness;
	for(i=0;i<pob.tam_poblacion;i++)
	{
		if(pob.individuos[i].fitness>pob.individuos[pob.tam_poblacion].fitness)
		{
			pob.individuos[pob.tam_poblacion].fitness=pob.individuos[i].fitness;
			mejor=i;
		}
	}
	//copio el mejor
	copiar_genes(pob.individuos[mejor].genes,pob.individuos[pob.tam_poblacion].genes,pob.num_variables);
	pob.individuos[pob.tam_poblacion].fitness=pob.individuos[mejor].fitness;
}

void generar_reporte(poblacion pob, int generacion)
{
	double total_fitness=0;
	int i;
	double mean,var;
	
	for(i=0;i<pob.tam_poblacion;i++)
	{
		total_fitness+=pob.individuos[i].fitness;
		AvgVar(pob.individuos[i].fitness,&mean,&var);
	}
	
	if(generacion==1)
		printf("%-14s%-14s%-14s%-17s%-13s%-17s\n","GENERACION;","PROMEDIO;","VARIANZA;","DESV. STANDARD;","TOTAL;","MEJOR INDIVIDUO"); 
	printf("%-14d;%-14f;%-14f;%-17f;%-13f;%-17f;\n",generacion,mean,var,sqrt(var),total_fitness,pob.individuos[pob.tam_poblacion].fitness); 
}
