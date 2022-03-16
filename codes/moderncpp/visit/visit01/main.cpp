#include <string>
#include <variant>
#include <vector>
#include <iostream>

using var_t = std::variant<int, long, double, std::string>;

int main( int argc, char **argv )
{
    {
        std::vector<var_t> vec = {10, 15l, 1.5, "hello"};
        for( auto& v: vec )
        {
            std::visit( [](auto&& arg){ std::cout << arg; }, v );
        }
        std::cout << std::endl;
    }
    {
        std::vector<var_t> vec = {10, 15l, 1.5, "hello"};
        for( auto& v: vec )
        {
            std::visit( [](auto&& arg){ std::cout << arg << ' '; }, v );
        }
        std::cout << std::endl;
    }

    return 0;
}
