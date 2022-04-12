#include <vector>
#include <iostream>
#include <chrono>

int main(int argc, char** argv)
{
    {
        size_t n = 1<<2;
        std::vector<float> vec(n);
        typedef std::chrono::high_resolution_clock Clock;
        auto t1 = Clock::now();

        for ( size_t i = 0; i < vec.size(); ++ i )
        {
            vec[i] = std::sin(i);
        }

        auto t2 = Clock::now();
        std::chrono::nanoseconds dt = t2 - t1;
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();
        std::chrono::nanoseconds::rep ns1 = std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();

        std::cout << "high_resolution_clock time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count()
             << " nanoseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::microseconds>(dt).count()
             << " microseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::milliseconds>(dt).count()
             << " milliseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::seconds>(dt).count()
             << " seconds" << std::endl;
    }


    return 0;
}