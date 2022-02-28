#include <iostream>
#include <tbb/tick_count.h>

int fib( int n )
{
    if ( n < 2 )
    {
        return n;
    }
    int f1 = fib( n - 1 );
    int f2 = fib( n - 2 );
    return f1 + f2;
}

int main( int argc, char **argv )
{
    size_t n = 1 << 27;
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n = " << n << std::endl;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        int nfib = 39;
        std::cout << " fib( " << nfib << " ) = " <<  fib( nfib ) << std::endl;
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }

    return 0;
}

