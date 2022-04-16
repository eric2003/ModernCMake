#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        int sum = 0;

        #pragma omp parallel for
        for ( int i = 0; i < 100000; ++ i )
        {
            sum += 1;
        }
        std::cout << "sum = " << sum << std::endl;

    }
    return 0;
}
