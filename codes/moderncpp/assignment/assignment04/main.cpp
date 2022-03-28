#include <iostream>

void f( int i )
{
    std::cout << i << ' ';
}

int main( int argc, char **argv )
{
    {
        int dummy = -1;
        ((( dummy = (f(1), 1) ) = (f(2), 2)) = (f(3), 3));
        std::cout << std::endl;
    }

    return 0;
}
