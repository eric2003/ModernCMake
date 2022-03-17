#include <iostream>
#include <type_traits>

union A { int i; float f; };        // named union
struct B {
  union { int foo; float bar; };    // anonymous member union
};

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_union<int>::value )
        REF( std::is_union<A>::value )
        REF( std::is_union<B>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_union_v<int> )
        REF( std::is_union_v<A> )
        REF( std::is_union_v<B> );
#   undef REF
    }
    return 0;
}

