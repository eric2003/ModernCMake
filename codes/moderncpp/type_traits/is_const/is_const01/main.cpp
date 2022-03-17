#include <iostream>
#include <type_traits>

class A {};

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_const<int>::value )
        REF( std::is_const<const int>::value )
        REF( std::is_const<const int*>::value )
        REF( std::is_const<int* const>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_const_v<int> )
        REF( std::is_const_v<const int> )
        REF( std::is_const_v<const int*> )
        REF( std::is_const_v<int* const> );
#   undef REF
    }
    return 0;
}

