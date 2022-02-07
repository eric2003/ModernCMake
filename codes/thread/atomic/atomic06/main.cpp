#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

int main( int argc, char **argv )
{
    const int nSize = 10000;
    std::vector<int> data(2*nSize);
    std::atomic<int> sum;
    sum.store(0);

    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i ) {
            int index = sum.fetch_add(1);
            data[index] = i;
        }
    });

    std::thread th2([&] {
        for ( int i = 0; i < nSize; ++ i ) {
            int index = sum.fetch_add(1);
            data[index] = i;
        }
    });

    th1.join();
    th2.join();

    std::cout << " sum = " << sum.load() << std::endl;
    std::cout << "data[9999] = " << data[9999] << std::endl;

    return 0;
}

