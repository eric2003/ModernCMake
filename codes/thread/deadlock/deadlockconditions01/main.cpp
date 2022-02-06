#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;
 
void ThreadA()
{
    // Creates deadlock problem
    mtx1.lock();
    std::cout << "Thread A" << std::endl;
    mtx1.lock();
    mtx2.unlock();
    mtx1.unlock();
}
 
void ThreadB()
{
    // Creates deadlock problem
    mtx1.lock();
    std::cout << "Thread B" << std::endl;
    mtx2.lock();
    mtx1.unlock();
    mtx2.unlock();
}

int main ( int argc, char **argv )
{
    std::thread th1( ThreadA );
    std::thread th2( ThreadB );
 
    th1.join();
    th2.join();
 
    std::cout << "Finished" << std::endl;
    return 0;
}