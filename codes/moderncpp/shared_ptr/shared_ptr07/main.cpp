#include <iostream>
#include <memory>
#include <vector>

struct C
{
    int num;
    std::shared_ptr<C> child;
    C * parent;
    C() {
        num = 1234;
        std::cout << "C::C()" << std::endl;
        std::cout << "this->child .use_count() = " << this->child.use_count() << std::endl;
        std::cout << "this->parent = " << this->parent << std::endl;
    }

    ~C() {
        std::cout << "C::~C()" << std::endl;
        std::cout << "this->child .use_count() = " << this->child.use_count() << std::endl;
        std::cout << "this->parent = " << this->parent << std::endl;
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
    std::shared_ptr<C> parent = std::make_shared<C>();
    std::shared_ptr<C> child = std::make_shared<C>();
    std::cout << "main child .use_count() 000 = " << child.use_count() << std::endl;
    std::cout << "main parent.use_count() 000 = " << parent.use_count() << std::endl;
    parent->child = child;
    child->parent = parent.get();

    std::cout << "main child .use_count() 111 = " << child.use_count() << std::endl;
    std::cout << "main parent.use_count() 111 = " << parent.use_count() << std::endl;

    parent = nullptr;
    child = nullptr;
    std::cout << "main child .use_count() 222 = " << child.use_count() << std::endl;
    std::cout << "main parent.use_count() 222 = " << parent.use_count() << std::endl;

    std::cout << "now return" << std::endl;
    return 0;
}
