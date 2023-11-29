#include <format>
#include <iostream>

int main ( int argc, char **argv )
{
    {
        const std::string message = std::format("{1}, {0}!", "world", "hello");
        std::cout << " message = " << message << "\n";
    }
    {
        std::cout << "\n\n";
        const std::string message = std::format("he{0}{0}o, {1}!", "l", "world");
        std::cout << " message = " << message << "\n";
    }

    return 0;
}
