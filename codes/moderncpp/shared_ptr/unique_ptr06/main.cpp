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

std::unique_ptr<C> pp;

void foo( std::unique_ptr<C> p )
{
    p->Run();
    pp = std::move( p );
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
    raw_p->Run();
    std::cout << "now return" << std::endl;
    return 0;
}
