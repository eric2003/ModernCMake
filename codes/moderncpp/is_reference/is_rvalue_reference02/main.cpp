#include <iostream>
#include <type_traits>

class A {};

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_rvalue_reference_v<A> )
        REF( std::is_rvalue_reference_v<A&> )
        REF( std::is_rvalue_reference_v<A&&> )
        REF( std::is_rvalue_reference_v<int> )
        REF( std::is_rvalue_reference_v<int&> )
        REF( std::is_rvalue_reference_v<int&&> );
#   undef REF
    }

    return 0;
}

