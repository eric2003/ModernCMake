#include <iostream>
#include <thread>
#include <atomic>

int main( int argc, char **argv )
{
    const int nSize = 10000;
    std::atomic<int> sum;
    sum.store(0);

    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i ) {
            sum.fetch_add(1);
        }
    });

    std::thread th2([&] {
        for ( int i = 0; i < nSize; ++ i ) {
            sum.fetch_add(1);
        }
    });

    th1.join();
    th2.join();

    std::cout << " sum = " << sum.load() << std::endl;

    return 0;
}

