#include <omp.h>
#include <iostream>


int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        #pragma omp parallel
        {
            // Threads print their first message
            std::cout << "[Thread " << omp_get_thread_num() << "] I print my first message." << std::endl;
            // Make sure all threads have printed their first message before moving on.
            #pragma omp barrier

            #pragma omp single
            for ( int i = 0; i < 10; ++ i )
            {
                std::cout << "[Thread " << omp_get_thread_num() << "] The barrier is complete, which means all threads have printed their first message." << std::endl;
            }

            // Threads print their second message
            std::cout << "[Thread " << omp_get_thread_num() << "] I print my second message." << std::endl;
        }
    }

    return 0;
}