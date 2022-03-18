#include <iostream>
#include <type_traits>
class A {};
int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_member_pointer<int(A::*)>::value )
        REF( std::is_member_pointer<int>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_member_pointer_v<int(A::*)> )
        REF( std::is_member_pointer_v<int> );
#   undef REF
    }
    return 0;
}

