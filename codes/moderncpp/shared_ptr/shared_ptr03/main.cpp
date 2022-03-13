#include <iostream>
#include <memory>
#include <vector>

struct C
{
    int num;
    C() {
        num = 1234;
        std::cout << "C::C()" << std::endl;
    }

    ~C() {
        std::cout << "C::~C()" << std::endl;
        num = -1234;
    }
    void Run()
    {
        std::cout << "C::Run() this->num = " << this->num << std::endl;
    }
};

std::vector<std::shared_ptr<C>> ptrlist;

void foo( std::shared_ptr<C> p )
{
    p->Run();
    ptrlist.push_back( std::move( p ) );
}
 
int main( int argc, char **argv )
{
    std::shared_ptr<C> p = std::make_shared<C>();
    std::cout << "p.use_count() 000 = " << p.use_count() << std::endl;
    foo(p);
    std::cout << "p.use_count() 111 = " << p.use_count() << std::endl;
    foo(p);
    std::cout << "p.use_count() 222 = " << p.use_count() << std::endl;
    ptrlist.clear();
    std::cout << "p.use_count() 333 = " << p.use_count() << std::endl;
    p->Run();
    std::cout << "now return" << std::endl;
    return 0;
}
