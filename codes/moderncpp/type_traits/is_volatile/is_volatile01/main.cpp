#include <iostream>
#include <type_traits>

class A {};

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_volatile<A>::value )
        REF( std::is_volatile<volatile A>::value )
        REF( std::is_volatile<volatile A&>::value )
        REF( std::is_volatile<volatile A&&>::value )
        REF( std::is_volatile<volatile A*>::value )
        REF( std::is_volatile<volatile A**>::value )
        REF( std::is_volatile<int>::value )
        REF( std::is_volatile<volatile int>::value )
        REF( std::is_volatile<volatile int*>::value )
        REF( std::is_volatile<int* volatile>::value )
        REF( std::is_volatile<volatile int&>::value )
        REF( std::is_volatile<volatile int&&>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_volatile_v<A> )
        REF( std::is_volatile_v<volatile A> )
        REF( std::is_volatile_v<volatile A&> )
        REF( std::is_volatile_v<volatile A&&> )
        REF( std::is_volatile_v<volatile A*> )
        REF( std::is_volatile_v<volatile A**> )
        REF( std::is_volatile_v<int> )
        REF( std::is_volatile_v<volatile int> )
        REF( std::is_volatile_v<volatile int*> )
        REF( std::is_volatile_v<int* volatile> )
        REF( std::is_volatile_v<volatile int&> )
        REF( std::is_volatile_v<volatile int&&> );
#   undef REF
    }

    return 0;
}

