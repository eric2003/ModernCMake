#include <iostream>
#include <omp.h>

void Hello(void)
{
    int my_id = omp_get_thread_num();
    int my_rank = omp_get_num_threads();
    std::cout << "Hello from thread " << my_id << " of " << my_rank << std::endl;
}


int main(int argc, char** argv)
{
    {
        int nthreads = 4;
#pragma omp parallel num_threads( nthreads )
        Hello();
    }
    {
        int nthreads = 8;
        omp_set_num_threads( nthreads );
        int my_rank = omp_get_num_threads();
        std::cout << "num_threads =  " <<  my_rank << std::endl;
        #pragma omp parallel
        {
            Hello();
        }
    }
    {
        int nthreads = 6;
        omp_set_num_threads( nthreads );
        int my_rank = omp_get_num_threads();
        std::cout << "num_threads =  " <<  my_rank << std::endl;
        #pragma omp parallel
        {
            Hello();
        }
    }	

    return 0;
}