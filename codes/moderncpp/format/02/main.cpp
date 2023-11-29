#include <format>
#include <iostream>

int main ( int argc, char **argv )
{
    {
        const std::string message = std::format("{}, {}!", "hello", "world");
        std::cout << " message = " << message << "\n";
        const std::string message1 = std::format("{}, {}!", "hello", "world");
        std::cout << " message1 = " << message1;
        std::cout << " message1 = " << message1;
    }
    {
        std::cout << "\n\n";
        const std::string message = std::format("{}, {}!", "hello", "world");
        std::cout << " message = " << message << "\n";
        const std::string message1 = std::format("{}, {}!\n", "hello", "world");
        std::cout << " message1 = " << message1;
        std::cout << " message1 = " << message1;
    }

    return 0;
}
