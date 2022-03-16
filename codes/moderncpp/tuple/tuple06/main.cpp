#include <iostream>
#include <tuple>

struct A
{
    int x;
    float y;
};

int main( int argc, char **argv )
{
    {
        A a = {1, 2.0f};

        auto [x, y] = a;

        std::cout << x << ", " << y << std::endl;
    }
    return 0;
}
