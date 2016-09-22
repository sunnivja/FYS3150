//Program to find the solution of Schrodingers equation

#include <vector>
#include <iostream>
#include "jacobi.h"
#include <math.h>
#include <cmath>

using namespace std;
void print_matrix(double** A, int n);


int main(int argc, char const *argv[])
{
	int n = 10;
	int N = n;
	double rho_0 = 0;
	double rho_max = 10;
	double h = (rho_max - rho_0)/(N+1.0);
	int i = 0; int j = 0;
	double Beta_e = 1.44; //nmeV
	double hbar = 197.1; //nmeV/c^2
	double m_e = 1; 
	double alpha = pow(hbar, 2)/(m_e*Beta_e);
	double k = 1;
	double omega_r = 0.25*m_e*k*pow(alpha, 4)/pow(hbar, 2);
	double rho; 



	double ** A = new double*[N] ; 
	double **R = new double*[N];

	for (i=0;i<N;i++){
		A[i] = new double[N];
		R[i] = new double[N];
	}
	cout << "Making A" << endl;
	for (i=0;i<N;i++){
		for (j=0; j<N; j++){
			if (j == i){
				//cout << "j = i" << endl;
				rho = i*h;
				//For the interacting case: rho = omega_r^2*rho^2 + 1/rho
				A[i][j] = 2/pow(h, 2) + pow(rho, 2);
			}
			else if (j == i+1){
				//cout << "j = i+1" << endl;
				A[j][i] = 1/pow(h, 2);
				A[i][j] = 1/pow(h, 2);}
			
			else{
				//cout << "the rest is 0" << endl;
				A[i][j] = 0;
			}
			}
		}

		cout << "calling the Jacobi-function" << endl;
	jacobi_method(A, R, N);
	cout << A[0][0] << " " << A[1][1] << " "<< A[2][2] << endl;
	//print_matrix(A, n);

		return 0;

}

void print_matrix(double** A, int n){
	int i; int j;
	for (i=0;i<n+1;i++){
		for (j=0; j<n+1; j++){
			cout << A[i][j] << " ";
			if (j == n){
				cout << "" << endl;

			}
		}
	}


	return;
}