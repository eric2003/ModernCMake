#include <iostream>

void foo( int & )
{
    std::cout << "int &" << std::endl;
}

void foo( int const & )
{
    std::cout << "int const &" << std::endl;
}

void foo( int && )
{
    std::cout << "int &&" << std::endl;
}

int main( int argc, char **argv )
{
    int a = 0;
    const int b = 1;
    int *p = &a;
    foo(a);
    foo(*p);
    foo(p[a]);
    foo(1);
    foo(int{});
    foo(a+int{});
    foo(a+1);
    foo(*p+1);
    foo(b);
    foo(b+1);


    return 0;
}
