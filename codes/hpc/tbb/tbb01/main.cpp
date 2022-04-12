#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>
#include <chrono>

constexpr size_t n = 1<<27;
std::vector<float> vec(n);

static void BM_Sin(benchmark::State& state)
{
    for ( auto _ : state )
    {
        for ( size_t i = 0; i < vec.size(); ++ i )
        {
            vec[i] = std::sin(i);
        }
    }
}

static void BM_Res(benchmark::State& state)
{
    for ( auto _ : state )
    {
        float res = 0;
        for ( size_t i = 0; i < vec.size(); ++ i )
        {
            res += vec[i];
        }
        benchmark::DoNotOptimize(res);
    }
}

int main(int argc, char** argv)
{
    benchmark::RegisterBenchmark("BM_Sin", &BM_Sin);
    benchmark::RegisterBenchmark("BM_Res", &BM_Res);
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
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
        std::cout << "high_resolution_clock sin time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(t21).count()
             << " nanoseconds" << std::endl;

        t1 = Clock::now();
        float res = 0;
        for ( size_t i = 0; i < vec.size(); ++ i )
        {
            res += vec[i];
        }
        t2 = Clock::now();
        t21 = t2 - t1;
        std::cout << "res = " << res << std::endl;
        std::cout << "high_resolution_clock res time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(t21).count()
             << " nanoseconds" << std::endl;

    }
    return 0;
}
