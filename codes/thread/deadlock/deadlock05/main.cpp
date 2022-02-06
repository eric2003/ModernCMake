#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int main ( int argc, char **argv )
{
    const int nSize = 5;
    std::mutex mtx1, mtx2;

    std::thread th1([&] {
        for ( int i = 0; i < nSize; ++ i )
        {
            std::cout << "th1 single step begin i = " << i << std::endl;
            std::cout << "th1 std::scoped_lock grd(mtx1, mtx2)\n";
            std::scoped_lock grd(mtx1, mtx2);

            std::cout << "th1 single step end\n";
        }
    });
    std::thread th2([&] {
        for (int i = 0; i < nSize; ++ i )
        {
            std::cout << "th2 single step begin i = " << i << std::endl;
            std::cout << "th2 std::scoped_lock grd(mtx2, mtx1)\n";
            std::scoped_lock grd(mtx2, mtx1);
            std::cout << "th2 single step end\n";
        }
    });

    th1.join();
    th2.join();
    return 0;
}