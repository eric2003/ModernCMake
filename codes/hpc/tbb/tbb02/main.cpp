#include <benchmark/benchmark.h>
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
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
        auto t0 = Clock::now();
        tbb::parallel_for(tbb::blocked_range<size_t>(0, n),
        [&] (tbb::blocked_range<size_t> r) {
            for ( size_t i = r.begin(); i < r.end(); ++ i ) {
                vec[i] = std::sin(i);
            }
        });
        auto t1 = Clock::now();
        std::chrono::nanoseconds dt = t1 - t0;
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();
        std::chrono::nanoseconds::rep ns1 = std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();
        std::cout << "tbb::parallel_for time elapsed: " << ns << " nanoseconds" << std::endl;
        t0 = Clock::now();
        float res = tbb::parallel_reduce(tbb::blocked_range<size_t>(0, n), (float)0,
        [&] (tbb::blocked_range<size_t> r, float local_res) {
            for ( size_t i = r.begin(); i < r.end(); ++ i) {
                local_res += vec[i];
            }
            return local_res;
        }, [] (float x, float y) {
            return x + y;
        });
        t1 = Clock::now();
        dt = t1 - t0;
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();
        std::cout << "tbb::parallel_reduce time elapsed: " << ns << " nanoseconds" << std::endl;
    }
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
