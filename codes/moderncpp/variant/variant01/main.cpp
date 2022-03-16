#include <string>
#include <iostream>
#include <variant>
#include <string>
#include <variant>
#include <iostream>

int main( int argc, char **argv )
{
    std::variant<int, float> v, w;
    v = 12;
    std::cout << " std::get<int>(v) = " << std::get<int>(v) << std::endl;
    int i = std::get<int>(v);
    std::cout << " i = " << i << std::endl;
    w = std::get<int>(v);
    std::cout << " std::get<int>(v) = " << std::get<int>(v) << std::endl;
    w = std::get<0>(v);
    std::cout << " std::get<0>(v) = " << std::get<0>(v) << std::endl;
    w = v;
    std::cout << " std::get<int>(w) = " << std::get<int>(w) << std::endl;

    return 0;
}
