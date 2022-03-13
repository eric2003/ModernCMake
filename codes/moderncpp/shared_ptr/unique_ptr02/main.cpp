#include <iostream>
#include <memory>

struct C {
    C() {
        std::cout << "C::C()" << std::endl;
    }

    ~C() {
        std::cout << "C::~C()" << std::endl;
    }
};

int main( int argc, char **argv )
{
    std::unique_ptr<C> p = std::make_unique<C>();
    std::cout << "00000" << std::endl;
    p = nullptr;
    std::cout << "11111" << std::endl;
    std::cout << "now return" << std::endl;
    return 0;
}
