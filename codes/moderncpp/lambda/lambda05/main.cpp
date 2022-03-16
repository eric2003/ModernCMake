#include <iostream>

template < typename F >
void foo( F f )
{
    std::cout << f( 0 ) << std::endl;
    std::cout << f( 1 ) << std::endl;
}

int main( int argc, char **argv )
{
    auto myfunc = [] ( int var ) -> int {
        return var * 2;
    };
    foo( myfunc );

    return 0;
}
