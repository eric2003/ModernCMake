#include <iostream>
#include <tbb/tbb.h>

int main( int argc, char **argv )
{ 
    tbb::parallel_invoke(
        []() { std::cout << " Hello " << std::endl; },
        []() { std::cout << " TBB! " << std::endl; }
    );
    return 0;
}

