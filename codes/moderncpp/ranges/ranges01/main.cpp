#include <iostream>
#include <ranges>

int main( int argc, char **argv )
{
    for ( int i : std::views::iota(0, 6) )
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}
