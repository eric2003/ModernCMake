#include <iostream>
#include <type_traits>

class A {};

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_scalar<int>::value )
        REF( std::is_scalar<A>::value )
        REF( std::is_scalar<A&>::value )
        REF( std::is_scalar<A*>::value )
        REF( std::is_scalar<int(int)>::value )
        REF( std::is_scalar<int(*)(int)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_scalar_v<int> )
        REF( std::is_scalar_v<A> )
        REF( std::is_scalar_v<A&> )
        REF( std::is_scalar_v<A*> )
        REF( std::is_scalar_v<int(int)> )
        REF( std::is_scalar_v<int(*)(int)> );
#   undef REF
    }
    return 0;
}

