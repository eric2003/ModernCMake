#include <iostream>

template < typename F >
void foo( F f )
{
    std::cout << f( 0 ) << std::endl;
    std::cout << f( 1 ) << std::endl;
    std::cout << "sizeof(f): " << sizeof(f) << std::endl;
}

int main( int argc, char **argv )
{
    int fac = 2;
    int counter = 0;
    auto myfunc = [&] ( int var ) {
        std::cout << " fac = " << fac << std::endl;
        counter ++;
        std::cout << " counter = " << counter << std::endl;
        return var * fac;
    };
    foo( myfunc );
    std::cout << " main counter = " << counter << std::endl;

    return 0;
}
