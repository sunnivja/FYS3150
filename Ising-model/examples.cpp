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

double Examples::Random_spins2D(int N, int n, double T, double& exp_energy_squared, double& magnetic_moment, double& magnetic_moment_squared, int init){
    int i; int j; int k; int s;
    Isingmodel ising;

    //Parameters:
    double beta = 1.0/T;
    double Z = 0;
    double sum_energies = 0;

    double* energies = new double[n];
    //double* magnetic_moment = new double[n];
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
                if (a > 0.5){
                    spins[i][j] = 1;
                    //cout << spins[i][j] << endl;
                }
                else{
                    spins[i][j] = -1;
                    //cout << spins[i][j] << endl;
                }
                //magnetic_moment[s] += spins[i][j]/double(N*N);
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
        //Calculate the energy for each system:
        Isingmodel isingmodel;
        energies[s] = isingmodel.Energy(spins, N)/double(N*N);
        sum_energies += isingmodel.Energy(spins, N)/double(N*N);
        Z += exp(-beta*energies[s]);

       // cout << energies[s] << endl;
        //magnetic_moment[s] = Isingmodel::Magnetic_moment(spins, N);

    }
   // cout << "Z = " << Z << endl;
    //double partition_function = Isingmodel.Partition_function(N, energies, T);
    Isingmodel isingmodel;

    double expectation_energy = isingmodel.Exp_values(N, spins, T, n, exp_energy_squared, magnetic_moment, magnetic_moment_squared);

    //cout << "Expected value: " << expectation_energy << endl;
    //cout << "Mean value: " << sum_energies/n << endl;
    //double expectation_magnetic_moment = isingmodel.Exp_value_squared(N, magnetic_moment, Z, energies, T, n);
    for (int i=1;i<n;i++){
        probability[i] = energies[i]/Z;
    }



return expectation_energy;
}

void Examples::Random_spins3D(int N, double*** spins){
    int i; int j; int k;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            for (k=0;k<N;k++){
                double a = rand() % 1;
                if (a < 0.5){
                    spins[i][j][k] == -1;
                }
                else{
                    spins[i][j][k] == 1;
                }

            }
        }
}
return ;
}
