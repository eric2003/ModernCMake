#include <iostream>
#include "Image.h"
#include "rwimage.h"
#include "boxblur.h"
#include "gaussblur.h"
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


int main(int argc, char** argv)
{
    Image a;
    TIME_BEGIN(read);
    read_image(a, "original.jpg");
    TIME_END(read);

    //TIME_BEGIN(boxblur);
    //boxblur(a, 32, 32);
    //TIME_END(boxblur);

    TIME_BEGIN(gaussblur);
    gaussblur(a, 32, 12);
    TIME_END(gaussblur);

    TIME_BEGIN(write);
    write_image(a, "result.png");
    TIME_END(write);
    return 0;
}