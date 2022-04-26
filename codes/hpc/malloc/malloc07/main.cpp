#include <omp.h>
#include <benchmark/benchmark.h>
#include <iostream>
#include <vector>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
#define TIME_BEGIN(x) auto clock_time_##x = Clock::now();
#define TIME_END(x) { auto curr_time = Clock::now(); \
                      auto dt = curr_time - clock_time_##x; \
    std::cout << #x ": " \
	<< std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count() << " ns " \
	<< std::chrono::duration_cast<std::chrono::microseconds>(dt).count() << " micros " \
	<< std::chrono::duration_cast<std::chrono::milliseconds>(dt).count() << " ms " \
    << std::endl; }

constexpr size_t n = 1ull<<32;  // 16GB

template <class T>
struct NoInit {
    T value;

    NoInit() { /* do nothing */ }
};

int main(int argc, char** argv)
{
    std::vector< NoInit<int> > arr(n);

    TIME_BEGIN(write_first);
    for ( size_t i = 0; i < 1024; ++ i )
	{
        arr[i].value = 1;
    }
    TIME_END(write_first);


    return 0;
}