#include <iostream>

template <class T = int>
T foo()
{
    return 1;
}

int main( int argc, char **argv )
{
    std::cout << foo<int>() << std::endl;
    std::cout << foo<float>() << std::endl;
    std::cout << foo<double>() << std::endl;
    std::cout << foo() << std::endl;
    return 0;
}
