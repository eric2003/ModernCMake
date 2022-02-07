#include <iostream>
#include <atomic>

int main( int argc, char **argv )
{
    std::atomic<int> sum;

    sum.store(1024);

    int old = sum.exchange(2022);
    std::cout << "old=" << old << std::endl;

    int now = sum.load();
    std::cout << "cnt=" << now << std::endl;

    return 0;
}

