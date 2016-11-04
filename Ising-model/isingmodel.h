#ifndef ISINGMODEL_H
#define ISINGMODEL_H


class Isingmodel
{
public:
    Isingmodel();
    double Partition_function(int N, double* E, double T);
    double Energy(double** spins, int N);
    double Magnetic_moment(double** spins, int N);
    double Exp_values(int N, double**spins, double T, int MCnumber, double& exp_energy_squared, double& magnetic_moment, double& magnetic_moment_squared);
};

#endif // ISINGMODEL_H
