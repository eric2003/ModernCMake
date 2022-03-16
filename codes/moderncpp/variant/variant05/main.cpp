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

void PrintInfo1(std::variant<int, float> const &v)
{
    if ( v.index() == 0 )
    {
        std::cout << std::get<0>(v) << std::endl;
    }
    else if ( v.index() == 1 )
    {
        std::cout << std::get<1>(v) << std::endl;
    }
}

void PrintInfo2(std::variant<int, float> const &v)
{
    std::visit
    (  [&] ( auto const &t )
       {
           std::cout << t << std::endl;
       },
       v
    );
}

int main( int argc, char **argv )
{
    {
        std::variant<int, float> v = 1;
        PrintInfo( v );
        v = 2.1f;
        PrintInfo( v );
    }
    {
        std::variant<int, float> v = 1;
        PrintInfo1( v );
        v = 2.1f;
        PrintInfo1( v );
    }
    {
        std::variant<int, float> v = 1;
        PrintInfo2( v );
        v = 2.1f;
        PrintInfo2( v );
    }	
    return 0;
}
