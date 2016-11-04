#include <stdio.h>
#include "examples.h"
#include "isingmodel.h"
#include "MonteCarlo.h"
#include <time.h>
#include "random"
#include <fstream>
//#include "mpi.h"



int main(int argc, char *argv[])
{
    int numprocs, my_rank;
    //MPI_Init = (&argc, &argv);
    //MPI_Comm_size = (MPI_COMM_WORLD, &numprocs);
    //MPI_Comm_rank = (MPI_COMM_WORLD, &my_rank);



    Examples examples;
    int N = 20;
    double T = 1.0;
    srand(time(NULL));
    //examples.Random_spins2D(N, n, T, "test.txt");

    int no_MC_cycles = 20000;
    int random_system = 0;
    int ordered_system = 1;

    double exp_energy_squared = 0; double magnetic_moment = 0; double magnetic_moment_squared = 0;

    ofstream myfile;
    myfile.open("test.dat");

    for (int i=0; i<(no_MC_cycles+1); i+=100){
        int MC_cycles = i;
        double exp_energy = examples.Random_spins2D(N, MC_cycles, T, exp_energy_squared, magnetic_moment, magnetic_moment_squared, random_system);
        myfile << MC_cycles << " " << exp_energy << " "<< exp_energy_squared<< " "<< magnetic_moment << " " << magnetic_moment_squared <<  "\n" ;

    }
    myfile.close();
    //MPI_finalize();


    return 0;
}
