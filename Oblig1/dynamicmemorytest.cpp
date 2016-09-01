//#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{   //Two operators:
    // & address-of operator
    // * dereference operator



    int *array = new int[10];
    *array = 1337;
    cout << array << endl;
    cout << array[0] << endl;
    array[1] = 10;
    *(array + 1) = 10;
    cout << array[1] << endl;

    return 0;
}