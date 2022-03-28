#include <iostream>
static int i1 = 1;
static int i2 = 2;
static int i3 = 3;
int & a()
{ 
    std::cout << "a" << std::endl;
    return i1;
}

int & b()
{ 
    std::cout << "b" << std::endl;
    return i2;
}

int & c()
{ 
    std::cout << "c" << std::endl;
    return i3;
}

int main( int argc, char **argv )
{
    {
        int dummy = -1;
        dummy = a() = b() = c();
        std::cout << "dummy = " << dummy << std::endl;
    }

    return 0;
}
