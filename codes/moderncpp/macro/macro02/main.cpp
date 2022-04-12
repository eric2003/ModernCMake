#include <iostream>

#define foo() bar()

void bar()
{
    std::cout << "bar() " << std::endl;
}

// parentheses avoid substitution by the macro
void (foo)()
{
    std::cout << "(foo)() " << std::endl;
}

int main ( int argc, char **argv )
{
    {
       // uses the macro
       foo();

       // uses the function
       (foo)();
    }

    return 0;
}
