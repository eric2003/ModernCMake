#include <iostream>
#include <type_traits>

class A {};

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_pointer<A>::value )
        REF( std::is_pointer<A&>::value )
        REF( std::is_pointer<A&&>::value )
        REF( std::is_pointer<A*>::value )
        REF( std::is_pointer<A**>::value )
        REF( std::is_pointer<int>::value )
        REF( std::is_pointer<int*>::value )
        REF( std::is_pointer<int&>::value )
        REF( std::is_pointer<int&&>::value )
        REF( std::is_pointer<int(*)(int)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_pointer_v<A> )
        REF( std::is_pointer_v<A&> )
        REF( std::is_pointer_v<A&&> )
        REF( std::is_pointer_v<A*> )
        REF( std::is_pointer_v<A**> )
        REF( std::is_pointer_v<int> )
        REF( std::is_pointer_v<int*> )
        REF( std::is_pointer_v<int&> )
        REF( std::is_pointer_v<int&&> )
        REF( std::is_pointer_v<int(*)(int)> );
#   undef REF
    }

    return 0;
}

