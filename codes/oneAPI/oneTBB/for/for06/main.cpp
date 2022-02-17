#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range2d.h>

int main( int argc, char **argv )
{
    //size_t n = 1 << 26;
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

    std::vector<float> a(n * n);

    auto t0 = std::chrono::steady_clock::now();

    tbb::parallel_for(tbb::blocked_range2d<size_t>(0, n, 0, n),
    [&] (tbb::blocked_range2d<size_t> r) {
        for ( size_t i = r.cols().begin(); i < r.cols().end(); ++ i ) {
            for ( size_t j = r.rows().begin(); j < r.rows().end(); ++ j ) {
                a[ i * n + j ] = std::sin(i) * std::sin(j);
            }
        }
    });

    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
    std::cout << "time elapsed: " << ms << " ms" << std::endl;

    return 0;
}

