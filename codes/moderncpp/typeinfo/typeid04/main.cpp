#include <iostream>
#include <typeinfo>

template<typename T> 
void f(const T& param) 
{
#if defined(__GNUC__) //GNU 
    std::cout << __PRETTY_FUNCTION__ << std::endl; // Clang 
#elif defined(_MSC_VER) 
    std::cout << __FUNCSIG__ << std::endl; //Microsoft 
#endif 
}

int main( int argc, char **argv )
{
    int i;
    int * pi;
    std::cout << "int is: " << typeid(int).name() << '\n';
    std::cout << "  i is: " << typeid(i).name() << '\n';
    std::cout << " pi is: " << typeid(pi).name() << '\n';
    std::cout << "*pi is: " << typeid(*pi).name() << '\n';
    f(i);
    f(pi);
    f(*pi);

    return 0;
}

