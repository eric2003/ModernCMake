#include <iostream>
#include <tuple>

int main( int argc, char **argv )
{
    {
        std::cout << "tuple test1" << std::endl;
        auto tup = std::tuple<int, float, char>(1, 2.0f, 'c');
        int   v0 = std::get<0>(tup);
        float v1 = std::get<1>(tup);
        char  v2 = std::get<2>(tup);

        std::cout << "v0 = " << v0 << std::endl;
        std::cout << "v1 = " << v1 << std::endl;
        std::cout << "v2 = " << v2 << std::endl;
    }
    {
        std::cout << "tuple test2" << std::endl;
        auto tup = std::tuple<int, float, char>(1, 2.0f, 'c');
        auto v0 = std::get<0>(tup);
        auto v1 = std::get<1>(tup);
        auto v2 = std::get<2>(tup);

        std::cout << "v0 = " << v0 << std::endl;
        std::cout << "v1 = " << v1 << std::endl;
        std::cout << "v2 = " << v2 << std::endl;
    }
    {
        std::cout << "tuple test3" << std::endl;
        auto tup = std::tuple<int, float, char>(1, 2.0f, 'c');
        auto [v0, v1, v2] = tup;

        std::cout << "v0 = " << v0 << std::endl;
        std::cout << "v1 = " << v1 << std::endl;
        std::cout << "v2 = " << v2 << std::endl;
    }
    {
        std::cout << "tuple test4" << std::endl;
        auto tup = std::tuple<int, float, char>(1, 2.0f, 'c');
        auto &&[v0, v1, v2] = tup;

        std::cout << "v0 = " << v0 << std::endl;
        std::cout << "v1 = " << v1 << std::endl;
        std::cout << "v2 = " << v2 << std::endl;
        v0 = -1;
        std::cout << "v0 = " << v0 << std::endl;
        std::cout << "v1 = " << v1 << std::endl;
        std::cout << "v2 = " << v2 << std::endl;

        std::cout << "std::get<0>(tup) = " << std::get<0>(tup) << std::endl;
        std::cout << "std::get<1>(tup) = " << std::get<1>(tup) << std::endl;
        std::cout << "std::get<2>(tup) = " << std::get<2>(tup) << std::endl;
    }

    return 0;
}
