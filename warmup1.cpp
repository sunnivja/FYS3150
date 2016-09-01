using namespace std;
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>

double derivative_tan(double x, double h, double& out1, double& out2);
double derivative_2(double x, double h, double& out1);
//double writetofile(double h_val[], double derivs1,[] double derivs2[]);
double error(double f1[], double h_values[], double& error[]);
//ofstream ofile;

int main(int argc, char const *argv[])
{  
	//double h_values[100] = 0;
	double h = 0.001;
	double hmax = 0.1;
	double h_values[] = {};
	double derivatives_single[] = {};
	double derivatives_double[] = {};
	double output1 = 0;
	double output2 = 0;
	double error_single[] ={};
	double error_double[] ={};
	int n = 0;
	for (hmax; h < hmax; hmax -= h){
	 cout <<"h = "<< hmax << "  Single = " <<derivative_tan(sqrt(2), hmax, output1, output2) << " Double: "<< derivative_2(sqrt(2), hmax, output2) << endl;//<< "  Backward:" << derivative_2(sqrt(2), hmax, output1)<<endl;
	 //cout << hmax <<"," << output1 << endl;
	 h_values[n] = hmax;
	 derivatives_single[n] =  derivative_tan(sqrt(2), hmax, output1, output2);
	 derivatives_double[n] =  derivative_2(sqrt(2), hmax, output2);
	 n += 1;
	}
	
	//writetofile(h_values, derivatives_single, derivatives_double, "derivativeswarmup.txt");
	error(derivatives_single, h_values, error_single);
	error(derivatives_double, h_values, error_double);
	//writetofile(h_values, error_single, error_double, "feilwarmup.txt");
	return 0;
}


double derivative_tan(double x, double h, double& out1, double& out2)
{
	double f_der =  (atan(x+h) - atan(x-h))/(2*h);
	//double Oh =   2*(pow(tan(x), -1) + pow(tan(x), -3))*(h/4);
	double Oh = h*h;

	out1 = Oh;
	return f_der + Oh;
}

double derivative_2(double x, double h, double& out1){
	double f_der = (pow(tan(x), -1) - pow(tan(x - h), -1))/(2*h);
	out1 = 1./3 - f_der;
	return f_der;
}

/*
double writetofile(double h_val[], double derivs1[], double derivs2[], filename){
	/*
	int n = sizeof(h_val);
	int i = 0;
	std::ofstream outfile (filename,std::ofstream::binary);
	while (i < n){
	outfile.write(printf("%f Single: %f  Double:  %f .\n", h_val[i], derivs1[i], derivs2[i]));
	i+= 1;}
	outfile.close()
	*//*
	i = 0;
	N = sizeof(h_val);
	ofstream ofile;
	ofile.open(filename);
	while (i < N){
		ofile << printf("%f  %f  %f \n", h_val[i], derivs1[i], derivs2[i] );
	}

	ofile.close();

	//return 0;
}
*/
double error(double f1[], double h_values[], double& error[])
{	int N = sizeof(h_values);
	int n = 0;
	double f_exact[] = {};
	while (n < N)
	{
		f_exact[n] = 1/(1 + pow(h_values[n], 2));
		error[n] = log((f1[n] - f_exact[n])/(f_exact[n]));
		n += 1;

	}
	return error
}