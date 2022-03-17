#include <iostream>
#include <type_traits>
#include <complex>

int main( int argc, char **argv )
{
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_arithmetic<char>::value )
        REF( std::is_arithmetic<float>::value )
        REF( std::is_arithmetic<float*>::value )
        REF( std::is_arithmetic<std::complex<double>>::value );
#   undef REF
    }
    {
#   define REF(x) << #x " ?: " << x << '\n'
        std::cout << std::boolalpha
        REF( std::is_arithmetic_v<char> )
        REF( std::is_arithmetic_v<float> )
        REF( std::is_arithmetic_v<float*> )
        REF( std::is_arithmetic_v<std::complex<double>> );
#   undef REF
    }
    return 0;
}

