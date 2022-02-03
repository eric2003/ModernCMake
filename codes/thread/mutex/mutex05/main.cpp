#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

int main( int argc, char **argv )
{
    const int nSize = 100;
    std::vector<int> myarray;
    std::mutex mtx;
    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            std::unique_lock grd(mtx);
            myarray.push_back( 0 );
        }
    });
    std::thread th2([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            std::unique_lock grd(mtx, std::defer_lock);
            std::cout << "before the lock in th2 loop " << " i = " << i << std::endl;
            grd.lock();
            myarray.push_back( 1 );
            grd.unlock();
            std::cout << "outside of lock in th2 loop " << " i = " << i << std::endl;
        }
    });
    th1.join();
    th2.join();
    std::cout << "myarray.size() = " << myarray.size() << std::endl;
    return 0;
}
