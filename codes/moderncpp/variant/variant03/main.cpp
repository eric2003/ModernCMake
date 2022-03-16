#include <variant>
#include <string>
#include <iostream>

void PrintInfo(std::variant<int, float> const &v)
{
    if ( std::holds_alternative<int>(v) )
    {
        std::cout << std::get<int>(v) << std::endl;
    }
    else if ( std::holds_alternative<float>(v) )
    {
        std::cout << std::get<float>(v) << std::endl;
    }
}
int main( int argc, char **argv )
{
    {
        std::variant<int, float> v = 1;
        PrintInfo( v );
        v = 2.1f;
        PrintInfo( v );
    }
    return 0;
}
