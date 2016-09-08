//oblig1 i c++

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <string>
#include <time.h>
//using std::vector
//#include <lib.cpp>


//double linspace(int start, int end, int N, double& x[]);


int main(int argc, char const *argv[])
{
int x0 = 0;           //initial condition
int xend = 1;         //boundary condition
int u0 = 0;           //initial condition
int uend = u0;        //boundary condition

ofstream myfile;
if (argc > 2){
int N = atoi(argv[1]) ;
myfile.open(argv[2]);   // File to save the values of u
int n = N;
clock_t start, finish;
start = clock();

	myfile << "\n n =" << n << "\n";
	vector<double> a(n+1, -2);
	vector<int> b(n, 1);
	vector<int> c(n, 1);
	vector<double> f_ (n+1);
	vector<double> u (n+1); 
	double h = 1./(n + 1);  //step length
	f_[0] = -100*pow(h, 2)*exp(-10*x0);
	int i = 1;

	//Forward substitution:
	while (i < (n+1)){
		double xi = i*h;
		double fi = -100*pow(h, 2)*exp(-10*xi);
		double factor = c[i-1]/a[i-1];
		a[i] = a[i] - b[i-1]*factor;
		f_[i] = fi - f_[i-1]*factor;
		i += 1;

	}
	//Backward substitution:
	i = n-2;
	u[n] = uend;
	u[0] = u0;
	u[n-1] = f_[n-1]/a[n-1];
	myfile << u[n] << "\n" ;
	myfile << u[n-1] << "\n" ;
	while (i > 0){
		u[i] = (f_[i] - b[i]*u[i+1])/a[i];
		myfile << u[i] << "\n" ;
		i -= 1;
	}
	myfile << u[0] ;
		
myfile.close();

//linspace(x0, xend, n, x);
finish = clock();
cout << "N = " << N << endl;
cout << "Time: " << (finish - start)/CLOCKS_PER_SEC << endl;
return 0;


}


else{cout << "N = ?, filename = ?" << endl;
return 1;}
}


