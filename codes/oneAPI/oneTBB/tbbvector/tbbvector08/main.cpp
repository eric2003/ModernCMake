#include <iostream>
#include <vector>
#include <cmath>
#include <tbb/tick_count.h>
#include <tbb/concurrent_vector.h>
#include <tbb/parallel_for.h>

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
    int count = 0;
    {
    tbb::tick_count t0 = tbb::tick_count::now();
    std::cout << "tbb::concurrent_vector for ( size_t i = 0; i < a.size(); ++ i ) " << std::endl;
    tbb::concurrent_vector<float> a(n);

    for ( size_t i = 0; i < a.size(); ++ i )
    {
        a[i] = count ++;
    }
    std::cout << std::endl;
    tbb::tick_count t1 = tbb::tick_count::now();
    std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
    tbb::concurrent_vector<float> b(n);

    tbb::tick_count t0 = tbb::tick_count::now();
    std::cout << "tbb::concurrent_vector for ( auto it = b.begin(); it != b.end(); ++ it ) " << std::endl;
    count = 0;
    for ( auto it = b.begin(); it != b.end(); ++ it )
    {
        *it = count ++;
    }
    tbb::tick_count t1 = tbb::tick_count::now();
    std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }

    return 0;
}

