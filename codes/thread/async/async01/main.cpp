#include <iostream>
#include <thread>
#include <string>
#include <future>

int compute( int nIters )
{
    for ( int iter = 0; iter < nIters; ++ iter )
    {
        std::cout << " iter = " << iter + 1 << " nIters = " << nIters << std::endl;		
        std::this_thread::sleep_for( std::chrono::milliseconds(500) );
    }
    std::cout << "The computation is finished! "  << std::endl;
    return 123;
}

void gui( double cfl )
{
    std::cout << "The CFL number is " << cfl << std::endl;
}

int main()
{
    std::future<int> fret = std::async([&] { return compute(10); } );
    std::this_thread::sleep_for( std::chrono::milliseconds(1500) );
    gui( 1.2 );
    int ret = fret.get();
    std::cout << "computation result: " << ret << std::endl;
    return 0;
}