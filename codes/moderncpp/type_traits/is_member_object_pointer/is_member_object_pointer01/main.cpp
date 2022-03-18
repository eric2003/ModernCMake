#include <iostream>
#include <type_traits>
struct A { int x; };

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        int A::* pt = &A::x;
        std::cout << std::boolalpha
        REF( std::is_member_object_pointer<int(A*)>::value )
        REF( std::is_member_object_pointer<int A::*>::value )
        REF( std::is_member_object_pointer<decltype(pt)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        int A::* pt = &A::x;
        std::cout << std::boolalpha
        REF( std::is_member_object_pointer_v<int(A*)> )
        REF( std::is_member_object_pointer_v<int A::*> )
        REF( std::is_member_object_pointer_v<decltype(pt)> );
#   undef REF
    }
    return 0;
}

