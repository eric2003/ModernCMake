#include <iostream>
#include <thread>

int main( int argc, char **argv )
{
    int sum = 0;
    const int nSize = 10000;

    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i ) {
            sum += 1;
        }
    });

    std::thread th2([&] {
        for ( int i = 0; i < nSize; ++ i ) {
            sum += 1;
        }
    });

    th1.join();
    th2.join();

    std::cout << " sum = " << sum << std::endl;

    return 0;
}

