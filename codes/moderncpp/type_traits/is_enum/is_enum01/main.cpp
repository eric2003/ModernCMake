#include <iostream>
#include <type_traits>

enum A {first,second,third};       // unscoped enum (C-style)
class B {};
enum class C {alpha,beta,gamma};   // scoped enum (C++11-style)

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_enum<A>::value )
        REF( std::is_enum<B>::value )
        REF( std::is_enum<C>::value )
        REF( std::is_enum<decltype(C::alpha)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_enum_v<A> )
        REF( std::is_enum_v<B> )
        REF( std::is_enum_v<C> )
        REF( std::is_enum_v<decltype(C::alpha)> );
#   undef REF
    }

    return 0;
}

