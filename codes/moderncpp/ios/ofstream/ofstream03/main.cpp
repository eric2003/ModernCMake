#include <iostream>
#include <fstream>

void print_state (const std::ios& stream) {
    std::cout << " good()=" << stream.good();
    std::cout << " eof()=" << stream.eof();
    std::cout << " fail()=" << stream.fail();
    std::cout << " bad()=" << stream.bad();
}

int main( int argc, char **argv )
{
    {
        std::ofstream file ("test.txt");

        print_state( file );

        file << "hello world!";
       
        file.close();
    }

    return 0;
}
