#include <iostream>
#include <omp.h>
#include <windows.h>

int main(int argc, char** argv)
{
    {
        double start = omp_get_wtime( );
        Sleep(1000);
        double end = omp_get_wtime( );
        double wtick = omp_get_wtick( );

        std::cout << "start = " << start << std::endl;
        std::cout << "end = " << end << std::endl;
        std::cout << "diff = " << end - start << std::endl;
        std::cout << "wtick = " << wtick << std::endl;
        std::cout << "1.0/wtick = " << 1.0/wtick << std::endl;
    }

    return 0;
}