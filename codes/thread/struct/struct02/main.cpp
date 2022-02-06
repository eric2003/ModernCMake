#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class MutexVector
{
    std::vector<int> data;
    std::mutex mtx;
public:
    void push_back( int val )
    {
        mtx.lock();
        data.push_back(val);
        mtx.unlock();
    }

    size_t size() const
    {
        mtx.lock();
        size_t dataSize = data.size();
        mtx.unlock();
        return dataSize;
    }
};

int main( int argc, char **argv )
{
    const int nSize = 1000;
    MutexVector myarray;
    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            myarray.push_back( 0 );
        }
    });
    std::thread th2([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            myarray.push_back( 1 );
        }
    });
    th1.join();
    th2.join();
    std::cout << "myarray.size() = " << myarray.size() << std::endl;
    return 0;
}
