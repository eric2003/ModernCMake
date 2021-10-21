#include <omp.h>
#include "myopenacc.h"
#include "cuda_sub.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int num_gpus = -1;
	GetCudaDeviceCount( num_gpus );
	cout << "num_gpus = " << num_gpus << " from main.cpp \n";
	test_open_acc();
	#pragma omp parallel  
	cout << "Hello, openmp world!\n";
	return 0;
}
