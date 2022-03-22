#include <iostream>

class A
{
public:
    A()  { std::cout << "A::A()" << std::endl; }
    ~A()  { std::cout << "A::~A()" << std::endl; }
    std::string operator() ( const int& x ) const
    {
        return "int";
    }
};
  
class B
{
public:
    B()  { std::cout << "B::B()" << std::endl; }
    ~B()  { std::cout << "B::~B()" << std::endl; }
    std::string operator() ( const double& x ) const
    {
        return "double";
    }
};
  
class C: public A, public B
{
public:
    C()  { std::cout << "C::C()" << std::endl; }
    ~C()  { std::cout << "C::~C()" << std::endl; }  
};

template<typename ... Ts> 
class D : public Ts ...
{ 
public:
    D()  { std::cout << "D::D()" << std::endl; }
    ~D()  { std::cout << "D::~D()" << std::endl; }
};

int main( int argc, char **argv )
{
    D<A,B> d;
    std::cout << "d(1) = " << d(1) << std::endl;
    std::cout << "d(1.1) = " << d(1.1) << std::endl;
    return 0;
}
