#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );

        // Variable that will be private
        int val = 1;

        std::cout << "Value of \"val\" before the OpenMP parallel for is " << val << std::endl;
 
        #pragma omp parallel for linear(val:2)
        for ( int i = 0; i < 10; ++ i )
        {
             std::cout << "Thread " << omp_get_thread_num() << " sees \"val\" = " <<  val << " at iteration " << i << std::endl;
        }

        std::cout << "Value of \"val\" after the OpenMP parallel for is " << val << std::endl;
    }
 
    return 0;
}
