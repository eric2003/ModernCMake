#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 8;
        omp_set_num_threads( nThreads );
        // Create the parallel region
        #pragma omp parallel
        {
            // Create the sections
            #pragma omp sections
            {
                // Generate the first section
                #pragma omp section
                {
                    std::cout << "Section 1 is executed by thread " << omp_get_thread_num() << std::endl;
                }

                // Generate the second section
                #pragma omp section
                {
                    std::cout << "Section 2 is executed by thread " << omp_get_thread_num() << std::endl;
                }
            }
        }
    }
 
    return 0;
}
