#include <iostream>
#include <vector>
#include <numeric>
#include <tbb/tick_count.h>
#include <tbb/parallel_for_each.h>
#include <tbb/parallel_pipeline.h>

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
    std::vector<float> result;
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
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        tbb::parallel_for_each( datas.begin(), datas.end(), [&] (Data &v) {
            v.step1();
        });
        tbb::parallel_for_each( datas.begin(), datas.end(), [&] (Data &v) {
            v.step2();
        });
        tbb::parallel_for_each( datas.begin(), datas.end(), [&] (Data &v) {
            v.step3();
        });
        tbb::parallel_for_each( datas.begin(), datas.end(), [&] (Data &v) {
            v.step4();
        });

        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "test 3 " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        auto it = datas.begin();
        tbb::parallel_pipeline(8
        , tbb::make_filter<void, Data *>(tbb::filter_mode::serial_in_order,
        [&] (tbb::flow_control &fc) -> Data * {
            if ( it == datas.end() )
            {
                fc.stop();
                return nullptr;
            }
            return &*it++;
        })
        , tbb::make_filter<Data *, Data *>(tbb::filter_mode::parallel,
        [&] (Data *v) -> Data * {
            v->step1();
            return v;
        })
        , tbb::make_filter<Data *, Data *>(tbb::filter_mode::parallel,
        [&] (Data *v) -> Data * {
            v->step2();
            return v;
        })
        , tbb::make_filter<Data *, Data *>(tbb::filter_mode::parallel,
        [&] (Data *v) -> Data * {
            v->step3();
            return v;
        })
        , tbb::make_filter<Data *, void>(tbb::filter_mode::parallel,
        [&] (Data *v) -> void {
            v->step4();
        })
        );

        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "test 4 " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        auto it = datas.begin();
        tbb::parallel_pipeline(8
        , tbb::make_filter<void, Data *>(tbb::filter_mode::serial_in_order,
        [&] (tbb::flow_control &fc) -> Data * {
            if ( it == datas.end() )
            {
                fc.stop();
                return nullptr;
            }
            return &*it++;
        })
        , tbb::make_filter<Data *, Data *>(tbb::filter_mode::parallel,
        [&] (Data *v) -> Data * {
            v->step1();
            return v;
        })
        , tbb::make_filter<Data *, Data *>(tbb::filter_mode::parallel,
        [&] (Data *v) -> Data * {
            v->step2();
            return v;
        })
        , tbb::make_filter<Data *, Data *>(tbb::filter_mode::parallel,
        [&] (Data *v) -> Data * {
            v->step3();
            return v;
        })
        , tbb::make_filter<Data *, float>(tbb::filter_mode::parallel,
        [&] (Data *v) -> float {
            float sum = std::reduce(v->arr.begin(), v->arr.end());
            return sum;
        })
        , tbb::make_filter<float, void>(tbb::filter_mode::serial_out_of_order,
        [&] (float sum) -> void {
            result.push_back(sum);
        })
        );

        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << "test 5 " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    return 0;
}

