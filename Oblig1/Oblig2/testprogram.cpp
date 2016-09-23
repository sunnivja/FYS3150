//Testing the program for the Jacobi method

#include "jacobi.h"
#include <vector>
#include <iostream>
#include "armadillo"


using namespace arma;
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 5;
	vector <double> A(n, n);
	vector <double> R(n, n);
	test_highest_element(A);


	return 0;
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

/*
double test_armadillo(double** A, n){
	double** eigvec = new double*[n];
	double* eigval = new double[n];
	for (i=0;i<n;i++){
		eigvec[n] = new double[n];
	}
	eigvec, eigval = eigs_gen(A, n);

	double** eigvec_jacobi = new double*[n];

	for (i=0;i<n;i++){
		eigvec_jacobi[n] = new double[n];

*/




	return ...;
}






