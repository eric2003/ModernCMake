#include <iostream>
#include <string>

template <class T>
T foo(T t)
{
    return t;
}

std::string foo( const std::string &t )
{
    return t + "!";
}

int main( int argc, char **argv )
{
    std::cout << foo<int>(1) << std::endl;
    std::cout << foo<float>(1.1f) << std::endl;
    std::cout << foo<double>(1.2) << std::endl;
    std::cout << foo<std::string>("hello") << std::endl;
    std::cout << foo<std::string>(std::string("hello")) << std::endl;

    std::cout << std::endl;
    std::cout << foo(1) << std::endl;
    std::cout << foo(1.1f) << std::endl;
    std::cout << foo(1.2) << std::endl;
    std::cout << foo("hello") << std::endl;
    std::cout << foo(std::string("hello")) << std::endl;
    return 0;
}
