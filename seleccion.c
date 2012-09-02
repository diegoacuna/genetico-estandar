#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "seleccion.h"
#include "utilidades.h"

int comparar(const void *arg1, const void *arg2)
{
	genotipo *ind1,*ind2;
	ind1=(genotipo*)arg1;
	ind2=(genotipo*)arg2;
	if(ind1->fitness<ind2->fitness)
		return -1;
	else if(ind1->fitness>ind2->fitness)
		return 1;
	else 
		return 0;
}

void ranking(poblacion pob)
{
	int i,j,total_fitness=0;
	double p;
	genotipo *nueva_pob;
	
	//se realiza un ranking de los individuos
	qsort(pob.individuos, pob.tam_poblacion, sizeof(genotipo), comparar);
	for(i=0;i<pob.tam_poblacion;i++)
		total_fitness+=i+1;
	//se calcula el relative fitness
	for(i=0;i<pob.tam_poblacion;i++)
		pob.individuos[i].rfitness=(double)(i+1)/(double)total_fitness;
	//se calcula el cumulative fitness
	pob.individuos[0].cfitness=pob.individuos[0].rfitness;
	for(i=1;i<pob.tam_poblacion;i++)
		pob.individuos[i].cfitness=pob.individuos[i-1].cfitness+pob.individuos[i].rfitness;
	
	//se seleccionan los individuos utilizando el cumulative fitness
	nueva_pob=malloc(sizeof(genotipo)*pob.tam_poblacion);
	for(i=0;i<pob.tam_poblacion;i++)
	{
		p=randval();
		if(p<pob.individuos[0].cfitness)
			nueva_pob[i]=pob.individuos[0];
		else
		{
			for(j=0;j<pob.tam_poblacion-1;j++)
			{
				if(p>=pob.individuos[j].cfitness && p<pob.individuos[j+1].cfitness)
					nueva_pob[i]=pob.individuos[j+1];
			}
			if(p>=pob.individuos[pob.tam_poblacion-1].cfitness)
				nueva_pob[i]=pob.individuos[pob.tam_poblacion-1];
		}
	}

	//se realiza la copia de vuelta a la poblacion original
	for(i=0;i<pob.tam_poblacion;i++)
	{
		pob.individuos[i]=nueva_pob[i];
	}
	free(nueva_pob);
	
	/*for(i=0;i<pob.tam_poblacion;i++)
	{
		printf("INDIVIDUO %d FITNESS: %f   RFITNESS: %f   CFITNESS: %f\n",i,pob.individuos[i].fitness,pob.individuos[i].rfitness,pob.individuos[i].cfitness);
	}*/
	
}

void tournament(poblacion pob)
{
  genotipo *nueva_pob;
  int i,ind1,ind2;
  nueva_pob=malloc(sizeof(genotipo)*pob.tam_poblacion);
  for(i=0;i<pob.tam_poblacion;i++)
  {
    ind1=(int)randval_between(0.0,(double)pob.tam_poblacion);
    do
			ind2=(int)randval_between(0.0,(double)pob.tam_poblacion);
		while(ind2==ind1);
    
    /*se selecciona al mejor de estos individuos*/
    if(pob.individuos[ind1].fitness>pob.individuos[ind2].fitness)
      nueva_pob[i]=pob.individuos[ind1];
    else
      nueva_pob[i]=pob.individuos[ind2];
  }
  
  //se realiza la copia de vuelta a la poblacion original
	for(i=0;i<pob.tam_poblacion;i++)
	{
		pob.individuos[i]=nueva_pob[i];
	}
	free(nueva_pob);
}

void proportional(poblacion pob)
{
  int i,j,peor;
	double p,total_fitness=0.0;
	genotipo *nueva_pob;
	
	//se busca el individuo con el menor fitness
  peor=0;
  for(i=0;i<pob.tam_poblacion;i++)
	{
		if(pob.individuos[i].fitness<pob.individuos[peor].fitness)
			peor=i;
	}
  //se dejan todos los fitness con valores positivos y se calcula el fitness total
  for(i=0;i<pob.tam_poblacion;i++)
  {
		pob.individuos[i].nfitness=pob.individuos[i].fitness+2*fabs(pob.individuos[peor].fitness);
    total_fitness+=pob.individuos[i].nfitness;
  }

	//se calcula el relative fitness
	for(i=0;i<pob.tam_poblacion;i++)
		pob.individuos[i].rfitness=pob.individuos[i].nfitness/total_fitness;
	//se calcula el cumulative fitness
	pob.individuos[0].cfitness=pob.individuos[0].rfitness;
	for(i=1;i<pob.tam_poblacion;i++)
		pob.individuos[i].cfitness=pob.individuos[i-1].cfitness+pob.individuos[i].rfitness;
	
	//se seleccionan los individuos utilizando el cumulative fitness
	nueva_pob=malloc(sizeof(genotipo)*pob.tam_poblacion);
	for(i=0;i<pob.tam_poblacion;i++)
	{
		p=randval();
		if(p<pob.individuos[0].cfitness)
			nueva_pob[i]=pob.individuos[0];
		else
		{
			for(j=0;j<pob.tam_poblacion-1;j++)
			{
				if(p>=pob.individuos[j].cfitness && p<pob.individuos[j+1].cfitness)
					nueva_pob[i]=pob.individuos[j+1];
			}
			if(p>=pob.individuos[pob.tam_poblacion-1].cfitness)
				nueva_pob[i]=pob.individuos[pob.tam_poblacion-1];
		}
	}

	//se realiza la copia de vuelta a la poblacion original
	for(i=0;i<pob.tam_poblacion;i++)
	{
		pob.individuos[i]=nueva_pob[i];
	}
	free(nueva_pob);
}
