#include "isingmodel.h"
#include "MonteCarlo.h"
#include "math.h"
#include "random"
#include <iostream>

using namespace std;

Isingmodel::Isingmodel()
{

}

double Isingmodel::Partition_function(int N, double* E, double T){
    double k_b = 1;
    double Z = 0;
    double beta = 1/(k_b*T);
    for (int i=0;i<N;i++){
        Z += exp(-E[i]*beta);
    }

  return Z;
}

double Isingmodel::Energy(double** spins, int N){
    double E = 0;
    double J = 1;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (j!= 0 && i != 0 && j != (N-1) && i != (N-1)){
                            E -=J*spins[i][j]*(spins[i-1][j] + spins[i+1][j] + spins[i][j-1] + spins[i][j+1]);}

            else if (j!=0 && i == 0 && j != (N-1)){
                            E -=J*spins[i][j]*(spins[N-1][j] + spins[i+1][j] + spins[i][j-1] + spins[i][j+1]);}

            else if (j!= 0 && i == (N-1) && j != (N-1)){
                            E -=J*spins[i][j]*(spins[i-1][j] + spins[0][j] + spins[i][j-1] + spins[i][j+1]);}

            else if (j == 0 && i != 0 && i != (N-1)){
                            E -=J*spins[i][j]*(spins[i-1][j] + spins[i+1][j] + spins[i][N-1] + spins[i][j+1]);}

            else if ( j == (N-1) && i != 0 && i != (N-1)){
                            E -=J*spins[i][j]*(spins[i-1][j] + spins[i+1][j] + spins[i][j-1] + spins[i][0]);}

            else if (j == 0 && i == 0){
                            E -=J*spins[i][j]*(spins[N-1][j] + spins[i+1][j] + spins[i][N-1] + spins[i][j+1]);}

            else if (j == (N-1) && i == (N-1)){
                            E -=J*spins[i][j]*(spins[i-1][j] + spins[0][j] + spins[i][j-1] + spins[i][0]);}

            else if (j == 0 && i == (N-1)){
                            E -=J*spins[i][j]*(spins[i-1][j] + spins[0][j] + spins[i][N-1] + spins[i][j+1]);}

            else if (j == (N-1) && i == 0){
                            E -=J*spins[i][j]*(spins[N-1][j] + spins[i+1][j] + spins[i][j-1] + spins[i][0]);}

        } }
    //cout << E/2 << endl;
    return E/2;
}

double Isingmodel::Magnetic_moment(double** spins, int N){
    double M = 0;
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M += spins[i][j];
        }
    }
   return abs(M)/2;
}


double Isingmodel::Exp_values(int N, double**spins, double T, int MCnumber, double& exp_energy_squared, double& magnetic_moment, double& magnetic_moment_squared){
    double w; double r;
    double k_b = 1;
    double beta = 1/(k_b*T);
    double exp_x = 0;
    double exp_x_squared = 0;
    double exp_m_squared = 0;
    int accepted = 0;
    double exp_m = Magnetic_moment(spins, N);

for (int k =0; k<MCnumber; k++){
            int i = rand() % N;
            int j = rand() % N;
            double Eb = Energy(spins, N)/(N*N);
            spins[i][j] *= (-1);
            double Et = Energy(spins, N)/(N*N);
            if (Eb > Et){
                exp_x += Et;
                //exp_x_squared += Et*Et;
                exp_m += 2*spins[i][j];
                exp_m_squared += 4*spins[i][j]*spins[i][j];
                accepted ++;
            }
            else{
                w = exp(-beta*(Et - Eb));
                r = rand()/double(RAND_MAX);
                if (w >= r){
                    exp_x += Et;
                    exp_x_squared += Et*Et;
                    exp_m += 2*spins[i][j];
                    exp_m_squared += 4*spins[i][j]*spins[i][j];
                    accepted++;
            }
             exp_x += Eb;
             exp_x_squared += Eb*Eb;
             spins[i][j] *= (-1);
             exp_m += 2*spins[i][j];
             exp_m_squared += 4*spins[i][j]*spins[i][j];
        } }

    magnetic_moment = exp_m/double(MCnumber);
    exp_energy_squared = exp_x_squared/double(MCnumber);
    magnetic_moment_squared = exp_m_squared/double(MCnumber);


    return exp_x/double(MCnumber);
}


