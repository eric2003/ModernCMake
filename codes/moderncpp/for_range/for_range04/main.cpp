#include <iostream>
#include <vector>
#include <ranges>

int main( int argc, char **argv )
{
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
        auto results = numbers | std::views::filter([](int n){ return n % 2 == 0; })
                               | std::views::transform([](int n){ return n * 2; });
                               
        for ( auto v: results ) std::cout << v << " ";     // 4 8 12
        std::cout << std::endl;
    }
    {
        std::vector<int> vec = { -2, -1, 0, 1, 2, 3, 4, 5 };
        std::cout << "vec1 = " << std::endl;
        for ( int vi : vec | std::views::filter([] (int x) { return x >= 0; } )
                           | std::views::transform([] (int x) { return x * x; } )
            )
        {
            //vi += 10; // increments the value in the vector
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
        std::cout << "vec2 = " << std::endl;
        for ( auto v: vec ) std::cout << v << " ";     // 4 8 12
        std::cout << std::endl;
    }
    {
        std::vector<int> vec = { -2, -1, 0, 1, 2, 3, 4, 5 };
        std::cout << "vec1 = " << std::endl;
        for ( int && vi : vec | std::views::filter([] (int & x) { return x >= 0; } )
                              | std::views::transform([] (int & x) { return x * x; } )
            )
        {
            std::cout << vi << ' ';
        }
        std::cout << std::endl;
        std::cout << "vec2 = " << std::endl;
        for ( auto v: vec ) std::cout << v << " ";     // 4 8 12
        std::cout << std::endl;
    }	

    return 0;
}
