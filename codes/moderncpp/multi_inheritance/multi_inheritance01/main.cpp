#include <iostream>

class A
{
public:
    A()  { std::cout << "A::A()" << std::endl; }
    ~A()  { std::cout << "A::~A()" << std::endl; }  
};
  
class B
{
public:
    B()  { std::cout << "B::B()" << std::endl; }
    ~B()  { std::cout << "B::~B()" << std::endl; }  
};
  
class C: public A, public B
{
public:
    C()  { std::cout << "C::C()" << std::endl; }
    ~C()  { std::cout << "C::~C()" << std::endl; }  
};

  
int main( int argc, char **argv )
{
    C c;
    return 0;
}
