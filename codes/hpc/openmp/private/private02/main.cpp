#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 10;
        omp_set_num_threads( nThreads );
        const int nSize = 1000;
        double a[ nSize ], b[ nSize ], c[ nSize ], d[ nSize ];
        for ( int i = 0; i < nSize; ++ i )
        {
            a[ i ] = i;
            b[ i ] = nSize - i;
        }
        double tmp;
        #pragma omp parallel for num_threads( nThreads )
        for ( int i = 0; i < nSize; ++ i )
        {
            tmp = a[ i ] / b[ i ];
            c[ i ] = tmp * tmp;
            //int myid = omp_get_thread_num();
            //int nThr = omp_get_num_threads();
            //std::cout << "i " << i << " c = " << c[ i ] << " myid = " << myid << " nThread = " << nThr << std::endl;
        }

        for ( int i = 0; i < nSize; ++ i )
        {
            tmp = a[ i ] / b[ i ];
            d[ i ] = tmp * tmp;
            //if ( std::abs( d[ i ] - c[ i ] ) > 1.0e-8 )
            if ( d[ i ] != c[ i ] )
            {
                std::cout << "i " << i << " c = " << c[ i ] << " d = " << d[ i ] << std::endl;
                break;
            }
        }
    }

    return 0;
}