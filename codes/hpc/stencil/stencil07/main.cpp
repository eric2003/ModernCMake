#include <iostream>
#include "Image.h"
#include "rwimage.h"
#include "boxblur.h"
#include "gaussblur.h"
#include <chrono>
/*
typedef std::chrono::high_resolution_clock Clock;
#define TIME_BEGIN(x) auto clock_time_##x = Clock::now();
#define TIME_END(x) { auto curr_time = Clock::now(); \
                      auto dt = curr_time - clock_time_##x; \
    std::cout << #x ": " \
	<< std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count() << " ns " \
	<< std::chrono::duration_cast<std::chrono::microseconds>(dt).count() << " micros " \
	<< std::chrono::duration_cast<std::chrono::milliseconds>(dt).count() << " ms " \
    << std::endl; }
*/

typedef std::chrono::high_resolution_clock Clock;
#define TIME_BEGIN(x) auto clock_time_##x = Clock::now();
#define TIME_END(x) { auto curr_time = Clock::now(); \
                      auto dt = curr_time - clock_time_##x; \
    printf( #x ": " ); \
    }

int main(int argc, char** argv)
{
	printf("haha\n");    
	Image a;
	printf("haha1\n");    
    //TIME_BEGIN(read);
	printf("haha2\n");    
    read_image(a, "original.jpg");
	printf("haha3\n");    
    //TIME_END(read);
	printf("haha4\n");    

    //TIME_BEGIN(boxblur);
    //boxblur(a, 32, 32);
    //TIME_END(boxblur);
	

    printf("haha5\n");    
    //TIME_BEGIN(gaussblur);
    //gaussblur(a, 32, 12);
	printf("haha6\n");    
    //TIME_END(gaussblur);

    //TIME_BEGIN(write);
	printf("haha7\n");    
    write_image(a, "result.png");
    //TIME_END(write);
	printf("haha8\n");    
	
    return 0;
}