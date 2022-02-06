#include <iostream>
#include <string>
#include <thread>
#include <vector>

int main( int argc, char **argv )
{
    const int nSize = 1000;
    std::vector<int> myarray;
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
