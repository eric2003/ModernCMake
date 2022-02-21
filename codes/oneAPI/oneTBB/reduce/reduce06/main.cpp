#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

int main( int argc, char **argv )
{
    size_t n = 1 << 26;
    size_t n0 = 1 << 0;
    size_t n1 = 1 << 1;
    size_t n2 = 1 << 2;
    size_t n3 = 1 << 3;
    std::cout << " n = " << n << std::endl;
    std::cout << " n0 = " << n0 << std::endl;
    std::cout << " n1 = " << n1 << std::endl;
    std::cout << " n2 = " << n2 << std::endl;
    std::cout << " n3 = " << n3 << std::endl;

    std::vector<float> a(n);
    auto t0 = std::chrono::steady_clock::now();
    float sum = 0;	
    for ( size_t i = 0; i < n; ++ i )
    {
        sum += std::sin(i);
        a[i] = sum;
    }

    std::cout << "a["<< n / 2 << "] = " << a[n / 2] << std::endl;
    std::cout << " sum = " << sum << std::endl;

    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
    std::cout << "time elapsed: " << ms << " ms" << std::endl;

    return 0;
}

