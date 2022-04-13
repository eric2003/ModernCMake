#include <iostream>
#include <omp.h>

int main(int argc, char** argv)
{
    {
        omp_set_num_threads(4);
        std::cout << "omp_in_parallel = " << omp_in_parallel() << std::endl;
        #pragma omp parallel
            #pragma omp master
            {
                std::cout << "omp_in_parallel = " << omp_in_parallel() << std::endl;
            }
    }

    return 0;
}