//oblig1 i c++
//Program is edited to fit our special case

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
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
myfile.open("valuesdifferentnmod.txt");   // File to save the values of u
int n = 10;
while (n < 1001)
{    //Perform the same iterations for different values of n
	myfile << "\nn =" << n;
	myfile << "\n u  e" ;
	vector<double> a(n+1, -2);
	vector<double> f_ (n+1);
	vector<double> u (n+1);
	vector<double> e (n+1);
	f_[0] = -100*exp(-10*x0);
	double h = 1/(n + 1);  //step length
	int i = 1;

	//Forward substitution:
	while (i < (n+1)){
		double xi = i*h;
		double fi = -100*exp(-10*xi);
		double factor = 2/a[i-1];
		a[i] = a[i] + factor;
		f_[i] = fi + f_[i-1]*factor;
		i += 1;

	}
	//Backward substitution:
	i = n-2;
	u[n] = uend;
	u[0] = u0;
	u[n-1] = f_[n-1]/a[n-1];
	myfile << "\n" << u[n] << " " << log((u[n] - h*n)/(h*n));
	myfile << u[n-1] << " " << log((u[n-1] - h*(n-1))/(h*(n-1)));
	while (i > 0){
		u[i] = (f_[i] - u[i+1])/a[i];
		double xi = i*h;
		e[i] = log((u[i] - xi)/xi);
		myfile << u[i] << " " << e[i] << "\n" ;
		i -= 1;
	}
	
		
	n = n*10;
	}
myfile.close();

//linspace(x0, xend, n, x);
return 0;
}