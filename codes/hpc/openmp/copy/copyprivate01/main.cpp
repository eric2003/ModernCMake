#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        
        int a = 123;
        
        #pragma omp parallel default(none) shared(std::cout) firstprivate(a)
        {
            std::cout << "Thread " << omp_get_thread_num() << ": a = " << a << ".\n";
        
            #pragma omp barrier
        
            #pragma omp single copyprivate(a)
            {
                a = 456;
                std::cout << "Thread " << omp_get_thread_num() << " executes the single construct and changes a to " << a << ".\n";
            }
            std::cout << "Thread " << omp_get_thread_num() << ": a = " << a << ".\n";
        }        
    }   
    return 0;
}
