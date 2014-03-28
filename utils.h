// Stuff C should have
double sq(double x){
	return x*x;
}

void swap(double* a, double* b){
	double* c = a;
	a=b;b=c;
}


// Derivatives along arrays
double d(double* x, int i){
	//return (x[i+1]-x[i-1])/2;
	return (x[i-2]-8*(-x[i-1]+x[i+1])-x[i+2])/12;
}

double d2(double* x, int i){
	return x[i-1]-2*x[i]+x[i+1];
}
