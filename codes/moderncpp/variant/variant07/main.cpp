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

auto add(std::variant<int, float> const &v1,
         std::variant<int, float> const &v2)
{
    std::variant<int, float> result;
    std::visit([&] (auto const &t1, auto const &t2) {
        result = t1 + t2;
    }, v1, v2);
    return result;
}

auto add1(std::variant<int, float> const &v1,
         std::variant<int, float> const &v2)
{
    return std::visit([&] (auto const &t1, auto const &t2)
               -> std::variant<int, float> {
        return t1 + t2;
    }, v1, v2);
}

int main( int argc, char **argv )
{
    {
        std::variant<int, float> v = 1;
        PrintInfo( v );
        v = 2.1f;
        PrintInfo( v );
        std::cout << std::endl;
    }
    {
        std::variant<int, float> v = 1;
        PrintInfo1( v );
        v = 2.1f;
        PrintInfo1( v );
        std::cout << std::endl;
    }
    {
        std::variant<int, float> v = 1;
        PrintInfo2( v );
        v = 2.1f;
        PrintInfo2( v );
        std::cout << std::endl;
    }
    {
        std::variant<int, float> v1 = 1;
        std::variant<int, float> v2 = 2.1f;
        PrintInfo2( add(v1, v2) );
        PrintInfo2( add(v1, 2.1f) );
        PrintInfo2( add(1, v2) );
        PrintInfo2( add(1, 2.1f) );
        std::cout << std::endl;
    }
    {
        std::variant<int, float> v1 = 1;
        std::variant<int, float> v2 = 10.1f;
        PrintInfo2( add1(v1, v2) );
        PrintInfo2( add1(v1, 10.1f) );
        PrintInfo2( add1(1, v2) );
        PrintInfo2( add1(1, 10.1f) );
        std::cout << std::endl;
    }
    return 0;
}
