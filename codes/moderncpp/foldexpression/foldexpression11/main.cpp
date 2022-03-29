#include <iostream>

template <typename ... Ts>
auto min(Ts... ts)
{
    auto vmin = (ts, ...);
    ( (ts < vmin ? vmin = ts : 0), ... );
    return vmin;
}

int main( int argc, char **argv )
{
    {
        std::cout << min(3, 1, 2, 4) << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << min(100, 300, 200) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
