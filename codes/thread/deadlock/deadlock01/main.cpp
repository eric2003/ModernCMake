#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int main ( int argc, char **argv )
{
    const int nSize = 100;
    std::mutex mtx1, mtx2;

    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            std::cout << "th1 i = " << i << std::endl;
            std::cout << "th1 step 1 " << std::endl;
            mtx1.lock();
            std::cout << "th1 step 2 " << std::endl;
            mtx2.lock();
            std::cout << "th1 step 3 " << std::endl;
            mtx2.unlock();
            std::cout << "th1 step 4 " << std::endl;
            mtx1.unlock();
            std::cout << "th1 step 5 " << std::endl;
        }
    });
    std::thread th2([&] {
        for (int i = 0; i < nSize; ++ i )
        {
            std::cout << "th2 i = " << i << std::endl;
            std::cout << "th2 step 1 " << std::endl;
            mtx2.lock();
            std::cout << "th2 step 2 " << std::endl;
            mtx1.lock();
            std::cout << "th2 step 3 " << std::endl;
            mtx1.unlock();
            std::cout << "th2 step 4 " << std::endl;
            mtx2.unlock();
            std::cout << "th2 step 5 " << std::endl;
        }
    });

    th1.join();
    th2.join();
    return 0;
}
