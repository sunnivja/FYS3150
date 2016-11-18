//Project 5

#include <random>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

// How to run from terminal:
// g++ -std=c++11 main.cpp

using namespace std;

void Metropolis(double* money, int nr_transactions, int nr_agents, double saving);
double sum_money(double* money, int nr_agents);

int main(int argc, char*argv[]){
	int nr_agents = stoi(argv[1]);
	int nr_transactions = stoi(argv[2]); 	// Should be at least 10^7
	int nr_simulations = 2; 	// Should be between 10^3 - 10^4

	double total_money = 0;
	int initial_money = stod(argv[3]);
	double total_money_new = 0;
	double saving = stod(argv[5]);
	//cout << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << " " << argv[5] << endl;
 

	// Make array with money, each element corresponding to one agent
	double* money = new double[nr_agents];


	//random_device epsilon();
	//mt19937 gen(epsilon());
	//uniform_int_distribution<> dis(0,nr_agents);
	
	for (int i = 0; i < nr_agents; i++){
		money[i] = initial_money;
	}
	total_money = sum_money(money, nr_agents);
	/*for (int i = 0; i < nr_agents; i++){
		cout << "money:  " << money[i] << endl;
	}*/


	cout << "Performing the Metropolis algorithm" << endl;
	for(int i=0; i<nr_simulations; i++)
{
	Metropolis(money, nr_transactions, nr_agents, saving);
}
	cout << "Done with the Metropolis" << endl;


	/*for (int i = 0; i < nr_agents; i++){
		cout << "money:  " << money[i] << endl;
	}*/

	//cout << sum_money(money, nr_agents) << endl;

	ofstream myfile;
	myfile.open(argv[4]);
	for (int i=0; i<nr_agents; i++){
		myfile << money[i] << endl;
	}
	myfile.close();

	


	return 0;
}

void Metropolis(double* money, int nr_transactions, int nr_agents, double saving){
	// Metropolis algorithm for transactions
	int completed_transactions = 0;
	//Initialize random int generator between 0 and number of agents
	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> random_int(0, nr_agents-1);

    //Initialize random double generator between 0 and 1
    uniform_real_distribution<double> random_double(0, 1);

	while (completed_transactions < nr_transactions){
		// Pick two random agents
		int i = random_int(gen);
		int j = random_int(gen);
		if (i != j){
		double epsilon = random_double(gen);
		//cout << epsilon << endl;
		double dm = (1 - saving)*(epsilon*money[j] - (1-epsilon)*money[i]);
		money[i] = money[i] + dm;
		money[j] = money[j] - dm;
		completed_transactions += 1;
		}
	//cout << money[i]<< endl;

	}
return;
}

double sum_money(double* money, int nr_agents){
	double total = 0;
		for (int i=0; i<nr_agents; i++){
			total += money[i];
		}
	return total;
}


