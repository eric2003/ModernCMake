#include <iostream>
#include <string>

void print_float( float var )
{
    std::cout << var << std::endl;
}

void print_int( int var )
{
    std::cout << var << std::endl;
}

template < typename F >
void foo( F f )
{
    f( 0 );
    f( 1 );
}

int main( int argc, char **argv )
{
    foo( print_float );
    foo( print_int   );

    return 0;
}
