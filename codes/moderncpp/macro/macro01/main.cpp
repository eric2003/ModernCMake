#include <iostream>

#define foo(x) bar(x)

void bar(int var)
{
    std::cout << "bar var = " << var << std::endl;
    std::cout << "bar(int var) = " << - std::abs(var) << std::endl;
}

// parentheses avoid substitution by the macro
void (foo)(int var)
{
    std::cout << "(foo) var = " << var << std::endl;
    std::cout << "(foo)(int var) = " << std::abs(var) << std::endl;
}

int main ( int argc, char **argv )
{
    {
       // uses the macro
       foo(1);

       // uses the function
       (foo)(1);
    }

    return 0;
}
