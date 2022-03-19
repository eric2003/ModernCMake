#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    typedef int mytype[][24][60];
    std::cout << "mytype array (int[][24][60]):" << std::endl;
    std::cout << "rank: " << std::rank<mytype>::value << std::endl;
    std::cout << "extent (0th dimension): " << std::extent<mytype,0>::value << std::endl;
    std::cout << "extent (1st dimension): " << std::extent<mytype,1>::value << std::endl;
    std::cout << "extent (2nd dimension): " << std::extent<mytype,2>::value << std::endl;
    std::cout << "extent (3rd dimension): " << std::extent<mytype,3>::value << std::endl;

    return 0;
}
