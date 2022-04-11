#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>
#include <chrono>


auto BM_test = [](benchmark::State& state, auto Inputs)
{
  for (auto _ : state) {
    benchmark::DoNotOptimize(state.iterations());
  }
    //std::cout << "Inputs = " << Inputs << std::endl;
};


int main(int argc, char** argv)
{
    //benchmark::RegisterBenchmark("BM_test", BM_test, 10);
    //benchmark::Initialize(&argc, argv);
    //benchmark::RunSpecifiedBenchmarks();
    //benchmark::Shutdown();
    {
        size_t n = 1<<27;
        std::vector<float> vec(n);
        typedef std::chrono::high_resolution_clock Clock;
        auto t1 = Clock::now();

        for ( size_t i = 0; i < vec.size(); ++ i )
        {
            vec[i] = std::sin(i);
        }

        auto t2 = Clock::now();
        std::chrono::nanoseconds t21 = t2 - t1;
        std::cout << "high_resolution_clock time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(t21).count()
             << " nanoseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::microseconds>(t21).count()
             << " microseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::milliseconds>(t21).count()
             << " milliseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::seconds>(t21).count()
             << " seconds" << std::endl;
    }
    {
        size_t n = 1<<27;
        std::vector<float> vec(n);
        typedef std::chrono::steady_clock Clock;
        auto t1 = Clock::now();

        for ( size_t i = 0; i < vec.size(); ++ i )
        {
            vec[i] = std::sin(i);
        }

        auto t2 = Clock::now();
        std::chrono::nanoseconds t21 = t2 - t1;
        std::cout << "steady_clock time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(t21).count()
             << " nanoseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::microseconds>(t21).count()
             << " microseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::milliseconds>(t21).count()
             << " milliseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::seconds>(t21).count()
             << " seconds" << std::endl;

    }
    {
        size_t n = 1<<27;
        std::vector<float> vec(n);
        typedef std::chrono::system_clock Clock;
        auto t1 = Clock::now();

        for ( size_t i = 0; i < vec.size(); ++ i )
        {
            vec[i] = std::sin(i);
        }

        auto t2 = Clock::now();
        std::chrono::nanoseconds t21 = t2 - t1;
        std::cout << "system_clock time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(t21).count()
             << " nanoseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::microseconds>(t21).count()
             << " microseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::milliseconds>(t21).count()
             << " milliseconds" << std::endl;
        std::cout << "time taken: "
             << std::chrono::duration_cast<std::chrono::seconds>(t21).count()
             << " seconds" << std::endl;
    }

    return 0;
}