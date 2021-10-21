#include <stdio.h>
#include "cuda_lib.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int num_gpus = -1;
    GetCudaDeviceCount( &num_gpus );
	cout << "num_gpus = " << num_gpus << " from myopenacc_main.cpp \n";
    
	cout << "Hello from main.cpp using std::cout\n";
    return 0;
}
