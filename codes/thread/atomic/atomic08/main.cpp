#include <iostream>
#include <atomic>

int main( int argc, char **argv )
{
    std::cout << std::boolalpha;
    std::atomic<int> sum;

    sum.store(2);

    int v1 = 1;
    bool return_flag = sum.compare_exchange_strong(v1, 3);
    std::cout << "return_flag=" << return_flag << std::endl;
    std::cout << "v1=" << v1 << std::endl;

    int v2 = sum.load();
    std::cout << "v2=" << v2 << std::endl;

    v1 = 2;
    return_flag = sum.compare_exchange_strong(v1, 3);
    std::cout << "return_flag=" << return_flag << std::endl;
    std::cout << "v1=" << v1 << std::endl;

    v2 = sum.load();
    std::cout << "v2=" << v2 << std::endl; 

    return 0;
}