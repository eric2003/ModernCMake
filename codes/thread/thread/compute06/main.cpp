#include <iostream>
#include <thread>
#include <string>

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
    std::cout << "The CFL number is " << cfl << std::endl;
}

 std::thread th;

void wrapfun()
{
    std::thread t1( [&] { compute(10); } );
    th = std::move( t1 );
}

int main()
{
    wrapfun();
    std::this_thread::sleep_for( std::chrono::milliseconds(1500) );
    gui( 1.2 );
	th.join();
    return 0;
}