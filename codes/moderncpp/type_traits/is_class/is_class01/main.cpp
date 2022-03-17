#include <iostream>
#include <type_traits>

struct A {};
class B {};
union C {int i; float f;};
enum class D {x,y,z};

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_class<A>::value )
        REF( std::is_class<B>::value )
        REF( std::is_class<C>::value )
        REF( std::is_class<D>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_class_v<A> )
        REF( std::is_class_v<B> )
        REF( std::is_class_v<C> )
        REF( std::is_class_v<D> );
#   undef REF
    }
    return 0;
}

