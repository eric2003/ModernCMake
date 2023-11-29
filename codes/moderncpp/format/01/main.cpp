#include <format>
#include <iostream>

int main ( int argc, char **argv )
{
    const std::string message = std::format("{}, {}!", "hello", "world");
    std::cout << " message = " << message << "\n";

    return 0;
}
