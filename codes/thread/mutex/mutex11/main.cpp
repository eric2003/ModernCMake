#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int main ( int argc, char **argv )
{
    std::mutex mtx;
    std::thread th1([&] {
        std::cout << "th1 function start....\n";
        std::unique_lock grd(mtx, std::defer_lock);
        std::cout << "th1 function lock_guard start....\n";
        std::lock_guard grd2(grd);
        std::cout << "th1 owns the lock\n";
        std::cout << "th1 begin sleep.....\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << "th1 end sleep.....\n";
    });

    std::thread th2([&] {
        std::cout << "th2 function start....\n";
        std::unique_lock grd(mtx, std::defer_lock);
        std::cout << "th2 function lock_guard start....\n";
        std::lock_guard grd2(grd);
        std::cout << "th2 owns the lock\n";
        std::cout << "th2 begin sleep.....\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "th2 end sleep.....\n";
    });

    th1.join();
    th2.join();
    return 0;
}
