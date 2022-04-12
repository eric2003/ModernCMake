#include <iostream>

template <typename T>
struct blah
{
    static constexpr T zero() { return 0; }
    static constexpr T lowest() { return 1.5 * 2; }
};

[[nodiscard]] constexpr float zero() noexcept
{
    return blah<float>::zero();
}

[[nodiscard]] constexpr float(min)() noexcept
{
    return blah<float>::lowest();
}

int main ( int argc, char **argv )
{
    {
       std::cout << zero() << std::endl;
       std::cout << min() << std::endl;
    }

    return 0;
}
