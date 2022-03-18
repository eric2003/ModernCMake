#include <iostream>
#include <type_traits>

struct A { int i; };            // C-struct (POD)
class B : public A {};          // still POD (no data members added)
struct C : B { void fn(){} };   // still POD (member function)
struct D : C { D(){} };         // no POD (custom default constructor)

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_pod<int>::value )
        REF( std::is_pod<A>::value )
        REF( std::is_pod<B>::value )
        REF( std::is_pod<C>::value )
        REF( std::is_pod<D>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_pod_v<int> )
        REF( std::is_pod_v<A> )
        REF( std::is_pod_v<B> )
        REF( std::is_pod_v<C> )
        REF( std::is_pod_v<D> );
#   undef REF
    }
    return 0;
}

