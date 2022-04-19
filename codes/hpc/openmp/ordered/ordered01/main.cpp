#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        
        std::cout << std::endl;
        
        #pragma omp parallel for
        for ( int i = 1; i <= 8; ++ i )
        {
            std::cout << "Thread " << omp_get_thread_num() << " is executing iteration " << i << " \n";
        }           
    }
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        
        std::cout << std::endl;        
       
        #pragma omp parallel for ordered
        for ( int i = 1; i <= 8; ++ i )
        {
            #pragma omp ordered
            std::cout << "Thread " << omp_get_thread_num() << " is executing iteration " << i << " \n";
        }           
    }       
    return 0;
}
