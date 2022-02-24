#include <iostream>
#include <vector>
#include <cmath>
#include <tbb/tick_count.h>
#include <tbb/parallel_for.h>
#include <tbb/task_arena.h>
#include <iostream>

int main( int argc, char **argv )
{
    size_t n = 1 << 5;
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n = " << n << std::endl;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;

    tbb::tick_count t0 = tbb::tick_count::now();

    tbb::task_arena my_arena(4);
    my_arena.execute([&] {
        //tbb::parallel_for(tbb::blocked_range<size_t>(0, n, 16),
        tbb::parallel_for(tbb::blocked_range<size_t>(0, n, 8),
        [&] (tbb::blocked_range<size_t> r) {
            std::cout << "thread " << tbb::this_task_arena::current_thread_index() << " size = " << r.size() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }, tbb::static_partitioner{});
    });

    tbb::tick_count t1 = tbb::tick_count::now();

    std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;

    return 0;
}

