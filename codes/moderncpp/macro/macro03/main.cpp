#include <iostream>

void(bar)()
{
    std::cout << "bar() " << std::endl;
}

void (foo)()
{
    std::cout << "(foo)() " << std::endl;
}

int main ( int argc, char **argv )
{
    {
       foo();
       (foo)();
       bar();
       (bar)();
    }

    return 0;
}
