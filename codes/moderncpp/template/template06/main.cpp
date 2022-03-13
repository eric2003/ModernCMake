#include <iostream>
#include <string>

template <int N>
void foo( std::string msg ) {
    for ( int i = 0; i < N; ++ i )
    {
        std::cout << msg << ' ';
    }
    std::cout << std::endl;
}

int main( int argc, char **argv )
{
    foo<1>("one");
    foo<2>("two");
    foo<3>("three");
    foo<4>("four");
    return 0;
}
