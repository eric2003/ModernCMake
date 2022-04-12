#include <iostream>
#define foo() bar()

float(bar)()
{
    //std::cout << float(bar) " << std::endl;
    return 1.0;
}

float(foo)()
{
    //std::cout << "(foo)() " << std::endl;
    return 2.0;
}

int main ( int argc, char **argv )
{
    {
       float f1 = bar();
       float f2 = (bar)();
       std::cout << "f1 = " << f1 << std::endl;
       std::cout << "f2 = " << f2 << std::endl;
       float g1 = foo();
       float g2 = (foo)();
       std::cout << "g1 = " << g1 << std::endl;
       std::cout << "g2 = " << g2 << std::endl;
    }

    return 0;
}
