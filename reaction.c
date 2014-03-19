#include <stdio.h>
#include <math.h>

double xs[1000];
size_t n = sizeof xs / sizeof *xs;

double sq(double x){
	return x*x;}

int main(){
	
	for(int i=0;i<n;i++){ // iterate along the line
		//xs[i]= (i>(n/3) && i<(2*n/3)) ? 1 : 0;
		//xs[i]= (i>(n/3.0) && i<(2*n/3.0)) ? exp(-sq((i-n/2.0)/(n/12.0))) : 0;
		xs[i]= (i>(n/6.0) && i<(2*n/6.0)) ? exp(-sq((i-3*n/12.0)/(n/24.0))) : 0;
		xs[i]= (i>(4*n/6.0) && i<(5*n/6.0)) ? exp(-sq((i-9*n/12.0)/(n/24.0))) : xs[i];
		//xs[i]= (i>(n/3.0) && i<(2*n/3.0)) ? 100*cos(10.0*i/n) : 0;
		//xs[i] = cos(i/100.0);
	}
	
	
	for (int j=0;j<10000;j++){ //iterate over which line
		for(int i=1;i<n-1;i++){ // iterate along the line
			// constant boundary condition
			printf("%f ",xs[i]);
			xs[i]+= (xs[i+1]-xs[i-1])/10;
			//xs[i]-= (xs[i-2]-8*(-xs[i-1]+xs[i+1])-xs[i+2])/(n/100.0);
		}
		printf("\n");
	}
}

