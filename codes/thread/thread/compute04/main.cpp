#include <iostream>
#include <thread>
#include <string>

void compute( int nIters )
{
    for ( int iter = 0; iter < nIters; ++ iter )
    {
        std::this_thread::sleep_for( std::chrono::milliseconds(500) );
        std::cout << " iter = " << iter + 1 << " nIters = " << nIters << std::endl;
    }
    std::cout << "The computation is finished! "  << std::endl;
}

void gui( double cfl )
{
    std::cout << "The CFL number is " << cfl << std::endl;
}

void wrapfun()
{
    std::thread t1( [&] { compute(10); } );
}

int main()
{
    wrapfun();
    gui( 1.2 );
    return 0;
}