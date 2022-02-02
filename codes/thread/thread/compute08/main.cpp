#include <iostream>
#include <thread>
#include <string>
#include <vector>

class ThreadPool
{
private:
    std::vector<std::thread> pool;
public:
    void push_back(std::thread th)
    {
        pool.push_back(std::move(th));
    }

    ~ThreadPool()
    {
        for ( auto &th: this->pool )
        {
            th.join();
        }
    }
};

ThreadPool th_pool;

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

void wrapfun()
{
    std::thread th( [&] { compute(10); } );
    th_pool.push_back( std::move(th) );
}

int main()
{
    wrapfun();
    std::this_thread::sleep_for( std::chrono::milliseconds(1500) );
    gui( 1.2 );
    return 0;
}