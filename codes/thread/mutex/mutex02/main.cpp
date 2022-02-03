#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

int main( int argc, char **argv )
{
    const int nSize = 1000;
    std::vector<int> myarray;
    std::mutex mtx;
    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            mtx.lock();
            myarray.push_back( 0 );
            mtx.unlock();
        }
    });
    std::thread th2([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            mtx.lock();
            myarray.push_back( 1 );
            mtx.unlock();
        }
    });
    th1.join();
    th2.join();
    std::cout << "myarray.size() = " << myarray.size() << std::endl;
    return 0;
}
