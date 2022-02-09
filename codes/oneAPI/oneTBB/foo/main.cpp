#include <iostream>
#include <thread>
#include <string>
#include <tbb/task_group.h>

void compute( int nIters )
{
    for ( int iter = 0; iter < nIters; ++ iter )
    {
        std::cout << " iter = " << iter + 1 << " nIters = " << nIters << std::endl;		
        std::this_thread::sleep_for( std::chrono::milliseconds(500) );
    }
    std::cout << "The computation is finished! "  << std::endl;
}

void gui( double cfl )
{
    std::this_thread::sleep_for( std::chrono::milliseconds(1500) );
    std::cout << "The CFL number is " << cfl << std::endl;
}

int main( int argc, char **argv )
{
    tbb::task_group tg;
    tg.run([&] {
        compute(10);
    });
    tg.run([&] {
        gui(1.2);
    });
    tg.wait();

    return 0;
}

