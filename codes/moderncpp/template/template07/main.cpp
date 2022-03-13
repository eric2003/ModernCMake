#include <iostream>
#include <string>

template <int N = 1, class T>
void foo( T msg )
{
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
    foo(1);
    foo<2>(2.0);
    foo<4>('%');
    foo<4>("%%");
    return 0;
}
