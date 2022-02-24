#include <iostream>
#include <vector>
#include <cmath>
#include <tbb/tick_count.h>
#include <tbb/concurrent_vector.h>

int main( int argc, char **argv )
{
    size_t n = 1 << 10;
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

    tbb::concurrent_vector<float> a;

    for ( size_t i = 0; i < n; ++ i )
    {
        auto it = a.grow_by(2);
        *it++ = std::cos(i);
        *it++ = std::sin(i);
    }

    std::cout << " n = " << n << " a.size() = " << a.size() << std::endl;

    tbb::tick_count t1 = tbb::tick_count::now();
    std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;

    return 0;
}

