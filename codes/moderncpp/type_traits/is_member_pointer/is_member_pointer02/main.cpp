#include <iostream>
#include <type_traits>
class A {};
struct B { int x; };
struct C { int x; float y; };

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        int B::* pt = &B::x;
        std::cout << std::boolalpha
        REF( std::is_member_pointer<int(A::*)>::value )
        REF( std::is_member_pointer<int(B*)>::value )
        REF( std::is_member_pointer<int B::*>::value )
        REF( std::is_member_pointer<float C::*>::value )
        REF( std::is_member_pointer<double C::*>::value )
        REF( std::is_member_pointer<void (B::*)()>::value )
        REF( std::is_member_pointer<decltype(pt)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        int B::* pt = &B::x;
        std::cout << std::boolalpha
        REF( std::is_member_pointer_v<int(A::*)> )
        REF( std::is_member_pointer_v<int(B*)> )
        REF( std::is_member_pointer_v<int B::*> )
        REF( std::is_member_pointer_v<float C::*> )
        REF( std::is_member_pointer_v<double C::*> )
        REF( std::is_member_pointer_v<void (B::*)()> )
        REF( std::is_member_pointer_v<decltype(pt)> );
#   undef REF
    }
    return 0;
}

