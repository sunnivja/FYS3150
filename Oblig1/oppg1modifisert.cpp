//oblig1 i c++
//Program is edited to fit our special case

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <time.h>
//using std::vector
//#include <lib.cpp>

//Main program
int main(int argc, char const *argv[])
{
//Checking if we have entered N and the filename
if (argc > 2){
int x0 = 0;           //initial condition
int xend = 1;         //boundary condition
int u0 = 0;           //initial condition
int uend = u0;        //boundary condition
int N = atoi(argv[1]);

//Monitoring the time usage of the substitution loops
clock_t start, finish;


ofstream myfile;
myfile.open(argv[2]);   // File to save the values of u
int n = N;




	myfile << "n = " << n;  // Writing the value of u we are using
	vector<double> a(n+1, -2); //Vectors (see theory-part)
	vector<double> f_ (n+1);
	vector<double> u (n+1);
	//vector<double> e (n+1);
	double h = 1./(n + 1);  //step length
	f_[0] = -100*pow(h, 2)*exp(-10*x0);  //Analytical result, known


start = clock();
	//Forward substitution:
	int i = 1;
	while (i < (n+1)){
		double xi = i*h;
		double fi = -100*pow(h, 2)*exp(-10*xi);
		//double factor = -1/a[i-1];
		a[i] = -(i+1.)/i;
		f_[i] = fi - f_[i-1]/double(a[i-1]);
		i += 1;

	}
cout << f_[n-1] << endl;
	//Backward substitution:
	i = n-2;
	u[n] = uend;
	u[0] = u0;
	u[n-1] = (f_[n-1] - uend)/double(a[n-1]);
	//e[n] = 0;
	myfile << u[n] << "\n" ;
	myfile << u[n-1] << "\n";
	while (i > 0){
		u[i] = (f_[i] - u[i+1])/double(a[i]);
		double xi = i*h;
		myfile << u[i] <<"\n " ; 
		i -= 1;
	}
	myfile << u[0] << "\n" ;
	
myfile.close();

finish = clock();
cout << "N = " << N << endl;
cout << "Time: " << (finish - start)/CLOCKS_PER_SEC << endl;


//Deleting arrays, since we have all the information we need in the txt-files.

u.clear();
f_.clear();
a.clear();

return 0;
}

else{cout << "N = ?, filename = ?" << endl;
return 1;}
}