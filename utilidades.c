#include <stdlib.h>
#include <math.h>
#include "utilidades.h"

double randval()
{
	return (double)rand()/(double)RAND_MAX;
}

double randval_between(double smallNumber, double bigNumber)
{
    double diff = bigNumber - smallNumber;
    return (((double) rand() / RAND_MAX) * diff) + smallNumber;
}

/**
* @brief Convierte un numero binario a double
*
* Convierte un gen en su representacion binaria a su valor punto flotante utilizando
* primero una transformacion a decimal x' y luego con la formular x=low_bound+x'(R/(2^p-1))
*
* @param binary_gen gen al que se desea obtener su valor double
* @returns representacion en punto flotante del valor del gen
**/
double binary_gen_to_double(gen bin_gen)
{
	char* endptr;
    int val;
	double factor;
	
	factor=(bin_gen.var->up_bound-bin_gen.var->low_bound)/(pow(2,bin_gen.var->p)-1);
	val = strtol(bin_gen.valor, &endptr, 2);
	
	return bin_gen.var->low_bound+val*factor;
}

/* Compute a running average and variance of a set of input values. */ 
void AvgVar(double x, double *mean, double *var)
{
    static int n = 0;
    static double sum   = 0.0;
	static double sumSq = 0.0; 
    
	if(n==50)
	{
		n=0;
		sum=sumSq=0.0;
		*mean=*var=0.0;
	}
	sum += x;
	sumSq += (x*x);
	n++; 
	*mean = sum/n;
	*var = (sumSq/n) - (*mean * *mean);
}
