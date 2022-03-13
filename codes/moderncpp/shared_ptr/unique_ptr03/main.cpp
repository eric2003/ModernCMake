#include <iostream>
#include <memory>

struct C
{
    C() {
        std::cout << "C::C()" << std::endl;
    }

    ~C() {
        std::cout << "C::~C()" << std::endl;
    }
    void Run()
    {
        std::cout << "C::Run()" << std::endl;
    }
};

void foo( std::unique_ptr<C> p )
{
    p->Run();
}

int main( int argc, char **argv )
{
    std::unique_ptr<C> p = std::make_unique<C>();
    foo(p); //error
    std::cout << "now return" << std::endl;
    return 0;
}
