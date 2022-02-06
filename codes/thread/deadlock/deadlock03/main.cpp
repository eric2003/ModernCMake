#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int main ( int argc, char **argv )
{
    const int nSize = 5;
    std::mutex mtx1, mtx2;

    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            std::cout << "th1 single step begin i = " << i << std::endl;
            std::cout << "th1 mtx1.lock() " << std::endl;
            mtx1.lock();
            std::cout << "th1 mtx2.lock() " << std::endl;
            mtx2.lock();
            std::cout << "th1 mtx2.unlock() " << std::endl;
            mtx2.unlock();
            std::cout << "th1 mtx1.unlock() " << std::endl;
            mtx1.unlock();
            std::cout << "th1 single step end " << std::endl;
        }
    });
    std::thread th2([&] {
        for (int i = 0; i < nSize; ++ i )
        {
            std::cout << "th2 single step begin i = " << i << std::endl;
            std::cout << "th2 mtx1.lock() " << std::endl;
            mtx1.lock();
            std::cout << "th2 mtx2.lock() " << std::endl;
            mtx2.lock();
            std::cout << "th2 mtx2.unlock() " << std::endl;
            mtx2.unlock();
            std::cout << "th2 mtx1.unlock() " << std::endl;
            mtx1.unlock();
            std::cout << "th2 single step end " << std::endl;
        }
    });

    th1.join();
    th2.join();
    return 0;
}