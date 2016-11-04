#include "MonteCarlo.h"

MonteCarlo::MonteCarlo()
{

}

double MonteCarlo::IntegrateOneStep(int N, double* f){

    double x = rand() % N;

    return f[x];
}

