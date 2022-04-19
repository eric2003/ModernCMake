#include <omp.h>
#include <iostream>

int a = 12345;
#pragma omp threadprivate(a)

int main(int argc, char** argv)
{
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        
        // Turn off dynamic threads as required by threadprivate
        omp_set_dynamic(0);
        
        #pragma omp parallel copyin(a)
        {
            #pragma omp master
            {
                std::cout << "[First parallel region] Master thread changes the value of a to 67890.\n";
                a = 67890;
            }
        
            #pragma omp barrier
            std::cout << "[First parallel region] Thread " << omp_get_thread_num() << ": a = " << a << ".\n";
        }
        
        #pragma omp parallel copyin(a)
        {
            std::cout << "[Second parallel region] Thread " << omp_get_thread_num() << ": a = " << a << ".\n";
        }       
    }
    return 0;
}
