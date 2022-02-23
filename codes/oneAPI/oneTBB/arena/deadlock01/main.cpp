#include <iostream>
#include <vector>
#include <cmath>
#include <tbb/tick_count.h>
#include <tbb/parallel_for.h>
#include <mutex>

int main( int argc, char **argv )
{
    size_t n = 1 << 13;
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n = " << n << std::endl;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;

    std::vector<float> a( n * n );
    tbb::tick_count t0 = tbb::tick_count::now();
    std::mutex mtx;

    tbb::parallel_for((size_t)0, (size_t)n, [&] (size_t i) {
        std::lock_guard lck(mtx);
        tbb::parallel_for((size_t)0, (size_t)n, [&] (size_t j) {
            a[ i * n + j ] = std::sin(i) * std::sin(j);
        });
    });
    tbb::tick_count t1 = tbb::tick_count::now();

    std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;

    return 0;
}

