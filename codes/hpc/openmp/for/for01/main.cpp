#include <omp.h>
#include <iostream>
void foo()
{
    int myid = omp_get_thread_num();
    std::cout << "foo: thread id = " << myid << std::endl;
}

void bar()
{
    int myid = omp_get_thread_num();
    std::cout << "bar: thread id = " << myid << std::endl;
}

void run( int i )
{
    int myid = omp_get_thread_num();
    std::cout << "run(" << i << "): thread id = " << myid << std::endl;
}

int main(int argc, char** argv)
{
    {
        int nThreads = 2;
        omp_set_num_threads( nThreads );
        #pragma omp parallel
        {
            foo();
            #pragma omp for
            for ( int i = 0; i < 3; ++ i )
            {
                run(i);
            }

            bar();
        }
    }

    return 0;
}