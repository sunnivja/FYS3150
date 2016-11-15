#include "examples.h"
#include "isingmodel.h"
#include <iostream>
#include "math.h"
#include <time.h>
#include <fstream>

using namespace std;

Examples::Examples()
{

}

void Examples::Random_spins2D(int N, int n, double T, double& exp_energy_squared, double& magnetic_moment, double& magnetic_moment_squared, int init){
    //Initialises the calculations for a two-dimensional spin lattice with N elements in each direction.

    int i; int j; int k; int s;
    Isingmodel ising;

    //Parameters:
    double beta = 1.0/T;
    double Z = 0;
    double sum_energies = 0;

    double* energies = new double[n];
    double* probability = new double[n];

    double** spins = new double*[N];
    for (int i=0;i<N;i++){ spins[i] = new double[N];}

    //srand(time(NULL));
    for (s=0;s<n;s++){
       //Generates one spin-system
        if (init == 0){
        for (i=0;i<N;i++){
            for (j=0;j<N;j++){
                //srand(time(NULL));
                double a = rand()/double(RAND_MAX);
                if (a >= 0.5){
                    spins[i][j] = 1;
                }
                else{
                    spins[i][j] = -1;  
                }
            }
        }
        }
        else{
            for (int i=0;i<N;i++){
                for (int j=0;j<N;j++){
                    spins[i][j] = 1;
                }
            }
    }
        Isingmodel isingmodel;


    }
    Isingmodel isingmodel;

    double expectation_energy = isingmodel.Exp_values(N, spins, T, n, exp_energy_squared, magnetic_moment, magnetic_moment_squared);



return ;
}

