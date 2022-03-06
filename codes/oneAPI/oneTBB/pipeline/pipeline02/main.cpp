#include <iostream>
#include <vector>
#include <tbb/tick_count.h>
#include <tbb/parallel_for_each.h>

struct Data
{
    std::vector<float> arr;

    Data()
    {
        arr.resize( std::rand() % 100 * 500 + 10000 );
        for ( int i = 0; i < arr.size(); ++ i )
        {
            arr[ i ] = std::rand() * (1.f / (float)RAND_MAX);
        }
    }

    void step1()
    {
        for ( int i = 0; i < arr.size(); ++ i )
        {
            arr[ i ] += 3.14f;
        }
    }

    void step2()
    {
        std::vector<float> tmp( arr.size() );
        for ( int i = 1; i < arr.size() - 1; ++ i )
        {
            tmp[ i ] = arr[ i - 1 ] + arr[ i ] + arr[ i + 1 ];
        }
        std::swap(tmp, arr);
    }

    void step3()
    {
        for ( int i = 0; i < arr.size(); ++ i )
        {
            arr[ i ] = std::sqrt( std::abs( arr[i] ) );
        }
    }

    void step4()
    {
        std::vector<float> tmp( arr.size() );
        for ( int i = 1; i < arr.size() - 1; ++ i )
        {
            tmp[ i ] = arr[ i - 1 ] - 2 * arr[ i ] + arr[ i + 1 ];
        }
        std::swap( tmp, arr );
    }
};

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

    size_t n = 1 << 12;
    std::cout << " n = " << n << std::endl;

    std::vector<Data> datas( n );
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        for ( auto &v: datas )
        {
            v.step1();
            v.step2();
            v.step3();
            v.step4();
        }
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "test 1 " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        tbb::parallel_for_each( datas.begin(), datas.end(), [&] (Data &v) {
            v.step1();
            v.step2();
            v.step3();
            v.step4();
        });
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "test 2 " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    return 0;
}

