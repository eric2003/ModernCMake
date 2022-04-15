#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        int i = 10;
        std::cout << "before parallel " << " i = " << i << " addr = " << &i << std::endl;
        #pragma omp parallel firstprivate(i)
        {
            int myid = omp_get_thread_num();
            std::cout << "thread " << myid << " i = " << i << " addr = " << &i << std::endl;
        }
        std::cout << "after parallel " << " i = " << i << " addr = " << &i << std::endl;
    }
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        int i = 10;
        std::cout << "before parallel " << " i = " << i << " addr = " << &i << std::endl;
        #pragma omp parallel firstprivate(i)
        {
            int myid = omp_get_thread_num();
            i += 2;
            std::cout << "thread " << myid << " i = " << i << " addr = " << &i << std::endl;
        }
        std::cout << "after parallel " << " i = " << i << " addr = " << &i << std::endl;
    }

    return 0;
}