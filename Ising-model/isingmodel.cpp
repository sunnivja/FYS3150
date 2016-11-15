#include "isingmodel.h"
#include "MonteCarlo.h"
#include "math.h"
#include "random"
#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

Isingmodel::Isingmodel()
{

}


double Isingmodel::Energy(double** spins, int N){
    //Calculates the total energy of the spin lattice

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
    return E/2;
}



double Isingmodel::Magnetic_moment(double** spins, int N){
    //Calculates the magnetic moment by adding all the spins in the lattice

    double M = 0;
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M += spins[i][j];
        }
    }
   return abs(M);
}


double Isingmodel::DeltaE(double** spins, int i, int j, int N){
    //Calculates the change in the energy of the lattice if we flip a spin
    double J = 1;
    int up; int down; int left; int right;
    up = j+1;
    down = j-1;
    right = i+1;
    left = i-1;

    if (i == N-1){right = 0;}
    if (i == 0){left = N-1;}
    if (j == N-1){up = 0;}
    if (j == 0){down = N-1;}

   double E = 2*J*spins[i][j]*(spins[i][up] + spins[i][down] + spins[left][j] + spins[right][j]);
   return E;
}




double Isingmodel::Exp_values(int N, double**spins, double T, int MCnumber, double& exp_energy_squared, double& magnetic_moment, double& magnetic_moment_squared){
    //Calculates all the parameters we want by perforing the Metropolis algorithm


    double w; double r; double magnetization = 0; double tot_energy = 0; double tot_energy_squared = 0; double tot_magnetization = 0; double tot_magnetization_squared = 0;
    double k_b = 1;
    double exp_x = 0;
    double exp_x_squared = 0;
    double exp_m_squared = 0;
    double magnetization_squared;
    double a;
    int accepted = 0;
    double deltaE;
    ofstream myfile;
    myfile.open("test.dat");
    double t = 2.25;
    cout << "N = " << N << endl;
    double energy = Energy(spins, N);

//while (t < 2.4){
    //cout << "t = " << t << endl;
    t = T;
    accepted = 0;
    int count;
    double beta = 1.0/t;
    //magnetization = Magnetic_moment(spins, N);
    for (int k =0; k<MCnumber; k++){
        magnetization = Magnetic_moment(spins, N);
            count = 0;
            for (int l=0; l<(N*N); l++){
            int i = rand() % N;
            int j = rand() % N;
            deltaE = DeltaE(spins, i, j, N);
            if (deltaE <= 0){
                spins[i][j] = spins[i][j]*(-1);
                energy += deltaE;
                magnetization += 2*spins[i][j];
                accepted ++;
            }
            else{
                w = exp(-beta*(deltaE));
                r = rand()/double(RAND_MAX);
                if (r < w){
                    spins[i][j] = spins[i][j]*(-1);
                    energy += deltaE;
                    magnetization += 2*spins[i][j];
                    accepted++;
                          }
                 }
            //myfile << k*l << " " << energy << "\n";
            }

           //cout << magnetization << endl;
           tot_energy += energy;
           tot_energy_squared += energy*energy;
           tot_magnetization += magnetization;
           tot_magnetization_squared += magnetization*magnetization;
           //cout << tot_magnetization_squared;

       // myfile << k << " " << tot_energy/double(k) << " "<< tot_energy_squared/double(k)<< " "<< tot_magnetization/double(k) << " " <<  tot_magnetization_squared/double(k) << " " << accepted << "\n";
    }
    //cout << "End of loop" << endl;
        tot_energy /= (MCnumber);
        tot_energy_squared /= (MCnumber);
        tot_magnetization /= (MCnumber);
        tot_magnetization_squared /= (MCnumber);

        double heat_capacity = (tot_energy_squared - tot_energy*tot_energy)/(t*t);
        double susceptibility = (tot_magnetization_squared - tot_magnetization*tot_magnetization)/(t);
        //myfile << t << " " <<tot_energy/(N*N) <<" " <<  tot_magnetization/(N*N) << " " << heat_capacity) << " " <<susceptibility << "\n" ;
       // t += 0.02;
//}
        myfile.close();



    //cout << "Magnetization: " << tot_magnetization/MCnumber  << "N*N = " << N*N << endl;
    cout << MCnumber << endl;
    cout << "Expectation energy: " << tot_energy << endl;
    cout << "Exp energy squared: " << tot_energy_squared << endl;
    cout << "Magnetization: " << tot_magnetization  << "          N*N = " << N*N << endl;
    cout << "Magnetization squared: " << tot_magnetization_squared  << endl;

    cout << "Susceptibility: " << susceptibility << endl;
    cout << "Heat capacity: " << heat_capacity << endl;
    cout << "Variance energy" << sqrt(heat_capacity*t*t) << endl;


    return exp_x/double(MCnumber);
}


