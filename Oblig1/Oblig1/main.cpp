#include <iostream>

using namespace std;

double linspace(int start, int end, int N, double& x);


int main(int argc, char const *argv[])
{
int x0 = 0;           //initial condition
int xend = 1;         //boundary condition
int v0 = 0;           //initial condition
int vend = v0;        //boundary condition
for n = [10, 100, 1000]{
       //number of iterations
double h = 1/(n +1);  //step length

double x  = new double [n];
linspace(x0, xend, n, x);}
    return 0;
}


double linspace(int start, int end, int N, double& x){
    int i = 0;
    double step_length = (end - start)/(N);
    while (i < N){
        x[i] = i*step_length;
        i += 1;
    }
    return 0;
}


