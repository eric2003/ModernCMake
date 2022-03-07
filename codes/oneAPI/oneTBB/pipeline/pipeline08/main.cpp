#include <iostream>
#include <vector>
#include <mutex>
#include <numeric>
#include <tbb/tick_count.h>
#include <tbb/spin_mutex.h>
#include <tbb/parallel_pipeline.h>


float ArraySum( float * first, float * last )
{
    float sum=0;
    tbb::parallel_pipeline(4,
    tbb::make_filter<void,float*>( tbb::filter_mode::serial_in_order,
    [&] ( tbb::flow_control& fc ) -> float*{
        if ( first < last ) {
            std::cout << * first << std::endl;
            return first ++;
        } else {
            fc.stop();
            return nullptr;
        }
    }) &
    tbb::make_filter<float*,float>( tbb::filter_mode::parallel,
    [] ( float * p ) {
       return ( * p );
    }) &
    tbb::make_filter<float,void>( tbb::filter_mode::serial_in_order,
    [&] ( float x ) {
        sum += x;
    })
    );
    return sum;
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

    size_t n = 1 << 10;
    std::cout << " n  = " << n << std::endl;
    std::vector<float> arr( n, 1 );
    {
        std::vector<float> arr( n, 1 );
        tbb::tick_count t0 = tbb::tick_count::now();
        float sum = ArraySum( &arr[0], &arr[0] + n );
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "sum = " << sum << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }

    return 0;
}

