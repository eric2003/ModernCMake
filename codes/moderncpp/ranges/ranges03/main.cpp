#include <ranges>
#include <iostream>
#include <vector>
#include <algorithm>

int main( int argc, char **argv )
{
    {
        std::cout << "test1" << std::endl;
        std::vector v = {4, 3, 2, 1, 0, -1, -2};
        for (auto &&vi: v
             | std::views::filter([] (auto &&x) { return x >= 0; })
             ) {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "test2" << std::endl;
        std::vector v = {4, 3, 2, 1, 0, -1, -2};
        for (auto &&vi: v
             | std::views::filter([] (auto &&x) { return x >= 0; })
             | std::views::transform([] (auto &&x) { return std::sqrtf(x); })
             ) {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "test3" << std::endl;
        std::vector v = {4, 3, 2, 1, 0, -1, -2};
        std::cout << "v1 = " << std::endl;
        for (auto &&vi: v
             | std::views::filter([] (auto &&x) { return x >= 0; })
             | std::views::transform([] (auto &&x) { return x * x; })
             ) {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
        std::cout << "v2 = " << std::endl;
        for (auto &&vi: v)
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "test4" << std::endl;
        std::vector v = {4, 3, 2, 1, 0, -1, -2};
        std::cout << "v1 = " << std::endl;
        for (auto vi: v
             | std::views::filter([] (auto &x) { return x >= 0; })
             | std::views::transform([] (auto &x) { return x * x; })
             ) {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
        std::cout << "v2 = " << std::endl;
        for (auto &&vi: v)
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }
    {
        std::cout << "test5" << std::endl;
        std::vector v = {4, 3, 2, 1, 0, -1, -2};
        std::cout << "v1 = " << std::endl;
        for (auto &&vi: v
             | std::views::filter([] (auto x) { return x >= 0; })
             | std::views::transform([] (auto x) { return x * x; })
             ) {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
        std::cout << "v2 = " << std::endl;
        for (auto &&vi: v)
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
