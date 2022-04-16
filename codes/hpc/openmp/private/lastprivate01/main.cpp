#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        int x = -1;
        std::cout << "before parallel " << " x = " << x << " addr = " << &x << std::endl;
        #pragma omp parallel for lastprivate(x)
        for ( int i = 0; i < 10; ++ i )
        {
            int myid = omp_get_thread_num();
            x = i;
            std::cout << "thread " << myid << " i = " << i << " x = " << x << " addr = " << &x << std::endl;
        }
        std::cout << "after parallel " << " x = " << x << " addr = " << &x << std::endl;
    }

    return 0;
}