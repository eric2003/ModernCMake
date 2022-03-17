#include <iostream>
#include <type_traits>

struct A { };
enum class B : int { x,y,z };

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_signed<int>::value )
        REF( std::is_signed<float>::value )
        REF( std::is_signed<unsigned long>::value )
        REF( std::is_signed<A>::value )
        REF( std::is_signed<B>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_signed_v<int> )
        REF( std::is_signed_v<float> )
        REF( std::is_signed_v<unsigned long> )
        REF( std::is_signed_v<A> )
        REF( std::is_signed_v<B> );
#   undef REF
    }
    return 0;
}

