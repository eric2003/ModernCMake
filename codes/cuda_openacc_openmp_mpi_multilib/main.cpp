#include <omp.h>
#include <mpi.h>
#include "myopenacc.h"
#include "cuda_sub.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int numprocs,namelen,rank;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(processor_name, &namelen);
	printf("Hello from %d on %s out of %d\n",(rank+1),processor_name,numprocs);
	
	int num_gpus = -1;
	GetCudaDeviceCount( num_gpus );

	printf("number of host CPUs:\t%d\n", omp_get_num_procs());
	printf("number of CUDA devices:\t%d\n", num_gpus);
	
	test_open_acc();

	#pragma omp parallel num_threads(4)
	{
	    int nt = omp_get_thread_num();
		printf("Hello OneFLOW CFD: Hybrid MPI+Cuda+OpenACC+OpenMP! Thread = %d on CPU Rank%d on Machine %s\n", nt, rank + 1, processor_name);
	}

	MPI_Finalize();
	return 0;
}
