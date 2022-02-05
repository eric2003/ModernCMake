#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

int main( int argc, char **argv )
{
    const int nSize = 10;
    std::vector<int> myarray1, myarray2;
    std::mutex mtx1, mtx2;
    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            {
                std::lock_guard grd(mtx1);
                myarray1.push_back( 0 );
            }

            {
                std::lock_guard grd(mtx2);
                myarray2.push_back(0);
            }
        }
    });
    std::thread th2([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            {
                std::lock_guard grd(mtx1);
                myarray1.push_back( 1 );
            }

            {
                std::lock_guard grd(mtx2);
                myarray2.push_back(1);
            }
        }
    });
    th1.join();
    th2.join();
    std::cout << "myarray1.size() = " << myarray1.size() << std::endl;
    std::cout << "myarray2.size() = " << myarray2.size() << std::endl;
    return 0;
}
