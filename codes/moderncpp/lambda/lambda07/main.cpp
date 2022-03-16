#include <iostream>

template < typename F >
void foo( F f )
{
    std::cout << f( 0 ) << std::endl;
    std::cout << f( 1 ) << std::endl;
}

int main( int argc, char **argv )
{
    int fac = 2;
    auto myfunc = [=] ( int var ) {
        std::cout << " fac = " << fac << std::endl;
        return var * fac;
    };
    foo( myfunc );

    return 0;
}
