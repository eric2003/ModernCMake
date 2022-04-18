#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        // Use 2 threads when creating OpenMP parallel regions
        int nThreads = 2;
        omp_set_num_threads( nThreads );

        std::cout << std::endl;
        // Parallelise the for loop using the dynamic schedule
        #pragma omp parallel for schedule(guided)
        for ( int i = 0; i < 10; ++ i )
        {
            std::cout << "Thread " << omp_get_thread_num() << " processes iteration " << i << ".\n";
        }
    }
    return 0;
}
