#include <omp.h>
#include <iostream>


int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        #pragma omp parallel
        {

            #pragma omp for nowait
            for ( int i = 0; i < 4; ++ i )
            {
                std::cout << "[Thread " << omp_get_thread_num() << "] is running in first loop." << std::endl;
            }

            #pragma omp for
            for ( int i = 0; i < 4; ++ i )
            {
                std::cout << "[Thread " << omp_get_thread_num() << "] is running in second loop." << std::endl;
            }
        }
    }
    return 0;
}