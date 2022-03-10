#include <iostream>
#include <stdexcept>

int compare( int a, int b ) {
    if ( a < 0 || b < 0 ) {
        throw std::invalid_argument( "received negative value" );
    }
    return a;
}

int main( int argc, char **argv )
{
    try {
        compare( -1, 3 );
    }
    catch( const std::invalid_argument& e ) {
        // do stuff with exception... 
        std::cout << "#1: " << e.what() << std::endl;
    }
    return 0;
}
