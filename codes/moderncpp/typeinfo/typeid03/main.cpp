#include <iostream>
#include <typeinfo>

int main( int argc, char **argv )
{
    int i;
    int * pi;
    std::cout << "int is: " << typeid(int).name() << '\n';
    std::cout << "  i is: " << typeid(i).name() << '\n';
    std::cout << " pi is: " << typeid(pi).name() << '\n';
    std::cout << "*pi is: " << typeid(*pi).name() << '\n';
    
    return 0;
}

