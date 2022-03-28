#include <iostream>
int a()
{ 
    std::cout << "a" << std::endl;
    return 1;
}
int b()
{ 
    std::cout << "b" << std::endl;
    return 2;
}

int c()
{ 
    std::cout << "c" << std::endl;
    return 3;
}

int main( int argc, char **argv )
{
    {
        std::cout << "test1" << std::endl;
        int v = a() + b() + c();
        std::cout << "v = " << v << std::endl;
    }
    {
        std::cout << "test2" << std::endl;
        int v = a(), b(), c();
        std::cout << "v = " << v << std::endl;
    }
    {
        std::cout << "test3" << std::endl;
        int v = ( a(), b(), c() );
        std::cout << "v = " << v << std::endl;
    }
    {
        std::cout << "test4" << std::endl;
        a(), b(), c();
    }
    {
        std::cout << "test5" << std::endl;
        int v = ( a(), b() ), c();
        std::cout << "v = " << v << std::endl;
    }
    {
        std::cout << "test6" << std::endl;
        std::cout << "First Line\n",
        std::cout << "Second Line\n",
        std::cout << "Third Line\n",
        std::cout << "Last line";
        std::cout << std::endl;
    }
    return 0;
}
