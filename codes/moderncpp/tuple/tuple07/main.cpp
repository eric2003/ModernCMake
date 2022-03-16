#include <iostream>
#include <tuple>
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
    return 0;
}
