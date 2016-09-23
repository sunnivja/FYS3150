//Program to find the solution of Schrodingers equation

#include <vector>
#include <iostream>
#include "jacobi.h"
#include <math.h>
#include <cmath>
#include <fstream>
#include "testprogram.h"
#include <cstdlib>
#include <string>

using namespace std;
void print_matrix(double** A, int n);
void print_vector(double*v, int n);
void extract_diagonal(double** A, int n, double* v);
double* sort(double *v, int n, double** R);


int main(int argc, char const *argv[])
{
	int n = atoi(argv[3]);
	int N = n;
	double rho_0 = 0;
	double rho_max = 5;
	double h = (rho_max - rho_0)/(N+1.0);
	int i = 0; int j = 0;
	double rho; 
	double omega_r = 0.25;



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
				int a = atoi(argv[2]);
				if (a == 0){
					A[i][j] = 2/pow(h, 2) + rho*rho;
					}
				else{
					A[i][j] = 2/pow(h, 2) + rho*rho*omega_r*omega_r + 1.0/rho;}
				}
			
			else if (j == i+1){
				//cout << "j = i+1" << endl;
				A[j][i] = 1/pow(h, 2);
				A[i][j] = 1/pow(h, 2);
			}
			else if (j == i-1){
				//cout << "j = i+1" << endl;
				A[j][i] = 1/pow(h, 2);
				A[i][j] = 1/pow(h, 2);
			}
			
			else{
				//cout << "the rest is 0   " << i<< ", " << j << endl;
				A[i][j] = 0;
			}
		}
	}
		
	
	cout << "calling the Jacobi-function" << endl;
	jacobi_method(A, R, N);
	double* eigenvalues = new double[N];
	extract_diagonal(A, N, eigenvalues);
	double* eigenvalues_sorted = new double[N];
	eigenvalues_sorted = sort(eigenvalues, N, R);
	cout << eigenvalues_sorted[1] << " " << eigenvalues_sorted[2] << " "<< eigenvalues_sorted[3] << endl;
	print_vector(R[0], n);
	/*
	int i;int j;
	ofstream myfile;
	myfile.open(argv[1]);
	myfile << "n = " << n << "\n";
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			myfile << R[i][j] << " " ;
			if (j == n){
				myfile << "" << endl ;
			}
		}
	}
	myfile.close();
	*/





	//print_matrix(A, n);

		return 0;

}

void print_matrix(double** A, int n){
	int i; int j;
	for (i=0;i<n;i++){
		for (j=0; j<n; j++){
			if (fabs(A[i][j]) < 1e-8) {
				cout <<"0" << " ";
			} else {
				cout << A[i][j] << " ";
			}
			if (j == n-1){
				cout << " " << endl;

			}
		}
	}


	return;
}

void print_vector(double*v, int n){
	int i;
	for (i=0;i<n;i++){
		if (fabs(v[i] < 1e-8)){
			cout << "0" << endl;
		}
	cout << v[i] << endl;
	}
	return;
}






void extract_diagonal(double** A, int n, double* v){
	//double v = new[n];
	int i = 0;
	for (i=0;i<n;i++){
		v[i] = A[i][i];
	}
	return;
}


double* sort(double *v, int n, double** R){
	double* v_sorted = new double[n];
	double ** R_sorted = new double*[n];
	int i = 0;
	for (i=0;i<n;i++){
		R_sorted[i] = new double[n];
	}
	int j = 0;
	for (i=0;i<n+1;i++){
		double a1 = 0;
		double a2 = 0;
		double amax = 0;
		int max_no = 0;
		//int count = 0; 
		for(j=0;j<n;j++){
			if (v[j] > amax){
				amax = v[j];
				max_no = j;
				//cout << v[j] << endl;
				//count++;
			}
		}
		v[max_no] = 0;
		v_sorted[n-i] = amax;
		R_sorted[n-i] = R[max_no]; 

		//cout << v_sorted[n-i] << endl;
	}
	//v = v_sorted;
	R = R_sorted;
	return v_sorted;
}


/*
amax = 0;
for i=1..n
	if v[i]>amax :
		amax = v[i];
		index = i;

v[index] = 0;
*/
