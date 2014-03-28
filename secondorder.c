
#include <stdio.h>
#include <math.h>
#include "utils.h"

double* x, *xold;
double x0[1000], x1[1000];
//size_t n = sizeof x / sizeof *x;
double n = sizeof x0 / sizeof *x0;


void initialCondition(double* x){
	for(int i=0;i<n;i++){ // set up initial condition
	
	// Zeros
	//x[i]=0;
	
	// Square
	//x[i]= ((i>(4*n/6) && i<(5*n/6)) ? 1 : 0);
	
	// One Gaussian
	//x[i]= (i>(n/3.0) && i<(2*n/3.0)) ? exp(-sq((i-n/2.0)/(n/12.0))) : 0;
	
	// Two Gaussians
	//x[i]= (i>(n/6.0) && i<(2*n/6.0)) ? exp(-sq((i-3*n/12.0)/(n/48.0))) : 0;
	//x[i]= (i>(4*n/6.0) && i<(5*n/6.0)) ? -exp(-sq((i-9*n/12.0)/(n/48.0))) : x[i];
	}
} 


int main(){
	
	initialCondition(x0);
	initialCondition(x1);
	
	x=x0;
	xold=x1;
	
	
	for (int j=0;j<1000;j++){ //iterate over which line
		for(int i=1;i<n-1;i++){ // iterate along the line
			//Wave Equation
			x[i]= 0*d2(x,i)+2*x[i]-xold[i];
			printf("%f ",x[i]);
			swap (x,xold);

		}
		printf("\n");
	}
}

