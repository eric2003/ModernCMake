#include <iostream>
#include <thread>
#include <vector>
#include <shared_mutex>

class MutexVector
{
public:
    void push_back( int val )
    {
        std::unique_lock grd(mtx);
        data.push_back(val);
    }

    size_t size() const
    {
        std::shared_lock grd(mtx);
        return data.size();
    }
private:
    std::vector<int> data;
    mutable std::shared_mutex mtx;
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
