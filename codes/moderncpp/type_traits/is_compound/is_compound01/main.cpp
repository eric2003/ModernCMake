#include <iostream>
#include <type_traits>
class A {};
int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_compound<A>::value )
        REF( std::is_compound<long int>::value )
        REF( std::is_compound<float>::value )
        REF( std::is_compound<float*>::value )
        REF( std::is_compound<float&>::value )
        REF( std::is_compound<float&&>::value )
        REF( std::is_compound<decltype(nullptr)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_compound_v<A> )
        REF( std::is_compound_v<long int> )
        REF( std::is_compound_v<float> )
        REF( std::is_compound_v<float*> )
        REF( std::is_compound_v<float&> )
        REF( std::is_compound_v<float&&> )
        REF( std::is_compound_v<decltype(nullptr)> );
#   undef REF
    }

    return 0;
}

