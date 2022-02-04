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
    std::promise<int> pret;
    std::thread t1([&] {
        auto ret = compute(10);
        pret.set_value(ret); 
    });

    std::this_thread::sleep_for( std::chrono::milliseconds(1500) );
    std::future<int> fret = pret.get_future();
    gui( 1.2 );

    int ret = fret.get();
    std::cout << "computation result: " << ret << std::endl;
    t1.join();
    return 0;
}