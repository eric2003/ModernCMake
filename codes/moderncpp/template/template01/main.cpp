#include <iostream>

template <class T>
T foo(T t)
{
    return t;
}
 
int main( int argc, char **argv )
{
    std::cout << foo<int>(1) << std::endl;
    std::cout << foo<float>(1.1f) << std::endl;
    std::cout << foo<double>(1.2) << std::endl;
    return 0;
}
