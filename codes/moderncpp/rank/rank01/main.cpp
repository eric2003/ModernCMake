#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    std::cout << std::rank<int>{} << std::endl;
 
    std::cout << std::rank<int[5]>{} << std::endl;
    std::cout << std::rank<int[5][5]>{} << std::endl;
    std::cout << std::rank<int[][5][5]>{} << std::endl;

    return 0;
}
