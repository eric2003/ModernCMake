#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex mtx;

void bar()
{
    std::cout << "bar begin \n";
    std::cout << "bar mtx.lock()\n";
    mtx.lock();
    std::cout << "bar mtx.unlock()\n";
    mtx.unlock();
    std::cout << "bar end \n";
}
 
void foo()
{
    std::cout << "foo begin \n";
    std::cout << "foo mtx.lock()\n";
    mtx.lock();
    std::cout << "foo call bar\n";
    bar();
    std::cout << "foo mtx.unlock()\n";
    mtx.unlock();
    std::cout << "foo end \n";
}

int main ( int argc, char **argv )
{
    foo();
    return 0;
}