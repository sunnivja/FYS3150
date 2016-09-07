#include <vector>
#include <iostream>

using namespace std;

int main(int numArguments, char **arguments) {
	vector<double> myVector(100, 0);
	for(int i=0; i<myVector.size(); i++) { 
		myVector[i] = 2*i;
	}

	myVector.clear();

	
	return 0;
}