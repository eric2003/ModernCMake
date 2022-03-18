#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_void<int>::value )
        REF( std::is_void<void>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_void_v<int> )
        REF( std::is_void_v<void> );
#   undef REF
    }

    return 0;
}

