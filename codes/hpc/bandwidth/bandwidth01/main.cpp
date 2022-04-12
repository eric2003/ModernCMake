#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>

constexpr size_t n = 1<<26;
std::vector<float> vec(n); // 256MB
typedef int MyInt;
static void BM_fill(benchmark::State &state) {
    for (auto _: state) {
        for ( size_t i = 0; i < n; ++ i ) {
            vec[i] = 1;
        }
    }
}
BENCHMARK(BM_fill);

static void BM_parallel_fill(benchmark::State &state) {
    for (auto _: state) {
#pragma omp parallel for
        for ( MyInt i = 0; i < n; ++ i )
        {
            vec[i] = 1;
        }
    }
}
BENCHMARK(BM_parallel_fill);

static void BM_sine(benchmark::State &state) {
    for (auto _: state) {
        for ( size_t i = 0; i < n; ++ i ) {
            vec[i] = std::sin(i);
        }
    }
}
BENCHMARK(BM_sine);

static void BM_parallel_sine(benchmark::State &state) {
    for (auto _: state) {
#pragma omp parallel for
        for ( MyInt i = 0; i < n; ++ i ) {
            vec[i] = std::sin(i);
        }
    }
}
BENCHMARK(BM_parallel_sine);

BENCHMARK_MAIN();
