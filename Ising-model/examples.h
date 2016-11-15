#ifndef EXAMPLES_H
#define EXAMPLES_H
#include <ostream>
#include <string>
using namespace std;

class Examples
{
public:
    Examples();
    void Random_spins2D(int N, int n, double T, double &exp_energy_squared, double &magnetic_moment, double &magnetic_moment_squared, int init);
};

#endif // EXAMPLES_H
