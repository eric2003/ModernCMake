#include <iostream>

void foo( int f(int) )
{
    std::cout << f( 0 ) << std::endl;
    std::cout << f( 1 ) << std::endl;
    std::cout << "sizeof(f): " << sizeof(f) << std::endl;
}

int main( int argc, char **argv )
{
    foo([] (int n) {
        return n * 2;
    });

    return 0;
}
