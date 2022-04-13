#include <iostream>

int main ( int argc, char **argv )
{
    {
        if ( argc > 1 )
        {
            long i = strtol( argv[1], NULL, 0 );
            std::cout <<  " i = " << i << std::endl;
        }
    }

    return 0;
}
