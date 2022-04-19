#include <omp.h>
#include <iostream>

int tid;
#pragma omp threadprivate( tid )

int main(int argc, char** argv)
{
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        int numt = -1;
        #pragma omp parallel default( shared )
        {
            int j;
            tid = omp_get_thread_num();
            if ( tid == 0 )
            {
                numt = omp_get_num_threads(); 
            }
        }
        #pragma omp parallel default( shared )
        std::cout << "Hello World from thread " << tid << " of " << numt << ".\n";
    }
    return 0;
}
