#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <tbb/parallel_reduce.h>
#include <tbb/blocked_range.h>

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

    auto t0 = std::chrono::steady_clock::now();

    //float sum = tbb::parallel_reduce( tbb::blocked_range<size_t>(0, n), (float)0,
    //[&] ( tbb::blocked_range<size_t> r, float local_sum ) {
    //    for ( size_t i = r.begin(); i < r.end(); ++ i ) {
    //        local_sum += std::sin(i);
    //    }
    //    return local_sum;
    //}, [] (float x, float y) {
    //    return x + y;
    //});
    float sum = tbb::parallel_reduce( tbb::blocked_range<size_t>(0, n), (float)0,
        [&] ( tbb::blocked_range<size_t> r, float local_sum ) {
            for ( size_t i = r.begin(); i < r.end(); ++ i ) {
                local_sum += std::sin(i);
            }
            return local_sum;
        }, std::plus<float>()
        );
    std::cout << " sum = " << sum << std::endl;

    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
    std::cout << "time elapsed: " << ms << " ms" << std::endl;

    return 0;
}

