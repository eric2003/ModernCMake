#include <iostream>

template <typename... Args> bool plot()
{
    std::cout << "plot() number of Args = " << sizeof ... (Args) <<std::endl;
    return true;
}

bool plot()
{
    std::cout << "my plot()" <<std::endl;
    return true;
}

template <typename A, typename B>
bool plot( const A &a, const B &b, const std::string &format )
{
    std::cout << "plot 2 format = " << format << std::endl;
    return true;
}

int main( int argc, char **argv )
{
    plot();
    plot<>();
    plot<int>();
    plot<int, float>();
    int i = 0;
    int j = 1;
    plot( i, j, "haha" );
    return 0;
}
