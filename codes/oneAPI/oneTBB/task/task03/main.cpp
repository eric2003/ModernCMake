#include <iostream>
#include <tbb/parallel_for.h>

void Foo( float a )
{
    std::cout << "a=" << a << std::endl;
}

class ApplyFoo {
    float *const my_a;
public:
    void operator()( const tbb::blocked_range<size_t>& r ) const {
        float *a = my_a;
        for( size_t i=r.begin(); i!=r.end(); ++i )
           Foo(a[i]);
    }
    ApplyFoo( float a[] ) :
        my_a(a)
    {}
};

void SerialApplyFoo( float a[], size_t n ) {
    for( size_t i=0; i!=n; ++i )
        Foo(a[i]);
}

void ParallelApplyFoo( float a[], size_t n ) {
    tbb::parallel_for(tbb::blocked_range<size_t>(0,n), ApplyFoo(a));
}

int main( int argc, char **argv )
{
    const size_t nSize = 4;
    float a[ nSize ] = { 1, 2, 3, 4 };
    ParallelApplyFoo( a, nSize );
    return 0;
}

