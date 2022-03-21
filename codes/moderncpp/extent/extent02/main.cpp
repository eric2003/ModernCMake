#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    {
        typedef int mytype[][24][60];
        std::cout << "mytype array (int[][24][60]):" << std::endl;
        std::cout << "rank: " << std::rank<mytype>::value << std::endl;
        std::cout << "extent (0th dimension): " << std::extent<mytype,0>::value << std::endl;
        std::cout << "extent (1st dimension): " << std::extent<mytype,1>::value << std::endl;
        std::cout << "extent (2nd dimension): " << std::extent<mytype,2>::value << std::endl;
        std::cout << "extent (3rd dimension): " << std::extent<mytype,3>::value << std::endl;
    }
    {
        std::cout << std::extent<int[3]>::value << '\n'; //< default dimension is 0
        std::cout << std::extent<int[3][4], 0>::value << '\n';
        std::cout << std::extent<int[3][4], 1>::value << '\n';
        std::cout << std::extent<int[3][4], 2>::value << '\n';
        std::cout << std::extent<int[]>::value << '\n';

        const auto ext = std::extent<int[9]>{};
        std::cout << ext << '\n'; //< implicit conversion to std::size_t

        const int ints[] = {1,2,3,4};
        std::cout << std::extent<decltype(ints)>::value << '\n'; //< array size
    }

    return 0;
}
