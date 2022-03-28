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

void void_a()
{ 
    std::cout << "void_a" << std::endl;
    return;
}

void void_b()
{ 
    std::cout << "void_b" << std::endl;
    return;
}

void void_c()
{ 
    std::cout << "void_c" << std::endl;
    return;
}

int main( int argc, char **argv )
{
    {
        std::cout << "test1-------------------------" << std::endl;
        int dummy = -1;
        dummy = a() = b() = c();
        std::cout << "dummy = " << dummy << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "test2-------------------------" << std::endl;
        int dummy = -1;
        ( dummy = (void_a(), 1));
        std::cout << "dummy = " << dummy << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "test3-------------------------" << std::endl;
        int dummy = -1;
        (( dummy = (void_a(), 1) ) = (void_b(), 2));
        std::cout << "dummy = " << dummy << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "test4-------------------------" << std::endl;
        int dummy = -1;
        ((( dummy = (void_a(), 1) ) = (void_b(), 2)) = (void_c(), 3));
        std::cout << "dummy = " << dummy << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
