#include <iostream>
#include <memory>
#include <vector>

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

std::vector<std::unique_ptr<C>> ptrlist;

void foo( std::unique_ptr<C> p )
{
    p->Run();
    ptrlist.push_back( std::move( p ) );
}

void bar( C *p )
{
    p->Run();
}

int main( int argc, char **argv )
{
    std::unique_ptr<C> p = std::make_unique<C>();
    std::cout << "p.get() 0000 = " << p.get() << std::endl;
    C * raw_p = p.get();
    foo(std::move(p));
    std::cout << "p.get() 1111 = " << p.get() << std::endl;
    ptrlist.clear();
    raw_p->Run();
    std::cout << "now return" << std::endl;
    return 0;
}
