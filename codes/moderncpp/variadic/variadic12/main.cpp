#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    {
        int dummy = 0;
        //(dummy, 0) = 42;
        (0, dummy) = 42;
        std::cout << " dummy = " << dummy << std::endl;
    }
    return 0;
}
