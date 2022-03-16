#include <string>
#include <iostream>
 
void operator"" _CFD ( const char* str, size_t )
{
    std::cout << "Hello " << str << " User-defined CFD literals! " << std::endl;
}
 
int main( int argc, char **argv )
{
    "OneFLOW"_CFD;

    return 0;
}
