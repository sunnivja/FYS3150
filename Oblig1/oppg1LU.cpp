//Kompilere program: g++ oppg1LU.cpp -lblas -llapack -larmadillo 

//Solving the problem using LU-decomposition
#include "armadillo"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include "time.h"

using namespace std;
using namespace arma;

int main(int argc, char const *argv[])
{	
	if (argc > 2){
	//Parameters
	int i = 0;
	int j = 0;
	int N = atoi(argv[1]);
	double h = 1./(N+1);

	//Declaring space for vectors and matrix A
	mat A =  zeros<mat>(N, N);
	vec f =  zeros<vec>(N);
	vec u =  zeros<vec>(N);

	//Making a tridiagonal matrix with equal elements on each diagonal
	for (i=0; i<N; i++){
		double xi = i*h;
		f[i] = -100*pow(h, 2)*exp(-10*xi);
		for (j=0; j<N; j++){
			if (j == i){
				A(i, j) = -2;
			}
			else if (j == (i+1)){
				A(i, j) = 1;
			}
			else if (j == (i-1)){
				A(i, j) = 1;
			}
			else{
				A(i, j) = 0;
			}

		}
	}
	//printf("A = \n");
	//cout << A << endl;

	clock_t start, finish;
	//L decomposition
	start = clock();
	mat L, U;
	lu(L, U, A);
	finish = clock();
	cout << (finish - start)/CLOCKS_PER_SEC << endl;

	//Solving the linear equation Au = f
	u = solve(A, f);
	ofstream myfile;
	myfile.open(argv[2]);
	for(i=0;i<N;i++){
		myfile << u[i] ;
	}
	myfile.close();
	//cout << u << endl;


	return 0;}
	else{
		cout << "N = ?, filename = ?" << endl;
		return 1;
	}
}