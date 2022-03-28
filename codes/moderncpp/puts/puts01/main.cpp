#include <cstdio>
#include <iostream>

int main( int argc, char **argv )
{
    {
        int v1 = std::puts("a");
        int v2 = std::puts("b");
        int v3 = std::puts("hello world");
        std::cout << " v1 = " << v1 << std::endl;
        std::cout << " v2 = " << v2 << std::endl;
        std::cout << " v3 = " << v3 << std::endl;
    }
    return 0;
}