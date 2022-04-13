#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        //const int nThreads = 8;
        int nThreads = 8;
        const int nSize = 1000;
        double a[ nSize ], b[ nSize ], c[ nSize ];
        #pragma omp parallel for num_threads( nThreads )
        for ( int i = 0; i < nSize; ++ i )
        {
            c[ i ] = a[ i ] + b[ i ];
            int myid = omp_get_thread_num();
            if ( i == 200 )
            {
                std::cout << "i = " << i << " myid = " << myid << std::endl;
            }
            if ( i == 300 )
            {
                std::cout << "i = " << i << " myid = " << myid << std::endl;
            }
        }
    }

    return 0;
}