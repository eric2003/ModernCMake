#include <iostream>

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

class MyInt
{
public:
    MyInt( int i ) : data(i) {}
    ~MyInt() {}
    MyInt& operator = ( const MyInt& rhs )
    {
        std::cout << "MyInt operator const MyInt& = ";
        if ( this != &rhs )
        {
            this->data = rhs.data;
        }
        std::cout << this->data << std::endl;
        return *this;
    }
    MyInt& operator = ( const int& rhs )
    {
        std::cout << "MyInt operator const int& = ";
        this->data = rhs;
        std::cout << this->data << std::endl;
        return *this;
    }
public:
    int data;
};

int main( int argc, char **argv )
{
    {
        std::cout << "test1-------------------------" << std::endl;
        MyInt dummy = -1;
        std::cout << "initial dummy = " << dummy.data << std::endl;
        ((( dummy = (void_a(), 1) ) = (void_b(), 2)) = (void_c(), 3));
        std::cout << "final dummy = " << dummy.data << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
