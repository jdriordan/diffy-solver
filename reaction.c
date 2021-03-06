#include <stdio.h>
#include <math.h>
#include "utils.h"

double x0[1000];
double n = sizeof x0 / sizeof *x0;




void initialCondition(double* x){
	for(int i=0;i<n;i++){ // set up initial condition
	
	// Zeros
	//x[i]=0;
	
	// Square
	//x[i]= ((i>(4*n/6) && i<(5*n/6)) ? 1 : 0);
	
	// Power Law
	x[i]= (i>(n/3) && i<(2*n/3)) ? pow((i/n),-2) : 0;
	
	// One Gaussian
	//x[i]= (i>(n/3.0) && i<(2*n/3.0)) ? exp(-sq((i-n/2.0)/(n/12.0))) : 0;
	
	// Two Gaussians
	//x[i]= (i>(n/6.0) && i<(2*n/6.0)) ? exp(-sq((i-3*n/12.0)/(n/48.0))) : 0;
	//x[i]= (i>(4*n/6.0) && i<(5*n/6.0)) ? -exp(-sq((i-9*n/12.0)/(n/48.0))) : x[i];
	}
} 


int main(){
	
	
	for (int j=0;j<1000;j++){ //iterate over which line
		for(int i=1;i<n-1;i++){ // iterate along the line
			
			printf("%f ",x0[i]);
			
			// Diffusion-Loss
			 x0[i]+= 1e-3*(-2.5*x0[i]-1e-0*(i/n)*d(x0,i))+ 
			// with Power Law Injection
				((i>(n/3) && i<(2*n/3)) ? 1e-3*pow((i/n),-2) : 0);
			// with Mono-energetic Injection
			//	((i>(4*n/6) && i<(5*n/6)) ? 1e-3 : 0);
			
			
			//Convection Equation (speed?)
			//x[i]+= d(x,i)/5;
			

		}
		printf("\n");
	}
}

