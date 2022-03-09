#include <bitset>
#include <iostream>
#include <stdexcept>
#include <string>
 
int main( int argc, char **argv )
{
    try {
        std::bitset<4>{"012"}; // Throws: only '0' or '1' expected
    } catch (std::invalid_argument const& ex) {
        std::cout << "#1: " << ex.what() << '\n';
    }
 
    try {
        [[maybe_unused]] int f = std::stoi("ABBA"); // Throws: no conversion
    } catch (std::invalid_argument const& ex) {
        std::cout << "#2: " << ex.what() << '\n';
    }
 
    try {
        [[maybe_unused]] float f = std::stof("(3.14)"); // Throws: no conversion
    } catch (std::invalid_argument const& ex) {
        std::cout << "#3: " << ex.what() << '\n';
    }

    return 0;
}
