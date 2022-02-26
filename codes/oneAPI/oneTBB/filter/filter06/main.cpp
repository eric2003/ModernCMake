#include <iostream>
#include <vector>
#include <cmath>
#include <tbb/tick_count.h>
#include <tbb/parallel_for.h>
#include <tbb/concurrent_vector.h>

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
        tbb::concurrent_vector<float> c;
        tbb::parallel_for(tbb::blocked_range<size_t>(0, n),
        [&] ( tbb::blocked_range<size_t> r ) {
            std::vector<float> local_c;
            for ( size_t i = r.begin(); i < r.end(); ++ i )
            {
                float val = std::sin(i);
                if ( val > 0 )
                {
                    local_c.push_back(val);
                }
            }
            auto it = c.grow_by( local_c.size() );
            for ( size_t i = 0; i < local_c.size(); ++ i )
            {
                *it ++ = local_c[i];
            }
        });
        std::cout << "c.size() = " << c.size() << std::endl;
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        tbb::concurrent_vector<float> d;
        tbb::parallel_for(tbb::blocked_range<size_t>(0, n),
        [&] ( tbb::blocked_range<size_t> r ) {
            std::vector<float> local_d;
            for ( size_t i = r.begin(); i < r.end(); ++ i )
            {
                float val = std::sin(i);
                if ( val > 0 )
                {
                    local_d.push_back(val);
                }
            }
            auto it = d.grow_by( local_d.size() );
            std::copy(local_d.begin(), local_d.end(), it);
        });
        std::cout << "d.size() = " << d.size() << std::endl;
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        tbb::concurrent_vector<float> e;
        tbb::parallel_for(tbb::blocked_range<size_t>(0, n),
        [&] ( tbb::blocked_range<size_t> r ) {
            std::vector<float> local_e;
            local_e.reserve( r.size() );
            for ( size_t i = r.begin(); i < r.end(); ++ i )
            {
                float val = std::sin(i);
                if ( val > 0 )
                {
                    local_e.push_back(val);
                }
            }
            auto it = e.grow_by( local_e.size() );
            std::copy( local_e.begin(), local_e.end(), it );
        });
        std::cout << "e.size() = " << e.size() << std::endl;
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    return 0;
}

