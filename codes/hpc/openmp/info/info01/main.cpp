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
        int nthread = 4;
#pragma omp parallel num_threads( nthread )
        Hello();
    }

    return 0;
}