#include <iostream>

template <typename T>
class Add{
    private:
        T first;
        T second;
    public:
        Add() = default;
        Add(T v1, T v2): first{v1}, second{v2} {}
        T result() const {return first + second;}
};

//Add(const char*, const char*) -> Add<std::string>;

int main( int argc, char **argv )
{
    Add<int> addv0(1,2);
    Add addv1(1,2);          //T deduced as int
    Add addv2{1.1, 2.2};     //T deduced as double
    Add addv3 = {0.1f, 0.2f}; //T deduced as float
    Add<std::string> hellov0("Hello"," World");
    Add hellov1("Hello"," World");

    std::cout << "addv0.result() = " << addv0.result() << std::endl;
    std::cout << "addv1.result() = " << addv1.result() << std::endl;
    std::cout << "addv2.result() = " << addv2.result() << std::endl;
    std::cout << "addv3.result() = " << addv3.result() << std::endl;
    std::cout << "hellov0.result() = " << hellov0.result() << std::endl;
    std::cout << "hellov1.result() = " << hellov1.result() << std::endl;
    return 0;
}
