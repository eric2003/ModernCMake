#include <iostream>

template <typename ... Ts>
auto get_first(Ts... ts)
{
    std::common_type_t<decltype(ts)...> result;
    ((result = ts, true) || ...);
    return result;
}

int main( int argc, char **argv )
{
    {
        std::cout << get_first(1, 2, 3) << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << get_first(2, 1, 3) << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << get_first(1000, 1, 2) << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
