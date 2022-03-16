#include <iostream>
#include <variant>


int main( int argc, char **argv )
{
    {
        std::variant<int, float> v = 1;

        std::cout << std::get<int>(v) << std::endl;
        std::cout << std::get<0>(v) << std::endl;

        v = 2.3f;

        std::cout << std::get<float>(v) << std::endl;
        std::cout << std::get<int>(v) << std::endl;
    }

    return 0;
}
