#include <string>
#include <iostream>

int main ( int argc, char **argv )
{
    {
        if ( argc > 1 )
        {
            int i = std::stoi( argv[1] );
            std::cout <<  " i = " << i << std::endl;
        }
    }

    return 0;
}
