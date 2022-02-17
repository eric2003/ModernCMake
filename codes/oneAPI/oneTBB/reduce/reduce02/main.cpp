#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <tbb/task_group.h>

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

    float sum = 0;
    size_t maxt = 4;
    tbb::task_group tg;
    std::vector<float> sum_save(maxt);
    size_t dn = n / maxt;
    for ( size_t it = 0; it < maxt; ++ it )
    {
        size_t beg = it * dn;
        size_t end = std::min( n, (it + 1) * dn );
        tg.run( [&, it, beg, end] {
            float local_sum = 0;
            for ( size_t i = beg; i < end; ++ i ) {
                local_sum += std::sin(i);
            }
            sum_save[ it ] = local_sum;
        });
    }
    tg.wait();
    for ( size_t it = 0; it < maxt; ++ it ) {
        sum += sum_save[ it ];
    }

    std::cout << " sum = " << sum << std::endl;

    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
    std::cout << "time elapsed: " << ms << " ms" << std::endl;

    return 0;
}

