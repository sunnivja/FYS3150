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
    srand(time(NULL));
    //int numprocs, my_rank;
    //MPI_Init = (&argc, &argv);
    //MPI_Comm_size = (MPI_COMM_WORLD, &numprocs);
    //MPI_Comm_rank = (MPI_COMM_WORLD, &my_rank);

    Examples examples;
    Isingmodel isingmodel;
    int N = 2;
    double T = 1.0;
    int random_system = 0;
    int ordered_system = 1;



    double exp_energy_squared = 0; double magnetic_moment = 0; double magnetic_moment_squared = 0;
    int MC_cycles =1000000;
    examples.Random_spins2D(N, MC_cycles, T, exp_energy_squared, magnetic_moment, magnetic_moment_squared, random_system);

    return 0;
}
