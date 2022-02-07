#include <iostream>
#include <thread>
#include <mutex>

int main( int argc, char **argv )
{
    int sum = 0;
    const int nSize = 10000;
    std::mutex mtx;

    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i ) {
            mtx.lock();
            sum += 1;
            mtx.unlock();
        }
    });

    std::thread th2([&] {
        for ( int i = 0; i < nSize; ++ i ) {
            mtx.lock();
            sum += 1;
            mtx.unlock();
        }
    });

    th1.join();
    th2.join();

    std::cout << " sum = " << sum << std::endl;

    return 0;
}

