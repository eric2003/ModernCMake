#include <iostream>
#include <type_traits>

struct A { };
enum class B : int { x,y,z };

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_unsigned<int>::value )
        REF( std::is_unsigned<float>::value )
        REF( std::is_unsigned<unsigned long>::value )
        REF( std::is_unsigned<A>::value )
        REF( std::is_unsigned<B>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_unsigned_v<int> )
        REF( std::is_unsigned_v<float> )
        REF( std::is_unsigned_v<unsigned long> )
        REF( std::is_unsigned_v<A> )
        REF( std::is_unsigned_v<B> );
#   undef REF
    }
    return 0;
}

