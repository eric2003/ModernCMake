#include <iostream>
#include <type_traits>

struct A { };
struct B { void fn(){} };
struct C { int x; };

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_empty<int>::value )
        REF( std::is_empty<A>::value )
        REF( std::is_empty<B>::value )
        REF( std::is_empty<C>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_empty_v<int> )
        REF( std::is_empty_v<A> )
        REF( std::is_empty_v<B> )
        REF( std::is_empty_v<C> );
#   undef REF
    }
    return 0;
}

