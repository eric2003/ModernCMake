#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 2;
        omp_set_num_threads( nThreads );

        int val = 0;

        std::cout << "Value of \"val\" before the OpenMP parallel region: " << val << std::endl;
 
        #pragma omp parallel default(none) shared(std::cout) private(val)
        {
            // Step 1: thread 0 writes the value
            if ( omp_get_thread_num() == 0 )
            {
                std::cout << "Thread 0 sets the value of \"val\" to 123." << std::endl;
                val = 123;
            }

            // Threads wait each other before progressing to step 2
            #pragma omp barrier
            
            // Step 2: thread 1 reads the value
            if ( omp_get_thread_num() == 1 )
            {
                std::cout << "Thread 1 reads the value of \"val\": "<< val << std::endl;
            }
        }
        std::cout << "Value of \"val\" after the OpenMP parallel region: " << val << std::endl;
    }

    return 0;
}
