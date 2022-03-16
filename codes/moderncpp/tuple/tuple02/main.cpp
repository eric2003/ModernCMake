#include <iostream>
#include <tuple>

int main( int argc, char **argv )
{
    auto tup = std::tuple<int, float, char>(1, 2.0f, 'c');

    int   v0 = std::get<0>(tup);
    float v1 = std::get<1>(tup);
    char  v2 = std::get<2>(tup);

    std::cout << "v0 = " << v0 << std::endl;
    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    return 0;
}
