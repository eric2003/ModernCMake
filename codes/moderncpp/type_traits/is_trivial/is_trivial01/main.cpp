#include <iostream>
#include <type_traits>

class A {};
class B { B() {} };
class C : B {};
class D { virtual void fn() {} };

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_trivial<int>::value )
        REF( std::is_trivial<A>::value )
        REF( std::is_trivial<B>::value )
        REF( std::is_trivial<C>::value )
        REF( std::is_trivial<D>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_trivial_v<int> )
        REF( std::is_trivial_v<A> )
        REF( std::is_trivial_v<B> )
        REF( std::is_trivial_v<C> )
        REF( std::is_trivial_v<D> );
#   undef REF
    }
    return 0;
}

