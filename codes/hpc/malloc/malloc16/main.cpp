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

float func(int n) {
    std::vector<float> tmp;
    for (int i = 0; i < n; i++) {
        tmp.push_back(i / 15 * 2.71828f);
    }
    std::reverse(tmp.begin(), tmp.end());
    float ret = tmp[32];
    return ret;
}

int main(int argc, char** argv)
{
    {
        constexpr int n = 1<<25;
	    
        TIME_BEGIN(first_alloc);
        std::cout << func(n) << std::endl;
        TIME_END(first_alloc);
	    
        TIME_BEGIN(second_call);
        std::cout << func(n - 1) << std::endl;
        TIME_END(second_call);
    }

    return 0;
}
