#include <iostream>
#include <type_traits>

class A {};

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_object<int>::value )
        REF( std::is_object<int&>::value )
        REF( std::is_object<int&&>::value )
        REF( std::is_object<A>::value )
        REF( std::is_object<A&>::value )
        REF( std::is_object<A*>::value )
        REF( std::is_object<int(int)>::value )
        REF( std::is_object<int(*)(int)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_object_v<int> )
        REF( std::is_object_v<int&> )
        REF( std::is_object_v<int&&> )
        REF( std::is_object_v<A> )
        REF( std::is_object_v<A&> )
        REF( std::is_object_v<A*> )
        REF( std::is_object_v<int(int)> )
        REF( std::is_object_v<int(*)(int)> );
#   undef REF
    }

    return 0;
}

