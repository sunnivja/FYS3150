//Project 2, FYS3150
#include "armadillo"
#include <iostream>
#include <math.h>
#include <fstream>


using namespace std;
using namespace arma;


int main(int argc, char const *argv[])
{
if (argc > 2){
	//Declaring parameters

	int N = atoi(argv[1]);
	double rho_end = 1;
	double h = rho_end/N;
	b_end = 0;
	b0 = 0;
	epsilon = pow(10, -8);


	//Making the diagonals in matrix A:
	vec a = zeros(N) - 1/pow(h, 2);
	vec b = zeros(N);
	for (i=1; i<N-1;i++){
		rho_i = i*h;
		b[i] = 2/pow(h, 2) - pow(rho_i, 2);
		}

	//Setting up the eigenvector matrix

	mat R = zeros(N, N);
	for (i=0; i<N+1; i++){
		for (j=0; j<N+1; j++){
			if (j == i){
				R[j, i] = 1.0;
			}
			else{
				R[j, i]= 0.0;
			}

		}
	}
	int k, l;
	double max_iter = pow(N, 3);
	int iter = 0;
	

	/*
	//Finding cot(theta)
	
	for (l=0; l<N+1; l++){
		for (k=0; k<N+1; k++){
			double tau = (b[l] - b[k]/(2*a[l]);
			double t+ = -tau + sqrt(1 + pow(tau, 2));
			double t- = -tau - sqrt(1 + pow(tau, 2));
			double c = 1/sqrt(1 + pow(t+, 2));
			double s = c*t+;  

		}
	}
	*/










	return 0;
}
else{ cout << "N = ??"<< endl;
return 1;

}
}