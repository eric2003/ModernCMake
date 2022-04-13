#include <omp.h>
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char** argv)
{
    {
        double start = omp_get_wtime();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        double end = omp_get_wtime();
        double wtick = omp_get_wtick();
        int width = 6;
        std::cout << std::fixed << std::setprecision(width);
        std::cout << "start = " << start << std::endl;
        std::cout << "end   = " << end << std::endl;
        std::cout << "diff  = " << end - start << std::endl;
        std::cout.unsetf( std::cout.flags() );
        std::cout << "wtick = " << wtick << std::endl;
        std::cout << "1.0/wtick = " << 1.0/wtick << std::endl;
    }

    return 0;
}