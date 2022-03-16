#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    std::cout << std::boolalpha;
 
    std::cout << "std::remove_reference<int>::type is int? "
              << std::is_same<int, std::remove_reference<int>::type>::value << std::endl;
    std::cout << "std::remove_reference<int&>::type is int? "
              << std::is_same<int, std::remove_reference<int&>::type>::value << std::endl;
    std::cout << "std::remove_reference<int&&>::type is int? "
              << std::is_same<int, std::remove_reference<int&&>::type>::value << std::endl;
    std::cout << "std::remove_reference<const int&>::type is const int? "
              << std::is_same<const int,
                              std::remove_reference<const int&>::type>::value << std::endl;

    return 0;
}
