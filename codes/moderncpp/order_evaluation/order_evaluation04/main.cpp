#include <iostream>
void a()
{ 
    std::cout << "a" << std::endl;
    return;
}
void b()
{ 
    std::cout << "b" << std::endl;
    return;
}

void c()
{ 
    std::cout << "c" << std::endl;
    return;
}

int main( int argc, char **argv )
{
    {
        int dummy = -1;
        dummy = (a(), 0);
        std::cout << "dummy = " << dummy << std::endl;
    }
    {
        //a(), b(), c();
        //int dummy;
        //(dummy = (a(), 0) = ((b), 0) = ((c), 0));
        //std::cout << "dummy = " << dummy << std::endl;
    }

    return 0;
}
