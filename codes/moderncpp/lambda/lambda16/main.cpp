#include <iostream>

void foo( auto const &f )
{
    std::cout << f( 3.14f ) << std::endl;
    std::cout << f( 1 ) << std::endl;
    std::cout << "sizeof(f): " << sizeof(f) << std::endl;
}

int main( int argc, char **argv )
{
    auto mfun = [] <class T> ( T n ) {
        return n * 2;
    };
    foo( mfun );
    return 0;
}
