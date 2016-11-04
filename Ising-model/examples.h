#ifndef EXAMPLES_H
#define EXAMPLES_H
#include <ostream>
#include <string>
using namespace std;

class Examples
{
public:
    Examples();
    double Random_spins2D(int N, int n, double T, double &exp_energy_squared, double &magnetic_moment, double &magnetic_moment_squared, int init);
    void Random_spins3D(int N, double*** spins);
};

#endif // EXAMPLES_H
