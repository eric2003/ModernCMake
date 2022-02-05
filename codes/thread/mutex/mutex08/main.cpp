#include <iostream>       // std::cout
#include <chrono>         // std::chrono::milliseconds
#include <thread>         // std::thread
#include <mutex>          // std::timed_mutex

std::timed_mutex mtx;

void my_try_lock_function ( int i ) {
    if ( mtx.try_lock_for( std::chrono::milliseconds(500) ) )
    {
        std::cout << "try_lock_for thread " << i << " succeed! " << std::endl;
    }
    else
    {
        std::cout << "try_lock_for thread " << i << " failed! " << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    mtx.unlock();
}


int main( int argc, char **argv )
{
    std::thread threads[2];
    for ( int i = 0; i < 2; ++ i )
    {
        threads[i] = std::thread( my_try_lock_function, i );
    }
    
    for (auto& th : threads) th.join();

    return 0;
}
