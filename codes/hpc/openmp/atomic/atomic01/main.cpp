#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 2;
        omp_set_num_threads( nThreads );
        int sum = 0;

        #pragma omp parallel
        {
            for ( int i = 0; i < 4; ++ i )
            {
                std::cout << "thread id = " << omp_get_thread_num() << " i = " << i << std::endl;
            }
        }
    }
    {
        int nThreads = 2;
        omp_set_num_threads( nThreads );
        int sum = 0;
        std::cout << std::endl;
        #pragma omp parallel
        {
            #pragma omp for
            for ( int i = 0; i < 4; ++ i )
            {
                std::cout << "thread id = " << omp_get_thread_num() << " i = " << i << std::endl;
            }
        }
    }

    return 0;
}
