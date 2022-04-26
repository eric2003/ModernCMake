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

constexpr size_t n = 1<<29;

int main(int argc, char** argv)
{
    {
        TIME_BEGIN(first_alloc);
        std::vector<int> arr(n);
        TIME_END(first_alloc);
    }

    {
        TIME_BEGIN(second_alloc);
        std::vector<int> arr(n);
        TIME_END(second_alloc);
    }	

    return 0;
}