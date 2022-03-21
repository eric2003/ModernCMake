#include <iostream>
#include <cmath>
#include <string>

template <typename T>
struct Number {
    int absValue() {
        return std::abs(val);
    }
  T val{};
};

// template class Number<std::string>;           // (2)
// template int Number<std::string>::absValue(); // (3)

int main( int argc, char **argv )
{
    Number<std::string> numb;
    //numb.absValue();                         // (1)

    return 0;
}
