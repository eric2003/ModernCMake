#include <iostream>

template <typename... Args> bool plot()
{
    std::cout << "plot()" <<std::endl;
    return true;
}

int main( int argc, char **argv )
{
    plot();
    return 0;
}
