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
    {
        std::unique_ptr<C> p = std::make_unique<C>();
    }
    std::cout << "now return" << std::endl;
    return 0;
}
