#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_floating_point<int>::value )
        REF( std::is_floating_point<float>::value )
        REF( std::is_floating_point<const double>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_floating_point_v<int> )
        REF( std::is_floating_point_v<float> )
        REF( std::is_floating_point_v<const double> );
#   undef REF
    }

    return 0;
}

