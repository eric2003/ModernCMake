#include <iostream>
#include <vector>
#include <mutex>
#include <tbb/tick_count.h>
#include <tbb/spin_mutex.h>
#include <tbb/parallel_pipeline.h>

tbb::spin_mutex mylock;
std::atomic<int> counter = 0;

void hw( int x, int v )
{
    int mycount = counter++;
    std::cout << "Hello, Stage " << x << "(" << mycount << "):(" << v << ")\n";
}

int main( int argc, char **argv )
{
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;

    size_t n = 1 << 26;
    std::cout << " n  = " << n << std::endl;

    {
        tbb::tick_count t0 = tbb::tick_count::now();
        int cdown = 3;
        tbb::parallel_pipeline(6
        , tbb::make_filter<void, int>(tbb::filter_mode::parallel,
        [&] (tbb::flow_control &fc) -> int {
            hw(1, 0);
            if ( !cdown )
            { 
                fc.stop();
                return 0;
            }
            return 1000 * cdown--;
        })
        & tbb::make_filter<int,float>(tbb::filter_mode::parallel,
        [&] ( int i ) -> int {
            hw( 2, i );
            return ++ i;
        })
        & tbb::make_filter<float,float>(tbb::filter_mode::parallel,
        [&] ( float f ) -> float {
            hw( 3, (int) f );
            return f + 1.0f; 
        })
        & tbb::make_filter<float,int>(tbb::filter_mode::parallel,
        [&] ( float f ) -> float {
            hw( 4, (int) f );
            return ( int )f + 1;
        })
        & tbb::make_filter<int,void>(tbb::filter_mode::parallel,
        [&] ( float f ) -> void {
            hw( 5, f ); 
            return;
        })
        );
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }

    return 0;
}

