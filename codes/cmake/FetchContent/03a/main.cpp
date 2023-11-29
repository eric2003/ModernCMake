#include "foo.h"
#include <iostream>

int main( int argc, char ** argv )
{
    int c = AddInt(1, 2);
    std::cout << "c = "<< c << "\n";
    return 0;
}