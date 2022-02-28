#include <iostream>
#include <vector>
#include <tbb/tick_count.h>
#include <tbb/parallel_invoke.h>

template < typename T >
void quick_sort( T * data, size_t size )
{
    if ( size < 1 )
    {
        return;
    }
    size_t mid = std::hash<size_t>{}( size );
    mid ^= std::hash<void *>{}( static_cast<void *>( data ) );
    mid %= size;
    std::swap( data[ 0 ], data[ mid ] );
    T pivot = data[ 0 ];
    size_t left = 0, right = size - 1;
    while ( left < right )
    {
        while ( left < right && !( data[ right ] < pivot ) )
        {
            right --;
        }
        if ( left < right )
        {
            data[ left ++ ] = data[ right ];
        }
        while ( left < right && data[ left ] < pivot )
        {
            left ++;
        }
        if ( left < right )
        {
            data[ right -- ] = data[ left ];
        }
    }
    data[ left ] = pivot;
    quick_sort( data, left );
    quick_sort( data + left + 1, size - left - 1 );
}

template < typename T >
void quick_sort1( T * data, size_t size )
{
    if ( size < 1 )
    {
        return;
    }
    size_t mid = std::hash<size_t>{}( size );
    mid ^= std::hash<void *>{}( static_cast<void *>( data ) );
    mid %= size;
    std::swap( data[ 0 ], data[ mid ] );
    T pivot = data[ 0 ];
    size_t left = 0, right = size - 1;
    while ( left < right )
    {
        while ( left < right && !( data[ right ] < pivot ) )
        {
            right --;
        }
        if ( left < right )
        {
            data[ left ++ ] = data[ right ];
        }
        while ( left < right && data[ left ] < pivot )
        {
            left ++;
        }
        if ( left < right )
        {
            data[ right -- ] = data[ left ];
        }
    }
    data[ left ] = pivot;
    tbb::parallel_invoke([&] {
        quick_sort1( data, left );
    }, [&] {
        quick_sort1( data + left + 1, size - left - 1 );
    });
}

template < typename T >
void quick_sort2( T * data, size_t size )
{
    if ( size < 1 )
    {
        return;
    }

    if ( size < ( 1 << 16 ) )
    {
        std::sort(data, data + size, std::less<T>{});
        return;
    }
    size_t mid = std::hash<size_t>{}( size );
    mid ^= std::hash<void *>{}( static_cast<void *>( data ) );
    mid %= size;
    std::swap( data[ 0 ], data[ mid ] );
    T pivot = data[ 0 ];
    size_t left = 0, right = size - 1;
    while ( left < right )
    {
        while ( left < right && !( data[ right ] < pivot ) )
        {
            right --;
        }
        if ( left < right )
        {
            data[ left ++ ] = data[ right ];
        }
        while ( left < right && data[ left ] < pivot )
        {
            left ++;
        }
        if ( left < right )
        {
            data[ right -- ] = data[ left ];
        }
    }
    data[ left ] = pivot;
    tbb::parallel_invoke([&] {
        quick_sort2( data, left );
    }, [&] {
        quick_sort2( data + left + 1, size - left - 1 );
    });
}

int main( int argc, char **argv )
{
    size_t n = 1 << 24;
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n = " << n << std::endl;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;
    std::vector<int> arr( n );
    std::generate( arr.begin(), arr.end(), std::rand );	
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        std::sort( arr.begin(), arr.end(), std::less<int>{} );
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << " std::sort " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        quick_sort( arr.data(), arr.size() );
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << " quick_sort " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        quick_sort1( arr.data(), arr.size() );
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << " quick_sort1 " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    {
        tbb::tick_count t0 = tbb::tick_count::now();
        quick_sort2( arr.data(), arr.size() );
        tbb::tick_count t1 = tbb::tick_count::now();
        std::cout << " quick_sort2 " << std::endl;
        std::cout << "time elapsed: " << ( t1 - t0 ).seconds() * 1000 << " ms" << std::endl;
    }
    return 0;
}

