#include <iostream>
#include <mutex>

int main( int argc, char **argv )
{
    std::mutex mtx;
    if ( mtx.try_lock() )
    {
        std::cout << "try_lock 0 succeed! " << std::endl;
    }
    else
    {
        std::cout << "try_lock 0 failed! " << std::endl;
    }

    if ( mtx.try_lock() )
    {
        std::cout << "try_lock 1 succeed! " << std::endl;
    }
    else
    {
        std::cout << "try_lock 1 failed! " << std::endl;
    }

    mtx.unlock();

    return 0;
}
