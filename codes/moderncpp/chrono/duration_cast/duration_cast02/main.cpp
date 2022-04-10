#include <iostream>
#include <chrono>

int main ( int argc, char **argv )
{
    {
        typedef std::chrono::steady_clock Clock;
        Clock::time_point clock_begin = Clock::now();
        
        std::cout << "printing out 1000 stars...\n";
        for (int i=0; i<1000; ++i) std::cout << "*";
        std::cout << std::endl;
        
        Clock::time_point clock_end = Clock::now();
        
        Clock::duration time_span = clock_end - clock_begin;
        
        double nseconds = double(time_span.count()) * Clock::period::num / Clock::period::den;
        
        std::cout << "It took me " << nseconds << " seconds.";
        std::cout << std::endl;
    }
    {
        using Clock = std::chrono::steady_clock;
        Clock::time_point clock_begin = Clock::now();
        
        std::cout << "printing out 1000 stars...\n";
        for (int i=0; i<1000; ++i) std::cout << "*";
        std::cout << std::endl;
        
        Clock::time_point clock_end = Clock::now();
        
        Clock::duration time_span = clock_end - clock_begin;
        
        double nseconds = double(time_span.count()) * Clock::period::num / Clock::period::den;
        
        std::cout << "It took me " << nseconds << " seconds.";
        std::cout << std::endl;
    }

    return 0;
}
