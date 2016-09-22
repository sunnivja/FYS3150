//Testing the program for the Jacobi method

#include "jacobi.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 5;
	vector <double> A(n, n);
	vector <double> R(n, n);
	jacobi_method(A, R, n);


	return 0;
}






