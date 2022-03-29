// error state flags
#include <iostream>     // std::cout, std::ios
#include <sstream>      // std::stringstream

void print_state (const std::ios& stream) {
    std::cout << " good()=" << stream.good();
    std::cout << " eof()=" << stream.eof();
    std::cout << " fail()=" << stream.fail();
    std::cout << " bad()=" << stream.bad();
}

int main( int argc, char **argv )
{
    {
        std::stringstream stream;
        
        stream.clear (stream.goodbit);
        std::cout << "goodbit:"; print_state(stream); std::cout << '\n';
        
        stream.clear (stream.eofbit);
        std::cout << " eofbit:"; print_state(stream); std::cout << '\n';
        
        stream.clear (stream.failbit);
        std::cout << "failbit:"; print_state(stream); std::cout << '\n';
        
        stream.clear (stream.badbit);
        std::cout << " badbit:"; print_state(stream); std::cout << '\n';
    }

    return 0;
}
