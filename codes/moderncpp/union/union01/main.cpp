#include <iostream>
 
union SuperFloat
{
    float f;
    int i;
};

int RawMantissa(SuperFloat f) 
{ 
    return f.i & ((1 << 23) - 1); 
}
int RawExponent(SuperFloat f) 
{
    return (f.i >> 23) & 0xFF; 
}
 
int main( int argc, char **argv )
{
    {
        SuperFloat x;
        x.f = 1.1234f;
        std::cout << " RawMantissa( x ) = " << RawMantissa( x ) << std::endl;
        std::cout << " RawExponent( x ) = " << RawExponent( x ) << std::endl;
    }

    return 0;
}
