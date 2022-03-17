#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_fundamental<unsigned>::value )
        REF( std::is_fundamental<float>::value )
        REF( std::is_fundamental<float*>::value )
        REF( std::is_fundamental<decltype(nullptr)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_fundamental_v<unsigned> )
        REF( std::is_fundamental_v<float> )
        REF( std::is_fundamental_v<float*> )
        REF( std::is_fundamental_v<decltype(nullptr)> );
#   undef REF
    }

    return 0;
}

