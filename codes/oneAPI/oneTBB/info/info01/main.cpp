#include <iostream>
#include <tbb/version.h>

int main( int argc, char **argv )
{
    std::cout << "Hello from oneTBB "
              << TBB_VERSION_MAJOR << "."
              << TBB_VERSION_MINOR << "."
              << TBB_VERSION_PATCH
              << "!" << std::endl;

    return 0;
}

