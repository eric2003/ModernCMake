#include <iostream>
#include <type_traits>

int a(int i){return i;}                           // function
int(*b)(int)=a;                                   // pointer to function
struct C { int operator()(int i){return i;} } c;  // function-like class

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_function<decltype(a)>::value )
        REF( std::is_function<decltype(b)>::value )
        REF( std::is_function<decltype(c)>::value )
        REF( std::is_function<C>::value )
        REF( std::is_function<int(int)>::value )
        REF( std::is_function<int(*)(int)>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_function_v<decltype(a)> )
        REF( std::is_function_v<decltype(b)> )
        REF( std::is_function_v<decltype(c)> )
        REF( std::is_function_v<C> )
        REF( std::is_function_v<int(int)> )
        REF( std::is_function_v<int(*)(int)> );
#   undef REF
    }
    return 0;
}

