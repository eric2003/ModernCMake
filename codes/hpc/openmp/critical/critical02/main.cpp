#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        int sum = 0;
        int sum1 = 0;

        #pragma omp parallel for
        for ( int i = 0; i < 100000; ++ i )
        {
            #pragma omp critical
            sum += 1;
            sum1 += 1;
        }
        std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;
    }
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        int sum = 0;
        int sum1 = 0;

        #pragma omp parallel for
        for ( int i = 0; i < 100000; ++ i )
        {
            #pragma omp critical
            sum += 1;
            #pragma omp critical
            sum1 += 1;
        }
        std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;
    }
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        int sum = 0;
        int sum1 = 0;

        #pragma omp parallel for
        for ( int i = 0; i < 100000; ++ i )
        {
            #pragma omp critical
            {
                sum += 1;
                sum1 += 1;
            }
        }
        std::cout << "sum = " << sum << " sum1 = " << sum1 << std::endl;
    }	

    return 0;
}
