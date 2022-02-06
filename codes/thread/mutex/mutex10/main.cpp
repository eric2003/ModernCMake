#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int main ( int argc, char **argv )
{
    std::mutex mtx;
    std::thread th1([&] {
        std::cout << "th1 function start....\n";
        std::unique_lock grd(mtx);
        if ( grd.owns_lock() )
        {
            std::cout << "th1 owns the lock\n";
        }
        else
        {
            std::cout << "th1 not owns the lock\n";
        }
        std::cout << "th1 begin sleep.....\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << "th1 end sleep.....\n";
    });

    std::thread th2([&] {
        std::cout << "th2 function start....\n";
        std::cout << "th2 function begin lock....\n";
        mtx.lock();
        std::cout << "th2 function end lock....\n";
        std::cout << "th2 function begin std::adopt_lock....\n";
        std::unique_lock grd(mtx, std::adopt_lock);
        std::cout << "th2 function end std::adopt_lock....\n";
        if ( grd.owns_lock() )
        {
            std::cout << "th2 owns the lock\n";
        }
        else
        {
            std::cout << "th2 not owns the lock\n";
        }
        std::cout << "th2 begin sleep.....\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "th2 end sleep.....\n";
    });

    th1.join();
    th2.join();
    return 0;
}


