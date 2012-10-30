#include <stdio.h>
#include "operadores.h"
#include "utilidades.h"

void mutacion(poblacion pob,double prob_mut)
{
	int i,j,rand_pos1;
	double rand_num;
	
	for(i=0;i<pob.tam_poblacion;i++)
	{
		for(j=0;j<pob.num_variables;j++)
		{
			//numero aleatoreo entre 0 y 1
			rand_num=randval();
			if(rand_num<prob_mut)
			{
				//numero aleatoreo entre 0 y num_var
				rand_pos1=(int)randval_between(0.0,(double)pob.individuos[i].genes[j].var->p);
				if(pob.individuos[i].genes[j].valor[rand_pos1]=='1')
					pob.individuos[i].genes[j].valor[rand_pos1]='0';
				else
					pob.individuos[i].genes[j].valor[rand_pos1]='1';
			}
		}
	}
}

void crossover(poblacion pob,double prob_cross)
{
	int i,one,first=0;
	double p;
	
	for(i=0;i<pob.tam_poblacion;i++)
	{
		p=randval();
		if(p<prob_cross)
		{
			first++;
			if(first%2==0)
				xover(pob.individuos[one].genes,pob.individuos[i].genes,pob);	
			else
				one=i;
		}
	};
}

void xover(gen *ind1, gen *ind2, poblacion pob)
{
	int i,j,punto;
	for(i=0;i<pob.num_variables;i++)
	{
		//se busca un punto de cruzamiento para la variable i
		punto=(int)randval_between(0.0,(double)ind1[i].var->p-1);
		if(punto!=0)
		{
			for(j=punto;j<ind1[i].var->p;j++)
				ind1[i].valor[j]=ind2[i].valor[j];
			for(j=0;j<punto;j++)
				ind2[i].valor[j]=ind1[i].valor[j];
		}
	}
}