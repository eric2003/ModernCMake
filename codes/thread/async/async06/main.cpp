#include <iostream>
#include <thread>
#include <string>
#include <future>

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

int main()
{
    std::shared_future<void> fret = std::async([&] {
        compute(10); 
    });
    auto fret2 = fret;
    auto fret3 = fret;
    std::this_thread::sleep_for( std::chrono::milliseconds(1500) );
    gui( 1.2 );
    fret3.wait();
    std::cout << "computation finished " << std::endl;
    return 0;
}