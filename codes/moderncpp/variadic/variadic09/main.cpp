#include <iostream>
#include <tuple>

template<typename ... Ts> 
struct Overload : public Ts ...
{
	/*
    Overload()
    {
        std::cout << "Overload()::Overload()\n";
    }
    ~Overload()
    {
        std::cout << "Overload()::~Overload()\n";
    }
	*/
    using Ts::operator() ...;
};

template<typename T> 
struct MyOverload : public T
{
    MyOverload()
    {
        std::cout << "MyOverload()::MyOverload()\n";
    }
    ~MyOverload()
    {
        std::cout << "MyOverload()::~MyOverload()\n";
    }

    using T::operator();
};

struct MyType
{
};

class FuncClass
{
public:
    void operator()(const std::string& str) const
    {
        std::cout << str << std::endl;
    }
}; 

int main( int argc, char **argv )
{
    std::cout << '\n';

    auto TypeOfIntegral = Overload {
        [](int) { return "  int"; },
        [](unsigned int) { return " unsigned int"; },
        [](long int) { return " long int"; },
        [](long long int) { return "long long int"; },
        [](auto) { return "unknown type"; },
    };

    std::cout << "TypeOfIntegral(5): " << TypeOfIntegral(5) << '\n';
    std::cout << "TypeOfIntegral(5u): " << TypeOfIntegral(5u) << '\n';
    std::cout << "TypeOfIntegral(5U): " << TypeOfIntegral(5U) << '\n';
    std::cout << "TypeOfIntegral(5l): " << TypeOfIntegral(5l) << '\n';
    std::cout << "TypeOfIntegral(5L): " << TypeOfIntegral(5L) << '\n';
    std::cout << "TypeOfIntegral(5ll): " << TypeOfIntegral(5ll) << '\n';
    std::cout << "TypeOfIntegral(5LL): " << TypeOfIntegral(5LL) << '\n';

    std::cout << '\n';

    std::cout << "TypeOfIntegral(5ul): " << TypeOfIntegral(5ul) << '\n';
    std::cout << "TypeOfIntegral(5.5): " << TypeOfIntegral(5.5) << '\n';

    std::cout << '\n'; 
    MyOverload<FuncClass> a{};

    FuncClass myFuncClass; 
    myFuncClass("hello world");

    a("haha");

    //MyOverload{ [](const std::string& str) {
    //    std::cout << str << std::endl;
    //    }
    //};

    auto bar = std::make_tuple ("test", 3.1, 14, 'y');

    return 0;
}
