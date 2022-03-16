#include <iostream>
#include <type_traits>

int main( int argc, char **argv )
{
    typedef int&& rval_int;
    typedef std::remove_reference<int>::type A;
    typedef std::remove_reference<int&>::type B;
    typedef std::remove_reference<int&&>::type C;
    typedef std::remove_reference<rval_int>::type D;
    
    std::cout << std::boolalpha;
    std::cout << "typedefs of int:" << std::endl;
    std::cout << "A: " << std::is_same<int,A>::value << std::endl;
    std::cout << "B: " << std::is_same<int,B>::value << std::endl;
    std::cout << "C: " << std::is_same<int,C>::value << std::endl;
    std::cout << "D: " << std::is_same<int,D>::value << std::endl;

    return 0;
}
