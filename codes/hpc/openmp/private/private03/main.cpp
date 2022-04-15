#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 10;
        omp_set_num_threads( nThreads );
        const int nSize = 1000;
        double a[ nSize ], b[ nSize ];
        for ( int i = 0; i < nSize; ++ i )
        {
            a[ i ] = 1;
        }
        double sum = 0;
        #pragma omp parallel for
        for ( int i = 0; i < nSize; ++ i )
        {
            sum += a[ i ];
            b[ i ] = sum;
        }

        std::cout << "sum = " << sum << std::endl;
    }

    return 0;
}