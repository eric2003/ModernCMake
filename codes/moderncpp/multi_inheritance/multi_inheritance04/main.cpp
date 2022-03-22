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
};

int main( int argc, char **argv )
{
    auto d = D{ [](int) ->std::string { return "int"; },
                [](double) ->std::string { return "double"; }
              };

    std::cout << "d(1) = " << d(1) << std::endl;
    std::cout << "d(1.1) = " << d(1.1) << std::endl;

    D e{ [](int) ->std::string { return "int"; },
                [](double) ->std::string { return "double"; }
       };

    std::cout << "e(1) = " << e(1) << std::endl;
    std::cout << "e(1.1) = " << e(1.1) << std::endl;
    return 0;
}
