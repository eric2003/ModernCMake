#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        int sum = 0;

        #pragma omp parallel
        {
            #pragma omp for
            for ( int i = 0; i < 100000; ++ i )
            {
                sum ++;
            }
        }
        std::cout << "sum= " << sum << std::endl;
    }
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        int sum = 0;
        int sum1 = 0;
        std::cout << std::endl;

        #pragma omp parallel
        {
            #pragma omp for
            for ( int i = 0; i < 100000; ++ i )
            {
                #pragma omp atomic
                sum ++;
                sum1 ++;
            }
        }
        std::cout << "sum= " << sum << " sum1= " << sum1 << std::endl;
    }
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        int sum = 0;
        int sum1 = 0;
        std::cout << std::endl;

        #pragma omp parallel
        {
            #pragma omp for
            for ( int i = 0; i < 100000; ++ i )
            {
                #pragma omp atomic
                sum ++;
                #pragma omp atomic
                sum1 ++;
            }
        }
        std::cout << "sum= " << sum << " sum1= " << sum1 << std::endl;
    }

    return 0;
}
