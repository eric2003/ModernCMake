#include <iostream>

inline namespace v1
{
    void print()
    {
        std::cout << "v1::print\n";
    }
}

namespace v2
{
    void print()
    {
        std::cout << "v2::print\n";
    }
}


int main( int argc, char **argv )
{
    v1::print();
    v2::print();
    print();

    return 0;
}

