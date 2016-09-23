//Testing the program for the Jacobi method

#include "jacobi.h"
#include <vector>
#include <iostream>
#include "armadillo"


using namespace arma;
using namespace std;
double* sort(double *v, int n, double** R);
void test_highest_element(double** A);
double* test_armadillo(double** A, int n);
void test_orthogonality(double**A, int n);



int main(int argc, char const *argv[])
{
	int n = 5;
	vector <double> A(n, n);
	vector <double> R(n, n);
	test_highest_element(A);
	double* deviation = new[n];
	deviation = test_armadillo(A, n);



	return 0;
}

void test_orthogonality(double** A, int n){
	int i;int j;
	//A has to be an orthogonal matrix!
	double** eigvecs = new double[n];
	for (i=1;i<n;i++){
		eigvecs[i] = new double[n];
	}
	jacobi_method(A, eigvecs, n);
	//Calculating inner product:
	//double* inner_products = new double[n];
	double inner_product = 0;

	for (i=0;i<n;i++){
		//double inner_product = 0;
		for (j=0; j<n; j++){
			if (i != j){
				inner_product_ij = inner_product(begin(eigvecs[i][0]), end(eigvecs[i][n]), begin(eigvecs[j][0]), end(eigvecs[j][n]), 0.0);
				if (inner_product_ij < 1E-8){
					inner_product_ij = 0;
				}
		}		inner_product += inner_product_ij;
		}
	}
	if (inner_product < 1E-8){
		cout << "The Jacobi method preserves orthogonality" << endl;
	}
	else{
		cout << "The Jacobi method does not preserve orthogonality :o :( :'( " endl;
	}
	return;
}

void test_sort(double*v, n){

}




void test_highest_element(double** A){
	amax = max(A(row(A)!=col(A)));
	int k; int l;
	n = (row(A)).size();
	amax_jacobi = maxoffdiag(A, k, l, n);
	if (abs(amax - amax_jacobi) < 1E-8){
		cout << "Maxoffdiag works" << endl;
	}
	else{
		cout << "Maxoffdiag does not work" << endl;
	}
	return;
}


double* test_armadillo(double** A, int n){
	double** eigvec = new double*[n];
	double* eigval = new double[n];
	for (i=0;i<n;i++){
		eigvec[n] = new double[n];
	}
	eigvec, eigval = eigs_gen(A, n);

	double** eigvec_jacobi = new double*[n];

	for (i=0;i<n;i++){
		eigvec_jacobi[n] = new double[n];
	jacobi_method(A, eigvec_jacobi, n);
	double* v = new double[n];
	double* deviation = new double[n];
	double*dev = new double[n];
	sort(v, n, eigvec_jacobi);
	for (i=1;i<n;i++){
		for (j=1;j<n;j++){
			dev[j] = abs(eigvec_jacobi[i][j] - eigvec[i][j]);
		deviation[i] = mean(dev);
		}
	}


	return deviation;
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






