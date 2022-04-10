#include <iostream>
#include <chrono>

#define Print(x) \
    { \
        using Period = std::chrono::##x::period; \
        std::cout << #x << ": " << Period::num << " " << Period::den << std::endl; \
    }

int main ( int argc, char **argv )
{
    {
        Print(nanoseconds);
        Print(microseconds);
        Print(milliseconds);
        Print(seconds);
        Print(minutes);
        Print(hours);
        Print(days);
        Print(weeks);
        Print(months);
        Print(years);
    }

    return 0;
}
