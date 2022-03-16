#include <iostream>
#include <tuple>
#include <optional>
#include <cmath>

std::tuple<bool, float> mysqrt( float x )
{
    if ( x >= 0.0f )
    {
        return { true, std::sqrt(x) };
    }
    else
    {
        return { false, 0.0f };
    }
}

std::optional<float> myopt_sqrt( float x )
{
    if ( x >= 0.f )
    {
        return std::sqrt( x );
    }
    else
    {
        return std::nullopt;
    }
}

int main( int argc, char **argv )
{
    {
        auto [ success, value ] = mysqrt(4.0f);
        if ( success )
        {
            std::cout << " success mysqrt = " << value << std::endl;
        }
        else
        {
            std::cout << " failure mysqrt = " << value << std::endl;
        }
    }
    {
        auto [ success, value ] = mysqrt(-4.0f);
        if ( success )
        {
            std::cout << " success mysqrt = " << value << std::endl;
        }
        else
        {
            std::cout << " failure mysqrt = " << value << std::endl;
        }
    }
    {
        auto x = myopt_sqrt( -4.0f );
        std::cout << " myopt_sqrt( -4.0f ) = " << x.value_or( 0.0 ) << std::endl;
    }
    {
        auto x = myopt_sqrt( 4.0f );
        std::cout << " myopt_sqrt( 4.0f ) = " << x.value_or( 0.0 ) << std::endl;
    }
    {
        auto x = myopt_sqrt( 4.0f );
        if ( x.has_value() )
        {
            std::cout << " myopt_sqrt( 4.0f ) = " << * x << std::endl;
        }
        else
        {
            std::cout << " ERROR " << std::endl;
        }
    }
    {
        auto x = myopt_sqrt( -4.0f );
        if ( x.has_value() )
        {
            std::cout << " myopt_sqrt( -4.0f ) = " << * x << std::endl;
        }
        else
        {
            std::cout << " myopt_sqrt( -4.0f ) ERROR " << std::endl;
        }
    }	
    return 0;
}
