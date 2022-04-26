#include <omp.h>
#include <benchmark/benchmark.h>
#include <iostream>
#include <vector>

// L1: 32KB
// L2: 256KB
// L3: 12MB

constexpr size_t n = 1<<28;

std::vector<float> a(n);

void BM_original(benchmark::State &state) {
    for (auto _: state) {
#pragma omp parallel for
        for ( size_t i = 0; i < n; ++ i ) {
            a[i] = a[i] * 2;
        }
#pragma omp parallel for
        for ( size_t i = 0; i < n; ++ i ) {
            a[i] = a[i] + 1;
        }
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_original);

void BM_optimized(benchmark::State &state) {
    for (auto _: state) {
#pragma omp parallel for
        for ( size_t i = 0; i < n; ++ i ) {
            a[i] = a[i] * 2;
            a[i] = a[i] + 1;
        }
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_optimized);

BENCHMARK_MAIN();
