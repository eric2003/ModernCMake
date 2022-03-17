#include <iostream>
#include <type_traits>

class A {};

int main( int argc, char **argv )
{
    {
        std::cout << std::boolalpha;
        std::cout << std::is_lvalue_reference<A>::value << '\n';
        std::cout << std::is_lvalue_reference<A&>::value << '\n';
        std::cout << std::is_lvalue_reference<A&&>::value << '\n';
        std::cout << std::is_lvalue_reference<int>::value << '\n';
        std::cout << std::is_lvalue_reference<int&>::value << '\n';
        std::cout << std::is_lvalue_reference<int&&>::value << '\n';
    }
    {
        std::cout << std::boolalpha;
        std::cout << std::is_lvalue_reference_v<A> << '\n';
        std::cout << std::is_lvalue_reference_v<A&> << '\n';
        std::cout << std::is_lvalue_reference_v<A&&> << '\n';
        std::cout << std::is_lvalue_reference_v<int> << '\n';
        std::cout << std::is_lvalue_reference_v<int&> << '\n';
        std::cout << std::is_lvalue_reference_v<int&&> << '\n';
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_lvalue_reference<A>::value )
        REF( std::is_lvalue_reference<A&>::value )
        REF( std::is_lvalue_reference<A&&>::value )
        REF( std::is_lvalue_reference<int>::value )
        REF( std::is_lvalue_reference<int&>::value )
        REF( std::is_lvalue_reference<int&&>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_lvalue_reference_v<A> )
        REF( std::is_lvalue_reference_v<A&> )
        REF( std::is_lvalue_reference_v<A&&> )
        REF( std::is_lvalue_reference_v<int> )
        REF( std::is_lvalue_reference_v<int&> )
        REF( std::is_lvalue_reference_v<int&&> );
#   undef REF
    }

    return 0;
}
