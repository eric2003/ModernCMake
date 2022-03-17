#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_integral<char>::value )
        REF( std::is_integral<int>::value )
        REF( std::is_integral<float>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_integral_v<char> )
        REF( std::is_integral_v<int> )
        REF( std::is_integral_v<float> );
#   undef REF
    }
    return 0;
}

