#include <omp.h>
#include <iostream>


int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        #pragma omp parallel
        {
            int tid = omp_get_thread_num();
            std::cout << "[Thread " << tid << "] Every thread executes this print." << std::endl;

            #pragma omp master
            for ( int i = 0; i < 10; ++ i )
            {
                int myid = omp_get_thread_num();
                std::cout << "[Thread " << myid << "] Only the master thread executes this print, which is me." << std::endl;
            }
        }
    }

    return 0;
}