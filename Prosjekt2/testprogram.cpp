//Testing the program for the Jacobi method

#include "jacobi.h"
#include <vector>
#include <iostream>
#include "armadillo"


using namespace arma;
using namespace std;
double* sort(double *v, int n, double** R);
void test_highest_element(double** A, int n, double amax);
//double* test_armadillo(double** A, int n);
void test_orthogonality(double**A, int n);
double mean(double*v, int n);
void test_sort(double*v, int n);
//double** conv_to_arma(double** A, int n);
double** A = new double*[2];
for (i=0;i<2;i++){
	A[i] = new double[2];
}
A[]

void run_all_tests(double** A, int n, double amax){
	test_orthogonality(A, n);
	test_highest_element(A, n);
	return;
}


void test_orthogonality(double** A, int n){
	int i;int j; int k;
	//A has to be an orthogonal matrix!
	double** eigvecs = new double*[n];
	for (i=1;i<n;i++){
		eigvecs[i] = new double[n];
	}
	jacobi_method(A, eigvecs, n);
	//Calculating inner product:
	double inner_product = 0;
	double inner_product_ij;
	//If the vectors are not orthogonal, the "inner product" will be much larger than zero
	for (i=0;i<n;i++){
		for (j=0; j<n; j++){
			if (i != j){
				for (k=0;k=n;k++){
					inner_product_ij += eigvecs[i][k]*eigvecs[j][k];
				}
				if (inner_product_ij < 1E-10){
					inner_product_ij = 0;
				}
		}		inner_product += inner_product_ij;
		}
	}
	if (inner_product < 1E-8){
		cout << "The Jacobi method preserves orthogonality" << endl;
	}
	else{
		cout << "The Jacobi method does not preserve orthogonality :o :( :'( " << endl;
	}
	return;
}

void test_sort(double*v, int n){
	int i; double a;
	double** R = new double*[n];
	for (i=0;i<n;i++){
		R[i] = new double[n];
	}
	double* v_sorted = new double[n];
	int check = 0;
	v_sorted = sort(v, n, R);
	for (i=0;i<n-1;i++){
		a = v_sorted[i] - v_sorted[i+1];
		if (a < 0){
			check += 0;
		}
		else{
			check += 1;
		}
	}
	if (check == 0){
		cout << "The sorting function works! "<< endl;
	}
	else{
		cout << "The sorting function does not work.." << endl;
	}
}




void test_highest_element(double** A, int n, double amax){
	int *k; int *l;
	double amax_jacobi = maxoffdiag(A, k, l, n);
	if (abs(amax - amax_jacobi) < 1E-8){
		cout << "Maxoffdiag works" << endl;
	}
	else{
		cout << "Maxoffdiag does not work" << endl;
	}
	return;
}

/*
double* test_armadillo(double** A, int n){
	double** eigvec = new double*[n];
	double* eigval = new double[n];
	double* v = new double[n];
	double** eigvec_jacobi = new double*[n];
	double* deviation = new double[n];
	int i; int j;


	for (i=0;i<n;i++){
		eigvec[n] = new double[n];
	}
	for (i=0;i<n;i++){
		eigvec_jacobi[n] = new double[n];
	}

	mat A_arma = zeros<mat>(n, n);
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
		A_arma[i, j] = A[i][j];
	}
	}

	jacobi_method(A, eigvec_jacobi, n);
	eigvec, eigval = eigs_gen(A_arma);
	sort(v, n, eigvec_jacobi);
	for (i=1;i<n;i++){
		double*dev = new double[n];
		for (j=1;j<n;j++){
			dev[j] = abs(eigvec_jacobi[i][j] - eigvec[i][j]);
		deviation[i] = mean(dev, n);
		}
	}


	return deviation;
}
*/

double mean(double*v, int n){
	int i;
	double sum = 0;
	for (i=0;i<n;i++){
		sum += v[i];
	}
	return sum/double(n);
}

/*
double** conv_to_arma(double**A, int n){
	mat A_arma = zeros<mat>(n, n);
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
		A_arma[i][j] = A[i][j];
	}
	}
	return A_arma;
}
*/


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
	return v_sorted;}






