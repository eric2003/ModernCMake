#include <iostream>
#include <omp.h>

int main(int argc, char** argv)
{
    {
        int nCpuThreads = 8;
        omp_set_num_threads( nCpuThreads );
#pragma omp parallel
        {
            unsigned int cpu_thread_id = omp_get_thread_num();
            unsigned int num_cpu_threads = omp_get_num_threads();
            std::printf( "CPU thread %d (of %d)\n", cpu_thread_id, num_cpu_threads );
        }
    }
    {
        int nCpuThreads = 8;
        omp_set_num_threads( nCpuThreads );
		#ifdef USE_OMP
#pragma omp parallel
        {
            unsigned int cpu_thread_id = omp_get_thread_num();
            unsigned int num_cpu_threads = omp_get_num_threads();
            std::printf( "USE_OMP CPU thread %d (of %d)\n", cpu_thread_id, num_cpu_threads );
        }
		#endif
    }
    {
        int nCpuThreads = 8;
        omp_set_num_threads( nCpuThreads );
        {
            unsigned int cpu_thread_id = omp_get_thread_num();
            unsigned int num_cpu_threads = omp_get_num_threads();
            std::printf( "TEST 000 CPU thread %d (of %d)\n", cpu_thread_id, num_cpu_threads );
        }
    }
	{
        int nCpuThreads = 8;
        omp_set_num_threads( nCpuThreads );
#ifdef USE_OMP
#pragma omp parallel
#endif		
        {
            unsigned int cpu_thread_id = omp_get_thread_num();
            unsigned int num_cpu_threads = omp_get_num_threads();
            std::printf( "TEST 111 CPU thread %d (of %d)\n", cpu_thread_id, num_cpu_threads );
        }
    }
	{
        int nCpuThreads = 8;
        omp_set_num_threads( nCpuThreads );
#ifndef USE_OMP
#pragma omp parallel
#endif		
        {
            unsigned int cpu_thread_id = omp_get_thread_num();
            unsigned int num_cpu_threads = omp_get_num_threads();
            std::printf( "TEST 222 CPU thread %d (of %d)\n", cpu_thread_id, num_cpu_threads );
        }
    }

    return 0;
}