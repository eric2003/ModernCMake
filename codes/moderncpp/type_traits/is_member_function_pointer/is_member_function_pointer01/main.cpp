#include <iostream>
#include <type_traits>
struct A { void fn() {}; };

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        void(A::*pt)() = &A::fn;
        std::cout << std::boolalpha
        REF( std::is_member_function_pointer<A*>::value )
        REF( std::is_member_function_pointer<void(A::*)()>::value )
        REF( std::is_member_function_pointer<decltype(pt)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        void(A::*pt)() = &A::fn;
        std::cout << std::boolalpha
        REF( std::is_member_function_pointer_v<A*> )
        REF( std::is_member_function_pointer_v<void(A::*)()> )
        REF( std::is_member_function_pointer_v<decltype(pt)> );
#   undef REF
    }
    return 0;
}

