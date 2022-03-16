#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    std::cout << std::boolalpha;
    std::cout << "is_reference:" << std::endl;
    std::cout << "int: " << std::is_reference<int>::value << std::endl;
    std::cout << "int&: " << std::is_reference<int&>::value << std::endl;
    std::cout << "int&&: " << std::is_reference<int&&>::value << std::endl;

    return 0;
}
