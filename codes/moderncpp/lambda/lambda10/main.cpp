#include <iostream>

template < typename F >
void foo( F f )
{
    std::cout << f( 0 ) << std::endl;
    std::cout << f( 1 ) << std::endl;
    std::cout << "sizeof(f): " << sizeof(f) << std::endl;
}

auto func()
{
    return [] ( int var ) {
        return var * 2;
    };
}

int main( int argc, char **argv )
{
    auto myfunc = func();
    foo( myfunc );

    return 0;
}
