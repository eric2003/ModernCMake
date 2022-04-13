#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        int i = 10;
        std::cout << "before parallel " << " i = " << i << std::endl;
        #pragma omp parallel private(i)
        {
            int myid = omp_get_thread_num();
            i = 1000 + myid;
            std::cout << "thread " << myid << " i = " << i << std::endl;
        }
        std::cout << "after parallel " << " i = " << i << std::endl;
    }

    return 0;
}