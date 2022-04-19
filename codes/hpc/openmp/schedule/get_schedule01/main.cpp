#include <omp.h>
#include <iostream>

int main(int argc, char** argv)
{
    {
        // Use 2 threads when creating OpenMP parallel regions
        int nThreads = 2;
        omp_set_num_threads( nThreads );

        // Get the schedule to apply when a runtime schedule is encountered
        omp_sched_t kind;
        int chunk_size;
        omp_get_schedule(&kind, &chunk_size);
        std::cout << " schedule is applied, with chunks made of " << chunk_size << "iteration" << ( (chunk_size > 1) ? "s" : ""%s) << ".\n";


    }
    return 0;
}
