
#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        int sum = 100;
        std::cout << std::endl;
        std::cout << "Before parallelism sum's address is " << &sum << " value is " << sum << std::endl;
        #pragma omp parallel for reduction(+ : sum)
        for ( int i = 1; i <= 4; ++ i )
        {
            std::cout << "thread " << omp_get_thread_num() << " sum's address is " << &sum << " value is " << sum << std::endl;
            sum += i;
        }
        std::cout << "After parallelism sum addr is " << &sum << " value is " << sum << std::endl;
    }
    {
        int nThreads = 4;
        omp_set_num_threads( nThreads );
        int sum = 100;
        std::cout << std::endl;
        std::cout << "Before parallelism sum's address is " << &sum << " value is " << sum << std::endl;
        #pragma omp parallel for reduction(+ : sum)
        for ( int i = 1; i <= 4; ++ i )
        {
            sum += i;
            std::cout << "thread " << omp_get_thread_num() << " sum's address is " << &sum << " value is " << sum << std::endl;
        }
        std::cout << "After parallelism sum addr is " << &sum << " value is " << sum << std::endl;
    }
    return 0;
}
