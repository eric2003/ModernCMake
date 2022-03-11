#include <ranges>
#include <iostream>
#include <algorithm>

int main( int argc, char **argv )
{
    for (int i : std::ranges::iota_view{1, 10})
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int i : std::views::iota(1, 10))
        std::cout << i << ' ';
    std::cout << '\n';
 
    struct Bound
    {
        int bound;
        bool operator==(int x) const { return x == bound; }
    };
    for (int i : std::views::iota(1, Bound{10}))
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int i : std::views::iota(1) | std::views::take(9))
        std::cout << i << ' ';
    std::cout << '\n';
 
    std::ranges::for_each(std::views::iota(1, 10), [](int i) {
        std::cout << i << ' ';
    });
    std::cout << '\n';
    return 0;
}
