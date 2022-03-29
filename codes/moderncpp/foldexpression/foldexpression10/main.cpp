#include <iostream>

template <typename ... Ts>
auto get_first(Ts... ts)
{
    std::common_type_t<decltype(ts)...> result;
    ((result = ts, true) || ...);
    return result;
}

template <typename ... Ts>
auto get_last(Ts... ts)
{
    return (ts, ...);
}

int main( int argc, char **argv )
{
    {
        std::cout << get_last(1, 2, 3) << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << get_last(1, 3, 2) << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << get_last( 1, 2, 3, 4, 5, 6, 1000 ) << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
