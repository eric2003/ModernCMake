#include <iostream>

template < typename F >
void foo( F f )
{
    std::cout << f( 0 ) << std::endl;
    std::cout << f( 1 ) << std::endl;
    std::cout << "sizeof(f): " << sizeof(f) << std::endl;
}

auto func( int fac )
{
    return [&] ( int var ) {
        return var * fac;
    };
}

auto func1( int fac )
{
    return [=] ( int var ) {
        return var * fac;
    };
}

auto func2( double fac )
{
    return [=] ( double var ) {
        return var * fac;
    };
}

int main( int argc, char **argv )
{
    auto myfunc = func(2);
    foo( myfunc );
    auto myfunc1 = func1(2);
    foo( myfunc1 );
    auto myfunc2 = func2(2);
    foo( myfunc2 );	

    return 0;
}
