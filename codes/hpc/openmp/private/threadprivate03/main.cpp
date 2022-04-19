#include <omp.h>
#include <iostream>
#include <chrono>
#include <thread>

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
                using namespace std::chrono_literals;
                std::this_thread::sleep_for(200ms);
                numt = omp_get_num_threads(); 
            }
            #pragma omp barrier
            std::cout << "Hello World from thread " << tid << " of " << numt << ".\n";
        }
    }
    return 0;
}
