#include <omp.h>
#include <benchmark/benchmark.h>
#include <iostream>

constexpr size_t n = 1<<28;

std::vector<float> a(n);  // 1GB

void BM_parallel_add(benchmark::State &bm) {
    for (auto _: bm) {
#pragma omp parallel for
        for ( size_t i = 0; i < n; ++ i ) {
            a[i] = a[i] + 1;
        }
        benchmark::DoNotOptimize(a);
    }
}
BENCHMARK(BM_parallel_add);

BENCHMARK_MAIN();
