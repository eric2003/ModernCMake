#include <iostream>
#include <vector>
#include <cmath>
#include <tbb/tick_count.h>
#include <tbb/parallel_for.h>
#include <tbb/task_arena.h>
#include <iostream>

int main( int argc, char **argv )
{
    size_t n = 1 << 26;
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n = " << n << std::endl;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;

    std::vector<float> a(n);
    tbb::tick_count t0 = tbb::tick_count::now();

    tbb::task_arena my_arena(4);
    my_arena.execute([&] {
        auto numprocs = tbb::this_task_arena::max_concurrency();   // 4
        std::cout << "numprocs = " << numprocs << std::endl;
        tbb::parallel_for(tbb::blocked_range<size_t>(0, n, n / (2 * numprocs)),
        [&] ( tbb::blocked_range<size_t> r ) {
            for ( size_t i = r.begin(); i < r.end(); ++ i )
            {
                a[i] = std::sin(i);
            }
        }, tbb::simple_partitioner{});
    });

    tbb::tick_count t1 = tbb::tick_count::now();
    std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;

    return 0;
}

