
#include <omp.h>
#include <iostream>

#define ARRAY_SIZE    (10240)
float A[ARRAY_SIZE];
float B[ARRAY_SIZE];
float C[ARRAY_SIZE];

int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );

        std::cout << std::endl;
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            A[i] = i * 2.3;
            B[i] = i + 4.6;
        }
	    
        double start = omp_get_wtime();
		const int nLoop = 1000000;
        for ( int loop = 0; loop < nLoop; ++ loop )
        {
            for ( int i = 0; i < ARRAY_SIZE; ++ i )
            {
                C[i] = A[i] * B[i];
            }
        }
        double end = omp_get_wtime();
        std::cout << "Work consumed " << end - start << " seconds\n";
    }
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );

        std::cout << std::endl;
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            A[i] = i * 2.3;
            B[i] = i + 4.6;
        }
	    
        double start = omp_get_wtime();
		const int nLoop = 1000000;
        for ( int loop = 0; loop < nLoop; ++ loop )
        {
			#pragma omp simd
            for ( int i = 0; i < ARRAY_SIZE; ++ i )
            {
                C[i] = A[i] * B[i];
            }
        }
        double end = omp_get_wtime();
        std::cout << "Work consumed " << end - start << " seconds\n";
    }

    return 0;
}
